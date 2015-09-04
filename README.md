# Lzma SDK Objective-C
Lzma SDK for Objective-C based on extended functionality of the C++ LZMA code

#### Features list (TODO/DONE)
- [ ] **Lzma/.7z**
  - [ ] **List**
    - [x] Regular archive. ```tests/files/lzma.7z```
    - [x] Encrypted archive with AES256. ```tests/files/lzma_aes256.7z```
    - [x] Encrypted archive + encrypted header(*no visible content, files list, without password*) with AES256. ```tests/files/lzma_aes256_encfn.7z```
  - [ ] **Extract**
    - [ ] Regular archive. ```tests/files/lzma.7z```
    - [ ] Encrypted archive with AES256. ```tests/files/lzma_aes256.7z```
    - [ ] Encrypted archive + encrypted header(*no visible content, files list, without password*) with AES256. ```tests/files/lzma_aes256_encfn.7z```
  - [ ] **Create**
  - [ ] **Update**
- [ ] **Lzma2/.7z**
  - [ ] **List**
    - [x] Regular archive. ```tests/files/lzma2.7z```
    - [x] Encrypted archive with AES256. ```tests/files/lzma2_aes256.7z```
    - [x] Encrypted archive + encrypted header(*no visible content, files list, without password*) with AES256. ```tests/files/lzma2_aes256_encfn.7z```
  - [ ] **Extract**
    - [ ] Regular archive. ```tests/files/lzma2.7z```
    - [ ] Encrypted archive with AES256. ```tests/files/lzma2_aes256.7z```
    - [ ] Encrypted archive + encrypted header(*no visible content, files list, without password*) with AES256. ```tests/files/lzma2_aes256_encfn.7z```
  - [ ] **Create**
  - [ ] **Update**
- [ ] **Omit unused code**, reduce buildable, original code size.
