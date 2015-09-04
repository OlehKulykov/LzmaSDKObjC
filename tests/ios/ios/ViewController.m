//
//  ViewController.m
//  ios
//
//  Created by Resident evil on 9/2/15.
//  Copyright (c) 2015 Resident evil. All rights reserved.
//

#import "ViewController.h"
#import "LzmaSDKObjCReader.h"

@interface ViewController ()

@property (nonatomic, strong) LzmaSDKObjCReader * reader;

@end

@implementation ViewController

- (IBAction) on1:(id)sender
{
//	self.reader = [[LzmaObjcReader alloc] initWithFileURL:[NSURL fileURLWithPath:@"/Volumes/Data/1/1.7z"]];
//	[_reader open:nil];
//	[_reader read:nil];
//	self.reader = nil;

	NSString * testFile = nil;

	testFile = @"lzma.7z";
//	testFile = @"lzma_aes256.7z";
	testFile = @"lzma_aes256_encfn.7z";
//	testFile = @"lzma.exe";
//	testFile = @"lzma_aes256.exe";

//	testFile = @"lzma2.exe";
//	testFile = @"ppmd.7z";
//	testFile = @"bzip2.7z";
//	testFile = @"lzma2_aes256.7z";
//	testFile = @"ppmd.exe";
//	testFile = @"bzip2_aes256.7z";
//	testFile = @"lzma2_aes256.exe";
//	testFile = @"ppmd_aes256.7z";
//	testFile = @"bzip2_aes256_encfn.7z";
//	testFile = @"lzma2_aes256_encfn.7z";
//	testFile = @"ppmd_aes256.exe";
//	testFile = @"ppmd_aes256_encfn.7z";
//	testFile = @"lzma2.7z";


	NSString * archivePath = [@"/Volumes/Data/Documents/LzmaSDK-ObjC/tests/files/" stringByAppendingPathComponent:testFile];

	self.reader = [[LzmaSDKObjCReader alloc] initWithFileURL:[NSURL fileURLWithPath:archivePath]];

	_reader.passwordGetter = ^NSString*(void){
		return @"1234";
	};

	NSError * error = nil;
	[_reader open:&error];

	[_reader iterateWithHandler:^BOOL(LzmaSDKObjCItem * item, NSError * error){
		NSLog(@"\n%@", item);
		return YES;
	}];

	[_reader extract];
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
