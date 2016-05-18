//
//  Buffer.m
//  LzmaSDK-ObjC
//
//  Created by Resident evil on 03/04/16.
//  Copyright © 2016 olehkulykov. All rights reserved.
//

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
