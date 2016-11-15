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

@interface WriteObjc : TestBaseObjc <LzmaSDKObjCWriterDelegate>

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

- (void) readCreated:(NSString *) path {
	LzmaSDKObjCReader * reader = [[LzmaSDKObjCReader alloc] initWithFileURL:[NSURL fileURLWithPath:path]];
	reader.passwordGetter = ^NSString*() {
		return @"1234";
	};
	XCTAssertNil(reader.lastError);
	NSError * error = nil;
	XCTAssertTrue([reader open:&error]);
	XCTAssertNil(error);
	XCTAssertNil(reader.lastError);
	NSMutableArray * items = [NSMutableArray arrayWithCapacity:5];
	[reader iterateWithHandler:^BOOL(LzmaSDKObjCItem * _Nonnull item, NSError * _Nullable error) {
		XCTAssertNil(error);
		[items addObject:item];
		if ([item.fileName isEqualToString:@"shutuptakemoney.jpg"]) {
			XCTAssertTrue(item.originalSize == 33402);
			XCTAssertTrue(item.crc32 == 0x0b0646c5);
		} else if ([item.fileName isEqualToString:@"SouthPark.jpg"]) {
			XCTAssertTrue(item.originalSize == 40782);
			XCTAssertTrue(item.crc32 == 0x1243b886);
		} else if ([item.fileName isEqualToString:@"zombies.jpg"]) {
			XCTAssertTrue(item.originalSize == 83131);
			XCTAssertTrue(item.crc32 == 0xb5e98c78);
		} else if ([item.fileName isEqualToString:@"München.png"] ||
				   [item.fileName isEqualToString:@"Мюнхен.png"]) {
			XCTAssertTrue(item.originalSize == 10018);
			XCTAssertTrue(item.crc32 == 0xaa7eaf66);
		}
		return YES;
	}];
	XCTAssertTrue([items count] == 5);
	XCTAssertNil(reader.lastError);
	XCTAssertTrue([reader test:items]);

	NSString * extractPath = [path stringByDeletingLastPathComponent];
	XCTAssertTrue([reader extract:items toPath:extractPath withFullPaths:NO]);
	XCTAssertNil(reader.lastError);

	int locatedCount = 0;
	NSArray * outNames = [[NSFileManager defaultManager] contentsOfDirectoryAtPath:extractPath error:nil];
	for (NSString * fileName in outNames) {
		NSString * outPath = [extractPath stringByAppendingPathComponent:fileName];
		NSDictionary * dict = [[NSFileManager defaultManager] attributesOfItemAtPath:outPath error:nil];
		const int outSize = [[dict objectForKey:NSFileSize] intValue];
		NSData * fileData = [NSData dataWithContentsOfFile:outPath];
		if ([fileName isEqualToString:@"shutuptakemoney.jpg"]) {
			XCTAssertTrue(outSize == 33402);
			XCTAssertTrue([fileData CRC32Value] == 0x0b0646c5);
			locatedCount++;
		} else if ([fileName isEqualToString:@"SouthPark.jpg"]) {
			XCTAssertTrue(outSize == 40782);
			XCTAssertTrue([fileData CRC32Value] == 0x1243b886);
			locatedCount++;
		} else if ([fileName isEqualToString:@"zombies.jpg"]) {
			XCTAssertTrue(outSize == 83131);
			XCTAssertTrue([fileData CRC32Value] == 0xb5e98c78);
			locatedCount++;
		} else if ([fileName isEqualToString:@"München.png"] ||
				   [fileName isEqualToString:@"Мюнхен.png"]) {
			XCTAssertTrue(outSize == 10018);
			XCTAssertTrue([fileData CRC32Value] == 0xaa7eaf66);
			locatedCount++;
		}
	}

	XCTAssertTrue(locatedCount == 5);
}

