[![CocoaPods](https://img.shields.io/cocoapods/p/LzmaSDK-ObjC.svg?style=flat)](http://cocoapods.org/?q=LzmaSDK-ObjC)
[![CocoaPods](https://img.shields.io/cocoapods/v/LzmaSDK-ObjC.svg?style=flat)](http://cocoapods.org/?q=LzmaSDK-ObjC)


Lzma SDK for Objective-C based on extended functionality of the C++ [LZMA SDK] code. 
Available for iOS and MacOS.

#### Description
----------------
It's not yet another wrapper around C part of the Lzma library with all it's limitations. Based on C++ [LZMA SDK] version 15.06 (1506 - latest for now) and patched for iOS & MacOS platforms.

The main advantages is:
- List, extract **7z** files (**Lzma** & **Lzma2** *compression method*).
- List, extract **encrypted** (*password protected*) **7z** files (**Lzma** & **Lzma2** *compression method*).
- List, extract **encrypted** (password protected) + **encrypted header** (*no visible content, files list, without password*) **7z** files (**Lzma** & **Lzma2** *compression method*).
- Manage memory allocations during listing/extracting.
- Setuped for using less than 500Kb for listing/extracting, can be easly changed runtime (*no hardcoded definitions*).
- Manage IO read/write operations, aslo can be easly changed runtime (*no hardcoded definitions*).
- Track smoothed progress, which becomes possible with prev.
- Support reading archive files with size more than 4GB, eg. **HugeFiles=on**
- Support extracting files with size more than 4GB, eg. **HugeFiles=on**


#### Features list (TODO/DONE)
------------------------------
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


#### License
------------
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
