[![CocoaPods](https://img.shields.io/cocoapods/p/LzmaSDK-ObjC.svg?style=flat)](http://cocoapods.org/?q=LzmaSDK-ObjC)
[![CocoaPods](https://img.shields.io/cocoapods/v/LzmaSDK-ObjC.svg?style=flat)](http://cocoapods.org/?q=LzmaSDK-ObjC)


Lzma SDK for Objective-C based on extended functionality of the C++ LZMA code. 
Available for iOS and MacOS.

#### Description
It's not yet another wrapper arround C part of the Lzma library with all it's limitations.

The main advantages is:
- List, extract **7z** files (**Lzma** & **Lzma2** *compression method*).
- List, extract **encrypted** (*password protected*) **7z** files (**Lzma** & **Lzma2** *compression method*).
- List, extract **encrypted** (password protected) + **encrypted header** (*no visible content, files list, without password*) **7z** files (**Lzma** & **Lzma2** *compression method*).
- Manage memory allocations during listing/extracting.
- Setuped for using less than 500Kb for listing/extracting, can be easly changed runtime (*no hardcoded definitions*).
- Manage IO read/write operations, aslo can be easly changed runtime (*no hardcoded definitions*).
- Track smoothed progress, which becomes possible with prev.


#### Features list (TODO/DONE)
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
