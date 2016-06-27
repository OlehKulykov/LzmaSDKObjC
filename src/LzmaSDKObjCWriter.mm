/*
 *   Copyright (c) 2015 - 2016 Kulykov Oleh <info@resident.name>
 *
 *   Permission is hereby granted, free of charge, to any person obtaining a copy
 *   of this software and associated documentation files (the "Software"), to deal
 *   in the Software without restriction, including without limitation the rights
 *   to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 *   copies of the Software, and to permit persons to whom the Software is
 *   furnished to do so, subject to the following conditions:
 *
 *   The above copyright notice and this permission notice shall be included in
 *   all copies or substantial portions of the Software.
 *
 *   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *   IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *   FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *   AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *   LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 *   OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 *   THE SOFTWARE.
 */


#import "LzmaSDKObjCWriter.h"
#include "LzmaSDKObjCFileEncoder.h"
#import "LzmaSDKObjCMutableItem+Private.h"
#import "LzmaSDKObjCItem+Private.h"

@interface LzmaSDKObjCWriter() {
@private
	LzmaSDKObjC::FileEncoder * _encoder;

	__strong NSURL * _fileURL;
	__strong NSMutableArray * _items;
}

@end

@implementation LzmaSDKObjCWriter

static wchar_t * _LzmaSDKObjCWriterWepGW(NSString * we) {
	//TODO: .........
	const size_t len = we ? [we length] : 0;
	if (len)
	{
		wchar_t * b = (wchar_t *)malloc(sizeof(wchar_t) * (len + 1));
		if (b)
		{
			const NSStringEncoding e = CFStringConvertEncodingToNSStringEncoding(kCFStringEncodingUTF32LE);
			NSData * d = [we dataUsingEncoding:e];
			const size_t ds = d ? [d length] : 0;
			if (ds)
			{
				memcpy(b, [d bytes], ds);
				b[len] = 0;
				return b;
			}
			free(b);
		}
	}
	return NULL;
}

static void * _LzmaSDKObjCWriterGetVoidCallback1(void * context) {
	LzmaSDKObjCWriter * w = (__bridge LzmaSDKObjCWriter *)context;
	if (w) return w->_passwordGetter ? _LzmaSDKObjCWriterWepGW(w->_passwordGetter()) : NULL;
	return NULL;
}

static void _LzmaSDKObjCWriterSetFloatCallback(void * context, float value) {
	LzmaSDKObjCWriter * w = (__bridge LzmaSDKObjCWriter *)context;
	if (w) {
		id<LzmaSDKObjCWriterDelegate> d = w.delegate;
		if (d && [d respondsToSelector:@selector(onLzmaSDKObjCWriter:writeProgress:)]) {
			if ([NSThread isMainThread]) [d onLzmaSDKObjCWriter:w writeProgress:value];
			else dispatch_async(dispatch_get_main_queue(), ^{ [d onLzmaSDKObjCWriter:w writeProgress:value]; });
		}
	}
}

- (NSError *) lastError {
	LzmaSDKObjC::Error * error = _encoder ? _encoder->lastError() : NULL;
	if (error) {
		return [NSError errorWithDomain:kLzmaSDKObjCErrorDomain
								   code:(NSInteger)error->code
							   userInfo:@{ NSLocalizedDescriptionKey : [NSString stringWithUTF8String:error->description.Ptr() ? error->description.Ptr() : ""],
										   NSFilePathErrorKey : [NSString stringWithUTF8String:error->file.Ptr() ? error->file.Ptr() : ""],
										   @"line" : [NSNumber numberWithInt:error->line],
										   @"code" : [NSNumber numberWithLongLong:error->code],
										   NSLocalizedFailureReasonErrorKey : [NSString stringWithUTF8String:error->possibleReason.Ptr() ? error->possibleReason.Ptr() : ""]}];
	}
	return nil;
}

- (NSURL *) fileURL {
	return _fileURL;
}

- (nonnull id) initWithFileURL:(nonnull NSURL *) fileURL {
	self = [super init];
	if (self) {
		NSParameterAssert(fileURL);

		_fileType = LzmaSDKObjCDetectFileType(fileURL);
		_fileURL = fileURL;

		_encoder = new LzmaSDKObjC::FileEncoder();
		NSAssert(_encoder, @"Can't create encoder object");
	}
	return self;
}

- (nonnull id) initWithFileURL:(nonnull NSURL *) fileURL andType:(LzmaSDKObjCFileType) type {
	self = [super init];
	if (self) {
		NSParameterAssert(fileURL);

		_fileURL = fileURL;
		_fileType = type;

		_encoder = new LzmaSDKObjC::FileEncoder();
		NSAssert(_encoder, @"Can't create encoder object");
	}
	return self;
}

- (BOOL) openPath:(NSString *) path withError:(NSError **) error {
	[[NSFileManager defaultManager] removeItemAtPath:path error:nil];
	_encoder->context = (__bridge void *)self;
	_encoder->getVoidCallback1 = _LzmaSDKObjCWriterGetVoidCallback1;
	_encoder->setFloatCallback2 = _LzmaSDKObjCWriterSetFloatCallback;
	if (_encoder->openFile([path UTF8String])) return YES;

	if (error) *error = self.lastError;
	return NO;
}

- (BOOL) open:(NSError * _Nullable * _Nullable) error {
	if (!_encoder->prepare(_fileType)) {
		if (error) *error = self.lastError;
		return NO;
	}

	if (!_fileURL) {
		_encoder->setLastError(-1, __LINE__, __FILE__, "No file URL provided");
		if (error) *error = self.lastError;
		return NO;
	}

	NSString * path = [_fileURL path];
	if (path) {
		if ([self openPath:path withError:error]) return YES;
	}

	if (error) *error = self.lastError;
	return NO;
}

