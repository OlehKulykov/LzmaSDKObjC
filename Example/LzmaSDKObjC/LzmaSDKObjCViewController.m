//
//  LzmaSDKObjCViewController.m
//  LzmaSDKObjC
//
//  Created by OlehKulykov on 12/16/2015.
//  Copyright (c) 2015 OlehKulykov. All rights reserved.
//

#import "LzmaSDKObjCViewController.h"

#import <LzmaSDKObjC/LzmaSDKObjCReader.h>

@interface LzmaSDKObjCViewController() <LzmaSDKObjCReaderDelegate>

@property (strong) LzmaSDKObjCReader * reader;

@end

@implementation LzmaSDKObjCViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
	// Do any additional setup after loading the view, typically from a nib.

	NSLog(@"%@", NSHomeDirectory());

	// select full path to archive file with 7z or xz extension
	NSString * archivePath = @"/Volumes/Data/Documents/LzmaSDKObjC/tests/files/lzma.7z";

	// 1.1 Create and hold strongly reader object.
	self.reader = [[LzmaSDKObjCReader alloc] initWithFileURL:[NSURL fileURLWithPath:archivePath]];
	// 1.2 Or create with predefined archive type if path doesn't containes suitable extension
//	self.reader = [[LzmaSDKObjCReader alloc] initWithFileURL:[NSURL fileURLWithPath:archivePath]
//													 andType:LzmaSDKObjCFileType7z];

	// Optionaly: assign weak delegate for tracking extract progress.
	_reader.delegate = self;

	// If achive encrypted - define password getter handler.
	// NOTES:
	// - Encrypted file needs password for extract process.
	// - Encrypted file with encrypted header needs password for list(iterate) and extract archive items.
	_reader.passwordGetter = ^NSString*(void){
		return @"1234";
	};

	// Open archive, with or without error. Error can be nil.
	NSError * error = nil;
	if (![_reader open:&error])
	{
  NSLog(@"Open error: %@", error);
	}
	NSLog(@"Open error: %@", _reader.lastError);

	// Iterate all archive items, track what items do you need & hold them in array.
	NSMutableArray * items = [NSMutableArray array]; // Array with selected items.
	[_reader iterateWithHandler:^BOOL(LzmaSDKObjCItem * item, NSError * error){
		NSLog(@"\n%@", item);
		if (item) [items addObject:item]; // if needs this item - store to array.
		return YES; // YES - continue iterate, NO - stop iteration
	}];
	NSLog(@"Iteration error: %@", _reader.lastError);

	// Extract selected items from prev. step.
	// YES - create subfolders structure for the items.
	// NO - place item file to the root of path(in this case items with the same names will be overwrited automaticaly).
	[_reader extract:items
			  toPath:@"/Volumes/Data/1"
    withFullPaths:YES];
	NSLog(@"Extract error: %@", _reader.lastError);
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
