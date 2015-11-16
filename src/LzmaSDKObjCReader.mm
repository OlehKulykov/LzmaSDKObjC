/*
 *   Copyright (c) 2015 Kulykov Oleh <info@resident.name>
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


#import "LzmaSDKObjCReader.h"

#include "LzmaSDKObjCFileDecoder.h"
#include "LzmaSDKObjCCommon.h"

#import "LzmaSDKObjCItem+Private.h"

#include <wchar.h>

NSString * const _Nonnull kLzmaSDKObjCFileExt7z = @"7z";

NSString * const _Nonnull kLzmaSDKObjCFileExtXz = @"xz";

NSString * const _Nonnull kLzmaSDKObjCErrorDomain = @"LzmaSDKObjCReader";

@interface LzmaSDKObjCReader()
{
@private
	LzmaSDKObjC::FileDecoder * _decoder;
	
	__strong NSURL * _fileURL;
}

@end

static wchar_t * _LzmaSDKObjCReaderWepGW(NSString * we)
{
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

@implementation LzmaSDKObjCReader

static void _LzmaSDKObjCSetFloatCallback(void * context, float value)
{
	LzmaSDKObjCReader * r = (__bridge LzmaSDKObjCReader *)context;
	if (r)
	{
		id<LzmaSDKObjCReaderDelegate> d = r.delegate;
		if (d && [d respondsToSelector:@selector(onLzmaSDKObjCReader:extractProgress:)])
		{
			if ([NSThread isMainThread]) [d onLzmaSDKObjCReader:r extractProgress:value];
			else dispatch_async(dispatch_get_main_queue(), ^{ [d onLzmaSDKObjCReader:r extractProgress:value]; });
		}
	}
}

static void * _LzmaSDKObjCReaderGetVoidCallback1(void * context)
{
	LzmaSDKObjCReader * r = (__bridge LzmaSDKObjCReader *)context;
	if (r) return r->_passwordGetter ? _LzmaSDKObjCReaderWepGW(r->_passwordGetter()) : NULL;
	return NULL;
}

- (BOOL) openPath:(NSString *) path withError:(NSError **) error
{
	BOOL isDir = YES;
	if ([[NSFileManager defaultManager] fileExistsAtPath:path isDirectory:&isDir])
	{
		if (isDir)
		{
			if (error) *error = [NSError errorWithDomain:kLzmaSDKObjCErrorDomain
													code:-1
												userInfo:@{ NSLocalizedDescriptionKey : @"Archive path is directory." }];
			return NO;
		}
		else
		{
			_decoder->context = (__bridge void *)self;
			_decoder->getVoidCallback1 = _LzmaSDKObjCReaderGetVoidCallback1;
			if (_decoder->openFile([path UTF8String]))
			{
				return YES;
			}
			else
			{
				if (error) *error = [NSError errorWithDomain:kLzmaSDKObjCErrorDomain
														code:-1
													userInfo:@{ NSLocalizedDescriptionKey : @"Can't open file path." }];
				return NO;
			}
		}
	}
	else
	{
		if (error) *error = [NSError errorWithDomain:kLzmaSDKObjCErrorDomain
												code:-1
											userInfo:@{ NSLocalizedDescriptionKey : @"File path doesn't exists." }];
	}

	return NO;
}

- (BOOL) iterateWithHandler:(BOOL(^ _Nonnull)(LzmaSDKObjCItem * _Nonnull item, NSError * _Nullable error)) handler
{
	NSParameterAssert(handler);
	if (_decoder && handler)
	{
		_decoder->iterateStart();
		LzmaSDKObjCItem * item = nil;
		NSError * error = nil;
		do
		{
			item = nil;
			error = nil;
			PROPVARIANT prop = { 0 };
			PROPVARIANT name = { 0 };
			bool r = _decoder->readIteratorProperty(&prop, kpidSize);
			r |= _decoder->readIteratorProperty(&name, kpidPath);
			if (r)
			{
				item = [[LzmaSDKObjCItem alloc] init];
				if (item)
				{
					item->_index = _decoder->iteratorIndex();
					item->_orgSize = LzmaSDKObjCPROPVARIANTGetUInt64(&prop);
					prop = { 0 };

					if (name.vt == VT_BSTR && name.bstrVal)
						item->_path = [[NSString alloc] initWithBytes:name.bstrVal length:sizeof(wchar_t) * wcslen(name.bstrVal) encoding:NSUTF32LittleEndianStringEncoding];

					prop = { 0 };
					if (_decoder->readIteratorProperty(&prop, kpidCTime))
						if (prop.vt == VT_FILETIME) item->_cDate = LzmaSDKObjCFILETIMEToUnixTime(prop.filetime);

					prop = { 0 };
					if (_decoder->readIteratorProperty(&prop, kpidATime))
						if (prop.vt == VT_FILETIME) item->_aDate = LzmaSDKObjCFILETIMEToUnixTime(prop.filetime);

					prop = { 0 };
					if (_decoder->readIteratorProperty(&prop, kpidMTime))
						if (prop.vt == VT_FILETIME) item->_mDate = LzmaSDKObjCFILETIMEToUnixTime(prop.filetime);

					prop = { 0 };
					if (_decoder->readIteratorProperty(&prop, kpidEncrypted))
						if (prop.vt == VT_BOOL && prop.boolVal) item->_flags |= LzmaObjcItemFlagIsEncrypted;

					prop = { 0 };
					if (_decoder->readIteratorProperty(&prop, kpidCRC))
						item->_crc = (uint32_t)LzmaSDKObjCPROPVARIANTGetUInt64(&prop);

					prop = { 0 };
					if (_decoder->readIteratorProperty(&prop, kpidIsDir))
						if (prop.vt == VT_BOOL && prop.boolVal) item->_flags |= LzmaObjcItemFlagIsDir;
				}
				else error = [NSError errorWithDomain:kLzmaSDKObjCErrorDomain code:-1 userInfo:nil];
			}
			NWindows::NCOM::PropVariant_Clear(&name);
		}
		while (handler(item, error) && _decoder->iterateNext());
		return YES;
	}
	return NO;
}

- (BOOL) process:(NSArray *) items
		  toPath:(const char *) path
   withFullPaths:(BOOL) isFullPaths
{
	const uint32_t count = items ? (uint32_t)[items count] : 0;
	if (count && _decoder)
	{
		BOOL isOK = NO;
		uint32_t * itemsIndices = (uint32_t *)malloc(sizeof(uint32_t) * count);
		if (itemsIndices)
		{
			uint32_t index = 0;
			for (LzmaSDKObjCItem * item in items) itemsIndices[index++] = item->_index;
			_decoder->context = (__bridge void *)self;
			_decoder->setFloatCallback2 = _LzmaSDKObjCSetFloatCallback;
			if (_decoder->process(itemsIndices, count, path, path ? (bool)isFullPaths : false)) isOK = YES;
			free(itemsIndices);
		}
		return isOK;
	}
	return NO;
}

- (BOOL) extract:(nullable NSArray *) items
		  toPath:(nullable NSString *) path
   withFullPaths:(BOOL) isFullPaths
{
	const char * cPath = path ? [path UTF8String] : NULL;
	return cPath ? [self process:items toPath:cPath withFullPaths:isFullPaths] : NO;
}

- (BOOL) test:(nullable NSArray *) items
{
	return [self process:items toPath:NULL withFullPaths:NO];
}

- (BOOL) open:(NSError * _Nullable * _Nullable) error
{
	if (!_decoder)
	{
		if (error) *error = [NSError errorWithDomain:kLzmaSDKObjCErrorDomain
												code:-1
											userInfo:@{ NSLocalizedDescriptionKey : @"No suitable decoder found." }];
		return NO;
	}

	if (!_decoder->findCodec(_fileType))
	{
		if (error) *error = [NSError errorWithDomain:kLzmaSDKObjCErrorDomain
												code:-1
											userInfo:@{ NSLocalizedDescriptionKey : @"No suitable decoder found." }];
		return NO;
	}

	if (!_fileURL)
	{
		if (error) *error = [NSError errorWithDomain:kLzmaSDKObjCErrorDomain
												code:-1
												userInfo:@{ NSLocalizedDescriptionKey : @"No file URL provided." }];
		return NO;
	}

	NSString * path = [_fileURL path];
	if (path) return [self openPath:path withError:error];

	return NO;
}

- (NSURL *) fileURL
{
	return _fileURL;
}

- (NSUInteger) itemsCount
{
	return _decoder ? _decoder->itemsCount() : 0;
}

- (nonnull id) initWithFileURL:(nonnull NSURL *) fileURL
{
	self = [super init];
	if (self)
	{
		NSParameterAssert(fileURL);

		_fileType = LzmaSDKObjCDetectFileType(fileURL);
		_fileURL = fileURL;
		
		_decoder = new LzmaSDKObjC::FileDecoder();
		NSAssert(_decoder, @"Can't create decoder object");
	}
	return self;
}

- (nonnull id) initWithFileURL:(nonnull NSURL *) fileURL andType:(LzmaSDKObjCFileType) type
{
	self = [super init];
	if (self)
	{
		NSParameterAssert(fileURL);

		_fileURL = fileURL;
		_fileType = type;

		_decoder = new LzmaSDKObjC::FileDecoder();
		NSAssert(_decoder, @"Can't create decoder object");
	}
	return self;
}

- (void) dealloc
{
	if (_decoder)
	{
		_decoder->context = NULL;
		delete _decoder;
	}

	_fileURL = nil;
	_passwordGetter = nil;
}

@end

LzmaSDKObjCFileType LzmaSDKObjCDetectFileType(NSURL * _Nullable fileURL)
{
	if (fileURL)
	{
		NSString * ext = [[fileURL pathExtension] lowercaseString];
		if (ext)
		{
			if ([ext isEqualToString:kLzmaSDKObjCFileExt7z]) return LzmaSDKObjCFileType7z;
			else if ([ext isEqualToString:kLzmaSDKObjCFileExtXz]) return LzmaSDKObjCFileTypeXz;
		}
	}
	return LzmaSDKObjCFileTypeUndefined;
}

