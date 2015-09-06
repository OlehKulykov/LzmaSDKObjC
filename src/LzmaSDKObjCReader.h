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
#include "LzmaSDKObjCCommon.h"

LZMASDKOBJC_EXTERN NSString * const kLzmaSDKObjCFileExt7z;

LZMASDKOBJC_EXTERN NSString * const kLzmaSDKObjCFileExtXz;

@class LzmaSDKObjCReader;

@protocol LzmaSDKObjCReaderDelegate <NSObject>

@optional
- (void) onLzmaSDKObjCReader:(LzmaSDKObjCReader *) reader
			 extractProgress:(float) progress;

@end


@interface LzmaSDKObjCReader : NSObject

@property (nonatomic, assign, readonly) LzmaSDKObjCFileType fileType;

@property (nonatomic, assign, readonly) NSURL * fileURL;

@property (nonatomic, assign, readonly) NSUInteger itemsCount;

@property (nonatomic, weak) id<LzmaSDKObjCReaderDelegate> delegate;

@property (nonatomic, copy) NSString * (^passwordGetter)(void);

- (id) initWithFileURL:(NSURL *) fileURL;

- (id) initWithFileURL:(NSURL *) fileURL andType:(LzmaSDKObjCFileType) type;

- (BOOL) open:(NSError **) error;

- (BOOL) iterateWithHandler:(BOOL(^)(LzmaSDKObjCItem * item, NSError * error)) handler;

- (BOOL) extract:(NSArray *) items
		  toPath:(NSString *) path
		 withFullPaths:(BOOL) isFullPaths;

@end


LZMASDKOBJC_EXTERN LzmaSDKObjCFileType LzmaSDKObjCDetectFileType(NSURL * fileURL);

