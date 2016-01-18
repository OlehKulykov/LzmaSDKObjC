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


#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <CoreGraphics/CoreGraphics.h>


#ifndef __UIIMAGE_INLINEOBJC_H__
#define __UIIMAGE_INLINEOBJC_H__ 1

#if defined(DEBUG) || defined(_DEBUG)
#ifndef DEBUG
#define DEBUG 1
#endif
#endif


/**
 @brief Creates and return image filled with specific color.
 @param color Color of the image.
 @param size Size of the new image.
 @param opaque Flag indicating whether the image is opaque.
 @result Image object or nil. Nil will be returned on negative/null size, empty color or on error.
 */
NS_INLINE UIImage * UIImageCreateWithColorSizeAndOpaqueness(UIColor * color, const CGSize size, BOOL opaque)
{
	if (color && size.width > 0 && size.height > 0)
	{
#if defined(DEBUG)
		assert([color isKindOfClass:[UIColor class]]);
#endif
		const CGRect resultImageRect = CGRectMake(0.0f, 0.0f, size.width, size.height);
		UIGraphicsBeginImageContextWithOptions(size, opaque, [[UIScreen mainScreen] scale]);
		CGContextRef resultImageContext = UIGraphicsGetCurrentContext();

		CGContextSetFillColorWithColor(resultImageContext, [color CGColor]);
		CGContextFillRect(resultImageContext, resultImageRect);

		UIImage * image = UIGraphicsGetImageFromCurrentImageContext();
		UIGraphicsEndImageContext();
		return image;
	}
	return nil;
}


/**
 @brief Creates and return opaque image filled with specific color.
 @param color Color of the image.
 @param size Size of the new image.
 @result Image object or nil. Nil will be returned on negative/null size, empty color or on error.
 */
NS_INLINE UIImage * UIImageCreateWithColorAndSize(UIColor * color, const CGSize size)
{
	return UIImageCreateWithColorSizeAndOpaqueness(color, size, YES);
}

#endif

