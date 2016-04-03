//
//  Buffer.m
//  LzmaSDK-ObjC
//
//  Created by Resident evil on 03/04/16.
//  Copyright © 2016 olehkulykov. All rights reserved.
//

#import <XCTest/XCTest.h>
#import "TestBaseObjc.h"

@interface Buffer : TestBaseObjc

@end

@implementation Buffer

- (void)setUp {
    [super setUp];
    // Put setup code here. This method is called before the invocation of each test method in the class.
}

- (void)tearDown {
    // Put teardown code here. This method is called after the invocation of each test method in the class.
    [super tearDown];
}

- (void) testCompressDecompress {
	NSString * srcString = @"Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat.";
	for (int i = 0; i < 10; i++) srcString = [srcString stringByAppendingString:@"Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum."];
	XCTAssertNotNil(srcString);

	NSData * src1 = [NSData dataWithBytes:[srcString UTF8String] length:[srcString lengthOfBytesUsingEncoding:NSUTF8StringEncoding]];
	XCTAssertNotNil(src1);

	NSData * dst1 = LzmaSDKObjCBufferCompressLZMA2(src1, 1);
	XCTAssertNotNil(dst1);

	NSData * dst2 = LzmaSDKObjCBufferDecompressLZMA2(dst1);
	XCTAssertNotNil(dst2);

	XCTAssertTrue([src1 isEqualToData:dst2]);

	NSString * dstString1 = [[NSString alloc] initWithBytes:[dst2 bytes] length:[dst2 length] encoding:NSUTF8StringEncoding];
	XCTAssertNotNil(dstString1);

	XCTAssertTrue([srcString isEqualToString:dstString1]);
}

- (void)testPerformanceExample {
    // This is an example of a performance test case.
    [self measureBlock:^{
        // Put the code you want to measure the time of here.
    }];
}

@end
