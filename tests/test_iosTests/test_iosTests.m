

#import <XCTest/XCTest.h>

#import <LzmaSDKObjC/LzmaSDKObjCReader.h>

@interface test_iosTests : XCTestCase

@property (strong) NSArray * filePaths;

@end

@implementation test_iosTests

- (void) setUp
{
    [super setUp];
    // Put setup code here. This method is called before the invocation of each test method in the class.

	self.filePaths = @[
					   @"lzma.7z",
					   @"lzma_aes256.7z",
					   @"lzma_aes256_encfn.7z",

					   @"lzma2.7z",
					   @"lzma2_aes256.7z",
					   @"lzma2_aes256_encfn.7z"

//					   @"bzip2.7z",
//					   @"bzip2_aes256_encfn.7z",
//					   @"bzip2_aes256.7z"

//					   @"ppmd.7z",
//					   @"ppmd_aes256.7z",
//					   @"ppmd_aes256_encfn.7z"
					   ];
	XCTAssertNotNil(self.filePaths, @"ERROR test paths array");
}

- (void)tearDown {
    // Put teardown code here. This method is called after the invocation of each test method in the class.
    [super tearDown];
}

- (void) reader:(LzmaSDKObjCReader *) reader
   extractItems:(NSArray *) items
{
	XCTAssertNotNil(items, @"ERROR items is empty");


	NSFileManager * manager = [[NSFileManager alloc] init];
	NSString * extractPath = [NSSearchPathForDirectoriesInDomains(NSCachesDirectory, NSUserDomainMask, YES) firstObject];
	XCTAssertNotNil(extractPath, @"ERROR file no found");
	[manager removeItemAtPath:extractPath error:nil];

	NSError * error = nil;
	XCTAssertTrue([manager createDirectoryAtPath:extractPath
					 withIntermediateDirectories:YES
									  attributes:nil
										   error:&error],
				  @"ERROR create extract path");
	XCTAssertNil(reader.lastError, @"ERROR create extract path: %@", reader.lastError);

	BOOL isDir = NO;
	XCTAssertTrue([manager fileExistsAtPath:extractPath isDirectory:&isDir],
				  @"ERROR extract path don't exists");
	XCTAssertTrue(isDir, @"ERROR extract path is not directory");

	XCTAssertTrue([reader extract:items
						   toPath:extractPath
					withFullPaths:NO],
				  @"ERROR extract to path error");
	XCTAssertNil(reader.lastError, @"ERROR extract to path error: %@", reader.lastError);

	NSArray * extracted = [manager contentsOfDirectoryAtPath:extractPath error:&error];
	XCTAssertNotNil(extracted, @"ERROR extracted paths is empty");

	XCTAssertTrue([extracted count] > 0, @"ERROR extracted paths is empty");

	[manager removeItemAtPath:extractPath error:nil];

	//
	XCTAssertTrue([manager createDirectoryAtPath:extractPath
					 withIntermediateDirectories:YES
									  attributes:nil
										   error:&error],
				  @"ERROR create extract path");
	XCTAssertNil(reader.lastError, @"ERROR create extract path: %@", reader.lastError);

	isDir = NO;
	XCTAssertTrue([manager fileExistsAtPath:extractPath isDirectory:&isDir],
				  @"ERROR extract path don't exists");
	XCTAssertTrue(isDir, @"ERROR extract path is not directory");

	XCTAssertTrue([reader extract:items
						   toPath:extractPath
					withFullPaths:YES],
				  @"ERROR extract to path error");
	XCTAssertNil(reader.lastError, @"ERROR extract to path error: %@", reader.lastError);

	extracted = [manager contentsOfDirectoryAtPath:extractPath error:&error];
	XCTAssertNotNil(extracted, @"ERROR extracted paths is empty");

	XCTAssertTrue([extracted count] > 0, @"ERROR extracted paths is empty");

	[manager removeItemAtPath:extractPath error:nil];
}

- (void) testReadAndExtract
{
	for (NSString * inFile in self.filePaths)
	{
		NSString * fullPath = [[NSBundle bundleForClass:[self class]]
							   pathForResource:[inFile stringByDeletingPathExtension]
							   ofType:[inFile pathExtension]];
		XCTAssertNotNil(fullPath, @"ERROR file no found");

		LzmaSDKObjCReader * reader = [[LzmaSDKObjCReader alloc] initWithFileURL:[NSURL fileURLWithPath:fullPath]];
		XCTAssertNotNil(reader, @"ERROR internal creating error");
		XCTAssertNotNil(reader.fileURL, @"ERROR internal creating error");
		XCTAssertTrue(reader.fileType != LzmaSDKObjCFileTypeUndefined, @"ERROR can't determine file type");

		reader.passwordGetter = ^NSString*(void){
			return @"1234";
		};

		NSError * error = nil;
		XCTAssertTrue([reader open:&error], @"Can't open archive file");
		XCTAssertNil(error, @"Can't open archive file with error: %@", error);
		XCTAssertNil(reader.lastError, @"Can't open archive file with last error: %@", reader.lastError);


		NSMutableArray * items = [NSMutableArray array];
		XCTAssertNotNil(items, @"ERROR internal creating error");
		[reader iterateWithHandler:^BOOL(LzmaSDKObjCItem * item, NSError * error){
			[items addObject:item];
			return YES;
		}];

		XCTAssertTrue([items count] > 0, @"ERROR Can't read archive items");

		for (LzmaSDKObjCItem * item in items)
		{
			XCTAssertTrue([item isKindOfClass:[LzmaSDKObjCItem class]], @"ERROR worong item class type");
			if (item.isDirectory)
			{
				XCTAssertNotNil(item.directoryPath, @"ERROR item is dir, but no path provided");
			}
			else
			{
				XCTAssertNotNil(item.fileName, @"ERROR item is file, but no file name provided");
			}
		}

		[self reader:reader extractItems:items];
	}
}

- (void)testPerformanceExample
{
    // This is an example of a performance test case.
    [self measureBlock:^{
        // Put the code you want to measure the time of here.
    }];
}

@end
