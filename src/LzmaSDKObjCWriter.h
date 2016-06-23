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


#import "LzmaSDKObjCReader.h"
#import "LzmaSDKObjCMutableItem.h"

@interface LzmaSDKObjCWriter : NSObject

/**
 @brief Getter to the archive password.
 */
@property (nonatomic, copy) NSString * _Nullable (^ _Nullable passwordGetter)(void);

/**
 @brief Type of the assigned archive. Determined during initialization.
 @warning Readonly property. If can't be determined - create reader with custom type.
 */
@property (nonatomic, assign, readonly) LzmaSDKObjCFileType fileType;


/**
 @brief URL to the archive file.
 */
@property (nonatomic, strong, readonly) NSURL * _Nullable fileURL;


/**
 @brief Last error from operation.
 */
@property (nonatomic, strong, readonly) NSError * _Nullable lastError;


/**
 @brief Initialize archive with file url.
 @warning If `fileURL` is nil -> assertion.
 @warning Prev. path will be deleted.
 @warning Type detected from archive file extension using @b LzmaSDKObjCDetectFileType function.
 @param fileURL File url to the archive. Can't be nil.
 */
- (nonnull id) initWithFileURL:(nonnull NSURL *) fileURL;


/**
 @brief Initialize archive with file url and archive type.
 @warning If `fileURL` is nil -> assertion.
 @warning Prev. path will be deleted.
 @param fileURL File url to the archive. Can't be nil.
 @param type Manualy defined type of the archive.
 */
- (nonnull id) initWithFileURL:(nonnull NSURL *) fileURL andType:(LzmaSDKObjCFileType) type;


/**
 @brief Add file data with a given file path in archive.
 @param data File data to encode. Should not be nil or empty.
 @param path Path in arcvive. Example: `file.txt` or `dir/file.txt`, etc.
 @warning If `data` is nil -> assertion.
 @warning If `path` is nil -> assertion.
 @returns YES - stored and added, otherwice NO.
 */
- (BOOL) addData:(nonnull NSData *) data forPath:(nonnull NSString *) path;


/**
 @brief Open archive with `fileURL`.
 @warning Prev. path will be deleted.
 @param error Open error. Same error can be received via @b lastError property.
 */
- (BOOL) open:(NSError * _Nullable * _Nullable) error;


/**
 @brief Encode, e.g. compress all items to `fileURL`.
 @warning Call after all items are added and archive is opened.
 Can be called within separate thread.
 */
- (BOOL) write;

@end