- (BOOL) write {
	_encoder->clearLastError();
	_encoder->encodeItems((__bridge void *)_items, (uint32_t)[_items count]);
	return _encoder->lastError() ? NO : YES;
}

- (BOOL) addData:(nonnull NSData *) data forPath:(nonnull NSString *) path {
	NSParameterAssert(data);
	NSParameterAssert(path);
	LzmaSDKObjCMutableItem * item = [[LzmaSDKObjCMutableItem alloc] init];
	NSAssert(item, @"Can't create item");
	[item setPath:path isDirectory:NO];
	item.fileData = data;
	if (_items) [_items addObject:item];
	else _items = [NSMutableArray arrayWithObject:item];
	return YES;
}

- (BOOL) addPath:(nonnull NSString *) aPath forPath:(nonnull NSString *) path {
	NSParameterAssert(aPath);
	NSParameterAssert(path);
	BOOL isDir = NO;
	NSError * error = nil;
	if ([[NSFileManager defaultManager] fileExistsAtPath:aPath isDirectory:&isDir]) {
		if (isDir) {
			NSArray * contents = [[NSFileManager defaultManager] contentsOfDirectoryAtPath:aPath error:&error];
			if (error) return NO;
			if (contents) {
				for (NSString * subName in contents) {
					NSString * aSubPath = [aPath stringByAppendingPathComponent:subName];
					NSString * subPath = [path stringByAppendingPathComponent:subName];
					if (aSubPath && subPath) [self addPath:aSubPath forPath:subPath];
				}
			}
			return YES;
		} else {
			NSDictionary * attribs = [[NSFileManager defaultManager] attributesOfItemAtPath:aPath error:&error];
			if (!attribs || error) return NO;

			NSNumber * number = [attribs objectForKey:NSFileSize];
			if (!number) return NO;

			LzmaSDKObjCMutableItem * item = [[LzmaSDKObjCMutableItem alloc] init];
			NSAssert(item, @"Can't create item");

			[item setPath:path isDirectory:NO];
			item->_orgSize = (uint64_t)[number unsignedLongLongValue];
			item->_content = aPath;
			NSDate * now = [NSDate date];
			NSDate * date = [attribs objectForKey:NSFileCreationDate];
			item.creationDate = date ? date : now;
			date = [attribs objectForKey:NSFileModificationDate];
			item.modificationDate = date ? date : now;
			item.accessDate = now;

			if (_items) [_items addObject:item];
			else _items = [NSMutableArray arrayWithObject:item];
			return YES;
		}
	}
	return NO;
}

- (LzmaSDKObjCMethod) method {
	return (LzmaSDKObjCMethod)_encoder->method;
}

- (void) setMethod:(LzmaSDKObjCMethod) value {
	_encoder->method = (unsigned char)value;
}

- (BOOL) solid {
	return _encoder->settingsValue(LZMAOBJC_ENC_SOLID) ? YES : NO;
}

- (void) setSolid:(BOOL) value {
	_encoder->setSettingsValue(value ? true : false, LZMAOBJC_ENC_SOLID);
}

- (unsigned char) compressionLevel {
	return _encoder->compressionLevel;
}

- (void) setCompressionLevel:(unsigned char) level {
	if (level) _encoder->compressionLevel = (level > 9) ? 9 : level;
	else _encoder->compressionLevel = 1;
}

- (BOOL) compressHeader {
	return _encoder->settingsValue(LZMAOBJC_ENC_COMPR_HDR) ? YES : NO;
}

- (void) setCompressHeader:(BOOL) value {
	_encoder->setSettingsValue(value ? true : false, LZMAOBJC_ENC_COMPR_HDR);
}

- (BOOL) compressHeaderFull {
	return _encoder->settingsValue(LZMAOBJC_ENC_COMPR_HDR_FULL) ? YES : NO;
}

- (void) setCompressHeaderFull:(BOOL) value {
	_encoder->setSettingsValue(value ? true : false, LZMAOBJC_ENC_COMPR_HDR_FULL);
}

- (BOOL) encodeContent {
	return _encoder->settingsValue(LZMAOBJC_ENC_ENC_CONTENT) ? YES : NO;
}

- (void) setEncodeContent:(BOOL) value {
	_encoder->setSettingsValue(value ? true : false, LZMAOBJC_ENC_ENC_CONTENT);
}

- (BOOL) encodeHeader {
	return _encoder->settingsValue(LZMAOBJC_ENC_ENC_HEADER) ? YES : NO;
}

- (void) setEncodeHeader:(BOOL) value {
	_encoder->setSettingsValue(value ? true : false, LZMAOBJC_ENC_ENC_HEADER);
}

- (BOOL) writeCreationTime {
	return _encoder->settingsValue(LZMAOBJC_ENC_WRITE_CTIME) ? YES : NO;
}

- (void) setWriteCreationTime:(BOOL) value {
	_encoder->setSettingsValue(value ? true : false, LZMAOBJC_ENC_WRITE_CTIME);
}

- (BOOL) writeAccessTime {
	return _encoder->settingsValue(LZMAOBJC_ENC_WRITE_ATIME) ? YES : NO;
}

- (void) setWriteAccessTime:(BOOL) value {
	_encoder->setSettingsValue(value ? true : false, LZMAOBJC_ENC_WRITE_ATIME);
}

- (BOOL) writeModificationTime {
	return _encoder->settingsValue(LZMAOBJC_ENC_WRITE_MTIME) ? YES : NO;
}

- (void) setWriteModificationTime:(BOOL) value {
	_encoder->setSettingsValue(value ? true : false, LZMAOBJC_ENC_WRITE_MTIME);
}

- (void) dealloc {
	_encoder->context = NULL;
	delete _encoder;

	_passwordGetter = nil;
}

@end