- (void) testWrite {
	int testNumber = 0;
	int minSize = INT_MAX;
	NSString * minString = @"";
	for (NSNumber * method in @[ [NSNumber numberWithInt:LzmaSDKObjCMethodLZMA], [NSNumber numberWithInt:LzmaSDKObjCMethodLZMA2] ]) {
		for (NSNumber * solid in @[ @NO, @YES ]) {
			for (unsigned char compressionLevel = 0; compressionLevel <= 9; compressionLevel += 3) {
				for (NSNumber * compressHeader in @[ @NO, @YES ]) {
					for (NSNumber * compressHeaderFull in @[ @NO, @YES ]) {
						for (NSNumber * encodeContent in @[ @NO, @YES ]) {
							for (NSNumber * encodeHeader in @[ @NO, @YES ]) {
//								for (NSNumber * writeCreationTime in @[ @NO, @YES ]) {
//									for (NSNumber * writeAccessTime in @[ @NO, @YES ]) {
//										for (NSNumber * writeModificationTime in @[ @NO, @YES ]) {
								NSString * path = [[self tmpWriteFile] stringByAppendingPathExtension:@"7z"];
								LzmaSDKObjCWriter * writer = [[LzmaSDKObjCWriter alloc] initWithFileURL:[NSURL fileURLWithPath:path]];
								[writer addPath:[self pathForTestFile:@"shutuptakemoney.jpg"] forPath:@"shutuptakemoney.jpg"];
								[writer addPath:[self pathForTestFile:@"SouthPark.jpg"] forPath:@"SouthPark.jpg"];
								[writer addPath:[self pathForTestFile:@"zombies.jpg"] forPath:@"zombies.jpg"];
								[writer addPath:[self pathForTestFile:@"München.png"] forPath:@"München.png"];
								[writer addPath:[self pathForTestFile:@"Мюнхен.png"] forPath:@"Мюнхен.png"];
								writer.passwordGetter = ^NSString*() {
									return @"1234";
								};
								writer.method = method.unsignedCharValue;
								writer.solid = solid.boolValue;
								writer.compressionLevel = compressionLevel;
								writer.compressHeader = compressHeader.boolValue;
								writer.compressHeaderFull = compressHeaderFull.boolValue;
								writer.encodeContent = encodeContent.boolValue;
								writer.encodeHeader = encodeHeader.boolValue;
//											writer.writeCreationTime = writeCreationTime.boolValue;
//											writer.writeAccessTime = writeAccessTime.boolValue;
//											writer.writeModificationTime = writeModificationTime.boolValue;
								XCTAssertTrue([writer open:nil]);
								XCTAssertTrue([writer write]);

								NSDictionary * dict = [[NSFileManager defaultManager] attributesOfItemAtPath:path error:nil];
								const int outSize = [[dict objectForKey:NSFileSize] intValue];
								NSString * log = [NSString stringWithFormat:@"size: %i\nmethod: %i\nsolid: %@\ncompressionLevel: %i\ncompressHeader: %@\ncompressHeaderFull: %@\nencodeContent: %@\nencodeHeader: %@\nwriteCreationTime: %@\nwriteAccessTime: %@\nwriteModificationTime: %@\n\n",
												  outSize,
												  method.intValue,
												  solid.boolValue ? @"YES" : @"NO",
												  (int)compressionLevel,
												  compressHeader.boolValue ? @"YES" : @"NO",
												  compressHeaderFull.boolValue ? @"YES" : @"NO",
												  encodeContent.boolValue ? @"YES" : @"NO",
												  encodeHeader.boolValue ? @"YES" : @"NO",
//															  writeCreationTime.boolValue ? @"YES" : @"NO",
//															  writeAccessTime.boolValue ? @"YES" : @"NO",
//															  writeModificationTime.boolValue ? @"YES" : @"NO"
												  @"YES",@"YES",@"YES"

												  ];
								XCTAssertTrue(outSize > 0);
								NSLog(@"Writer test # %i\n%@", ++testNumber, log);
								if (minSize > outSize) {
									minSize = outSize;
									minString = log;
								}
								[self readCreated:path];
								[[NSFileManager defaultManager] removeItemAtPath:path error:nil];
							}
						}
//								}
//							}
//						}
					}
				}
			}
		}
	}
	NSLog(@"Minimum: %@", minString);
}


@end
