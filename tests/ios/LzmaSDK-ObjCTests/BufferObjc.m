/*
 *   Copyright (c) 2015 - 2018 Oleh Kulykov <info@resident.name>
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


#import <XCTest/XCTest.h>
#import "TestBaseObjc.h"

@interface BufferObjc : TestBaseObjc

@end

@implementation BufferObjc

- (void) testCompressDecompress {
	NSString * srcString = @"Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat.";
	for (int i = 0; i < 10; i++) srcString = [srcString stringByAppendingString:@"Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum."];
	XCTAssertNotNil(srcString);

	NSData * sourceData = [NSData dataWithBytes:[srcString UTF8String] length:[srcString lengthOfBytesUsingEncoding:NSUTF8StringEncoding]];
	XCTAssertNotNil(sourceData);

	NSData * compressedData = LzmaSDKObjCBufferCompressLZMA2(sourceData, 1);
	XCTAssertNotNil(compressedData);

	NSData * decompressedData = LzmaSDKObjCBufferDecompressLZMA2(compressedData);
	XCTAssertNotNil(decompressedData);

	XCTAssertTrue([sourceData isEqualToData:decompressedData]);

	NSString * dstString1 = [[NSString alloc] initWithBytes:[decompressedData bytes] length:[decompressedData length] encoding:NSUTF8StringEncoding];
	XCTAssertNotNil(dstString1);

	XCTAssertTrue([srcString isEqualToString:dstString1]);
}

@end
