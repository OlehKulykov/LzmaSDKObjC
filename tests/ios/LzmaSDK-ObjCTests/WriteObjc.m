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


#import <XCTest/XCTest.h>
#import "TestBaseObjc.h"

@interface WriteObjc : XCTestCase <LzmaSDKObjCWriterDelegate>

@end

@implementation WriteObjc

#pragma mark - LzmaSDKObjCWriterDelegate
- (void) onLzmaSDKObjCWriter:(LzmaSDKObjCWriter *)writer writeProgress:(float)progress {
	NSLog(@"Write progress: %f, %i %%", progress, (int)(progress * 100));
}

- (void) testMutableItem {
	LzmaSDKObjCMutableItem * item = [[LzmaSDKObjCMutableItem alloc] init];

	[item setPath:@"f" isDirectory:NO];
	XCTAssertTrue([item.path isEqualToString:@"f"]);
	XCTAssertFalse(item.isDirectory);
	XCTAssertNil(item.directoryPath);
	XCTAssertTrue([item.fileName isEqualToString:@"f"]);

	[item setPath:@"d/f" isDirectory:NO];
	XCTAssertTrue([item.path isEqualToString:@"d/f"]);
	XCTAssertFalse(item.isDirectory);
	XCTAssertNotNil(item.directoryPath);
	XCTAssertTrue([item.fileName isEqualToString:@"f"]);
	XCTAssertTrue([item.directoryPath isEqualToString:@"d"]);

	[item setPath:@"d" isDirectory:YES];
	XCTAssertTrue([item.path isEqualToString:@"d"]);
	XCTAssertTrue(item.isDirectory);
	XCTAssertNotNil(item.directoryPath);
	XCTAssertNil(item.fileName);
	XCTAssertTrue([item.directoryPath isEqualToString:@"d"]);

	[item setPath:@"d1/d2" isDirectory:YES];
	XCTAssertTrue([item.path isEqualToString:@"d1/d2" ]);
	XCTAssertTrue(item.isDirectory);
	XCTAssertNotNil(item.directoryPath);
	XCTAssertNil(item.fileName);
	XCTAssertTrue([item.directoryPath isEqualToString:@"d1/d2"]);

	NSDate * now = [NSDate date];
	item.modificationDate = now;
	item.accessDate = now;
	item.creationDate = now;

	NSDate * mDate = item.modificationDate;
	NSDate * aDate = item.accessDate;
	NSDate * cDate = item.creationDate;

	// compare as uints
	XCTAssertTrue((NSUInteger)mDate.timeIntervalSince1970 == (NSUInteger)now.timeIntervalSince1970);
	XCTAssertTrue((NSUInteger)aDate.timeIntervalSince1970 == (NSUInteger)now.timeIntervalSince1970);
	XCTAssertTrue((NSUInteger)cDate.timeIntervalSince1970 == (NSUInteger)now.timeIntervalSince1970);
}

- (void) testWrite {


}


@end
