[![CocoaPods](https://img.shields.io/cocoapods/p/LzmaSDK-ObjC.svg?style=flat)](http://cocoapods.org/pods/LzmaSDK-ObjC)
[![CocoaPods](https://img.shields.io/cocoapods/v/LzmaSDK-ObjC.svg?style=flat)](http://cocoapods.org/pods/LzmaSDK-ObjC)


Lzma SDK for Objective-C based on extended functionality of the C++ [LZMA SDK] code. 
Available for iOS and MacOS.

### Description
----------------
It's not yet another wrapper around C part of the [LZMA SDK] with all it's limitations. Based on C++ [LZMA SDK] version 15.06 (1506 - latest for now) and patched for iOS & MacOS platforms.

The main advantages is:
- List, extract **7z** files (**Lzma** & **Lzma2** *compression method*).
- List, extract **encrypted** (*password protected*) **7z** files (**Lzma** & **Lzma2** *compression method*).
- List, extract **encrypted** (password protected) + **encrypted header** (*no visible content, files list, without password*) **7z** files (**Lzma** & **Lzma2** *compression method*).
- Manage memory allocations during listing/extracting.
- Tuned up for using less than 500Kb for listing/extracting, can be easly changed runtime (*no hardcoded definitions*).
- Manage IO read/write operations, aslo can be easly changed runtime (*no hardcoded definitions*).
- Track smoothed progress, which becomes possible with prev.
- Support reading archive files with size more than 4GB and extracting files with size more than 4GB.
- Unicode support.


### Installation with [CocoaPods]
#### Podfile
```ruby
pod 'LzmaSDK-ObjC'
```


### Example
-----------
#### List and extract
```objc
// select full path to archive file.
NSString * archivePath = <path to archive>;

// Create and hold strongly reader object.
self.reader = [[LzmaSDKObjCReader alloc] initWithFileURL:[NSURL fileURLWithPath:archivePath]];

// Optionaly: assign weak delegate for tracking extract progress.
_reader.delegate = self;

// If achive encrypted - define password getter handler.
// NOTES:
// - Encrypted file needs password for extract process.
// - Encrypted file with encrypted header needs password for list(iterate) and extract archive items.
_reader.passwordGetter = ^NSString*(void){
  return @"password to my achive";
};

// Open archive, with or without error. Error can be nil.
NSError * error = nil;
if (![_reader open:&error])
{
  NSLog(@"Open error: %@", error);
}

// Iterate all archive items, track what items do you need & hold them in array.
NSMutableArray * items = [NSMutableArray array]; // Array with selected items.
[_reader iterateWithHandler:^BOOL(LzmaSDKObjCItem * item, NSError * error){
	NSLog(@"\n%@", item);
	if (item) [items addObject:item]; // if needs this item - store to array.
	return YES; // YES - continue iterate, NO - stop iteration
}];

// Extract selected items from prev. step.
// YES - create subfolders structure for the item.
// NO - place item file to the root of path(in this case items with the same names will be overwrited automaticaly).
[_reader extract:items
          toPath:@"/extract/path"
    withFullPaths:YES]; 
```


### Tune up speed, performance and disk IO operations
-----------------------------------------------------
Original C++ part of the [LZMA SDK] was patched to have a possibility to tune up default(*hardcoded*) settings.
For list and extract functionality was defined next global variables: ```kLzmaSDKObjCStreamReadSize```, ```kLzmaSDKObjCStreamWriteSize```, ```kLzmaSDKObjCDecoderReadSize``` and ```kLzmaSDKObjCDecoderWriteSize```.
This variables holds size values in bytes, so, for the single reader object summary of this 4's values will be allocated.

Keep in mind: operations with **memory much more faster** than **disk IO operations**, so read below situations:
```c
switch (<what do I need ?>)
{
	case <I need faster list and extract>:
		//TODO: Increase stream and decoder size of buffers
		Result:
			1. more allocated memory
			2. less IO read/write operations and less delays
			3. less smoothed progress
			4. more CPU load (do a job, not distracted to read/write data)
		break;

	case <I need use less memory or more smoothed progress>:
		//TODO: Decrease stream and decoder size of buffers
		Result:
			1. less allocated memory
			2. more IO read/write operations and more delays
			3. more smoothed progress
			4. less CPU load (wait for read/write data)
		break;

	default:
		//TODO: use current settings
		break;
	};
```
> NOTE: Modify global variables **before** creating & using reader object.

> NOTE: This allocation sizes doesn't affet to memory allocated for the archive dictionary.


### Features list (TODO/DONE)
-----------------------------
- [ ] **Lzma/*.7z**
  - [x] **List**
    - [x] Regular archive. ```tests/files/lzma.7z```
    - [x] Encrypted archive with AES256. ```tests/files/lzma_aes256.7z```
    - [x] Encrypted archive + encrypted header(*no visible content, files list, without password*) with AES256. ```tests/files/lzma_aes256_encfn.7z```
  - [x] **Extract**
    - [x] Regular archive. ```tests/files/lzma.7z```
    - [x] Encrypted archive with AES256. ```tests/files/lzma_aes256.7z```
    - [x] Encrypted archive + encrypted header(*no visible content, files list, without password*) with AES256. ```tests/files/lzma_aes256_encfn.7z```
  - [ ] **Create**
  - [ ] **Update**
- [ ] **Lzma2/*.7z**
  - [x] **List**
    - [x] Regular archive. ```tests/files/lzma2.7z```
    - [x] Encrypted archive with AES256. ```tests/files/lzma2_aes256.7z```
    - [x] Encrypted archive + encrypted header(*no visible content, files list, without password*) with AES256. ```tests/files/lzma2_aes256_encfn.7z```
  - [x] **Extract**
    - [x] Regular archive. ```tests/files/lzma2.7z```
    - [x] Encrypted archive with AES256. ```tests/files/lzma2_aes256.7z```
    - [x] Encrypted archive + encrypted header(*no visible content, files list, without password*) with AES256. ```tests/files/lzma2_aes256_encfn.7z```
  - [ ] **Create**
  - [ ] **Update**
- [ ] **Omit unused code**, reduce buildable, original code size.


### License
-----------
By using this all you are accepting original [LZMA SDK] and with MIT license (*see below*):

The MIT License (MIT)

Copyright (c) 2015 Kulykov Oleh <info@resident.name>

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.


[LZMA SDK]:http://www.7-zip.org/sdk.html
[CocoaPods]:http://cocoapods.org/pods/LzmaSDK-ObjC
