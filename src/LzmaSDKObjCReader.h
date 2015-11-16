/*
 *   Copyright (c) 2015 Kulykov Oleh <info@resident.name>
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


#import <Foundation/Foundation.h>

#include "LzmaSDKObjCTypes.h"
#include "LzmaSDKObjCItem.h"
#include "LzmaSDKObjC.h"

/**
 @brief Lower case string of the 7zip file extension.
 @return 7z.
 */
LZMASDKOBJC_EXTERN NSString * const _Nonnull kLzmaSDKObjCFileExt7z;


/**
 @brief Lower case string of the Xz file extension.
 @return xz.
 */
LZMASDKOBJC_EXTERN NSString * const _Nonnull kLzmaSDKObjCFileExtXz;


/**
 @brief Error domain for the reader errors.
 */
LZMASDKOBJC_EXTERN NSString * const _Nonnull kLzmaSDKObjCErrorDomain;


@class LzmaSDKObjCReader;


/**
 @brief Reader delegate. All methods is optional & called from main thread.
 */
@protocol LzmaSDKObjCReaderDelegate <NSObject>

@optional
/**
 @brief Reports extract progress of file(s). Called after all internal buffers was writed.
 Quality depends on size of the kLzmaSDKObjCStreamWriteSize, kLzmaSDKObjCDecoderWriteSize.
 @param progress Extract progress [0.0; 1.0]
 */
- (void) onLzmaSDKObjCReader:(nonnull LzmaSDKObjCReader *) reader
			 extractProgress:(float) progress;

@end


/**
 @brief Lzma file reader/extractor.
 */
@interface LzmaSDKObjCReader : NSObject

/**
 @brief Type of the assigned archive.
 */
@property (nonatomic, assign, readonly) LzmaSDKObjCFileType fileType;


/**
 @brief URL to the archive file. 
 */
@property (nonatomic, strong, readonly) NSURL * _Nullable fileURL;


/**
 @brief Number of the archive items.
  @warning Available only after open archive.
 */
@property (nonatomic, assign, readonly) NSUInteger itemsCount;


/**
 @brief Archive reader delegate.
 */
@property (nonatomic, weak) id<LzmaSDKObjCReaderDelegate> delegate;


/**
 @brief Getter to the archive password.
 */
@property (nonatomic, copy) NSString * _Nullable (^ _Nullable passwordGetter)(void);


/**
 @brief Initialize archive with file url.
 Type detected from archive file extension.
 */
- (nonnull id) initWithFileURL:(nonnull NSURL *) fileURL;


/**
 @brief Initialize archive with file url with archive type.
 */
- (nonnull id) initWithFileURL:(nonnull NSURL *) fileURL andType:(LzmaSDKObjCFileType) type;


/**
 @brief Opens archive.
 @param error Open error.
 */
- (BOOL) open:(NSError * _Nullable * _Nullable) error;


/**
 @brief Iterate thought all archive items. 
 Items created during iterating, so track, filter & store for extracting.
 */
- (BOOL) iterateWithHandler:(BOOL(^ _Nonnull)(LzmaSDKObjCItem * _Nonnull item, NSError * _Nullable error)) handler;


/**
 @brief Extracts array of items stored during iterating.
 @param items Array with LzmaSDKObjCItem objects.
 @param path Path to extract provided items.
 @param isFullPaths Create directory structure for the file items(YES) or store all files to extract path(NO).
 In case of just store to path, files with the same names will rewrite automaticaly.
 */
- (BOOL) extract:(nullable NSArray *) items
		  toPath:(nullable NSString *) path
		 withFullPaths:(BOOL) isFullPaths;


/**
 @brief Test archive items. Calculates CRC & compare with header value.
 @param items Array with LzmaSDKObjCItem objects.
 */
- (BOOL) test:(nullable NSArray *) items;

@end


/**
 @brief Get archive type from path by it's extension.
 Using kLzmaSDKObjCFileExt7z & kLzmaSDKObjCFileExtXz.
 */
LZMASDKOBJC_EXTERN LzmaSDKObjCFileType LzmaSDKObjCDetectFileType(NSURL * _Nullable fileURL);

