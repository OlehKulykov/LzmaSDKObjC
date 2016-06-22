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

@interface LzmaSDKObjCWriter()
{
@private
	LzmaSDKObjC::FileEncoder * _encoder;

	__strong NSURL * _fileURL;
}

@end

@implementation LzmaSDKObjCWriter

- (NSError *) lastError
{
	LzmaSDKObjC::Error * error = _encoder ? _encoder->lastError() : NULL;
	if (error)
	{
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

- (NSURL *) fileURL
{
	return _fileURL;
}

- (nonnull id) initWithFileURL:(nonnull NSURL *) fileURL {
	self = [super init];
	if (self)
	{
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
	if (self)
	{
		NSParameterAssert(fileURL);

		_fileURL = fileURL;
		_fileType = type;

		_encoder = new LzmaSDKObjC::FileEncoder();
		NSAssert(_encoder, @"Can't create encoder object");
	}
	return self;
}

- (void) dealloc {

	if (_encoder)
	{
		_encoder->context = NULL;
		delete _encoder;
	}

	_passwordGetter = nil;
}

@end
