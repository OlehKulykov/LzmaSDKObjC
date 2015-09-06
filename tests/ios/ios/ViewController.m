//
//  ViewController.m
//  ios
//
//  Created by Resident evil on 9/2/15.
//  Copyright (c) 2015 Resident evil. All rights reserved.
//

#import "ViewController.h"
#import "LzmaSDKObjCReader.h"

@interface ViewController () <LzmaSDKObjCReaderDelegate>

@property (nonatomic, strong) LzmaSDKObjCReader * reader;

@end

@implementation ViewController

- (void) onLzmaSDKObjCReader:(LzmaSDKObjCReader *) reader
			 extractProgress:(float) progress
{
	NSLog(@"DELEGATE, extractProgress = %f", progress);
}

- (IBAction) on1:(id)sender
{
//	self.reader = [[LzmaObjcReader alloc] initWithFileURL:[NSURL fileURLWithPath:@"/Volumes/Data/1/1.7z"]];
//	[_reader open:nil];
//	[_reader read:nil];
//	self.reader = nil;

	NSString * testFile = nil;

	testFile = @"lzma.7z";
//	testFile = @"lzma_aes256.7z";
//	testFile = @"lzma_aes256_encfn.7z";

	testFile = @"lzma2.7z";
	testFile = @"lzma2_aes256.7z";
	testFile = @"lzma2_aes256_encfn.7z";

//	testFile = @"ppmd.7z";
//	testFile = @"bzip2.7z";
//	testFile = @"bzip2_aes256.7z";
//	testFile = @"ppmd_aes256.7z";
//	testFile = @"bzip2_aes256_encfn.7z";
//	testFile = @"ppmd_aes256_encfn.7z";


	NSString * archivePath = [@"/Volumes/Data/Documents/LzmaSDK-ObjC/tests/files/" stringByAppendingPathComponent:testFile];
	archivePath = @"/Volumes/Data/1/1.7z";

	self.reader = [[LzmaSDKObjCReader alloc] initWithFileURL:[NSURL fileURLWithPath:archivePath]];
	_reader.delegate = self;

	_reader.passwordGetter = ^NSString*(void){
		return @"1234";
	};

	NSError * error = nil;
	[_reader open:&error];

	NSMutableArray * items = [NSMutableArray array];
	[_reader iterateWithHandler:^BOOL(LzmaSDKObjCItem * item, NSError * error){
		NSLog(@"\n%@", item);
		if (item) [items addObject:item];
		return YES;
	}];

	[_reader extract:items
			  toPath:@"/Volumes/Data/1/"
	   withFullPaths:YES];
}

- (void)viewDidLoad {
	[super viewDidLoad];
	// Do any additional setup after loading the view, typically from a nib.


}

- (void)didReceiveMemoryWarning {
	[super didReceiveMemoryWarning];
	// Dispose of any resources that can be recreated.
}

@end
