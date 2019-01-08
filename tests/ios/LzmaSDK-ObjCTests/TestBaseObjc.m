/*
 *   Copyright (c) 2015 - 2019 Oleh Kulykov <info@resident.name>
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


#import "TestBaseObjc.h"

@implementation TestBaseObjc

- (NSString *) pathForTestFile:(NSString *) testFilePath
{
	XCTAssertNotNil(testFilePath);

	NSString * name = [testFilePath stringByDeletingPathExtension];
	XCTAssertNotNil(name);

	NSString * ext = [testFilePath pathExtension];
	XCTAssertNotNil(ext);

	return [[NSBundle bundleForClass:[self class]] pathForResource:name ofType:ext];
}

- (NSString *) tmpWritePath
{
	NSString * path = [NSSearchPathForDirectoriesInDomains(NSCachesDirectory, NSUserDomainMask, YES) firstObject];
	path = [path stringByAppendingPathComponent:@"tmp_test"];
	XCTAssertNotNil(path);
	[[NSFileManager defaultManager] removeItemAtPath:path error:nil];
	[[NSFileManager defaultManager] createDirectoryAtPath:path withIntermediateDirectories:YES attributes:nil error:nil];
	BOOL isDir = NO;
	BOOL exists = [[NSFileManager defaultManager] fileExistsAtPath:path isDirectory:&isDir];
	XCTAssertTrue(exists);
	XCTAssertTrue(isDir);
	return path;
}

- (NSString *) tmpWriteFile {
	return [[self tmpWritePath] stringByAppendingPathComponent:[NSString stringWithFormat:@"%llu", (unsigned long long)[[NSDate date] timeIntervalSince1970]]];
}

@end

#include <zlib.h>

@implementation NSData (CRC32)

- (NSUInteger)CRC32Value {
	uLong crc = crc32(0L, Z_NULL, 0);
	crc = crc32(crc, [self bytes], (uInt)[self length]);
	return crc;
}

@end
