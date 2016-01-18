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

#ifndef __UICOLOR_INLINEOBJC_H__
#define __UICOLOR_INLINEOBJC_H__ 1

#if defined(DEBUG) || defined(_DEBUG)
#ifndef DEBUG
#define DEBUG 1
#endif
#endif


/**
 @brief Structure for holding color RGBA components.
 @detailed Each RGBA component stored as 8 bit unsigned integer at the same time as 4 dimension array of the 8 bit components and one single unsigned 32 bit integer.
 */
typedef struct _rgbaByteColor
{
	/**
	 @brief 32 bit union with RGBA components, components array and one single value.
	 */
	union
	{
		/**
		 @brief Structure for holding color RGBA components as 8 bit unsigned integer.
		 */
		struct
		{
			uint8_t red;
			uint8_t green;
			uint8_t blue;
			uint8_t alpha;
		};
		
		
		/**
		 @brief 4 dimension array of the 8 bit RGBA components.
		 */
		uint8_t rgba[4];
		
		
		/**
		 @brief 32 bit unsigned integer representation of the color.
		 */
		uint32_t value;
	};
} 
/**
 @brief Name of the structure for holding color RGBA components.
 */
RGBAByteColor;


/**
 @brief Compare two color structures.
 @detailed Compare two color structures by them 32 bit unsigned integer representation.
 */
NS_INLINE BOOL RGBAByteColorsIsEqual(const RGBAByteColor c1, const RGBAByteColor c2)
{
	return (c1.value == c2.value);
}


/**
 @brief Create color structure from RGB components.
 @detailed Create color structure from 8 bit unsigned integer RGB components.
 @param red The red 8 bit unsigned integer component of the color [0; 255].
 @param green The green 8 bit unsigned integer component of the color [0; 255].
 @param blue The blue 8 bit unsigned integer component of the color [0; 255].
 @result New color structure with alpha value 255.
 */
NS_INLINE RGBAByteColor RGBAByteColorMakeWithRGBBytes(const uint8_t red,
													  const uint8_t green,
													  const uint8_t blue)
{
	RGBAByteColor c;
	c.red = red;
	c.green = green;
	c.blue = blue;
	c.alpha = 255;
	return c;
}


/**
 @brief Create color structure from RGBA components.
 @detailed Create color structure from 8 bit unsigned integer RGBA components.
 @param red The red 8 bit unsigned integer component of the color [0; 255].
 @param green The green 8 bit unsigned integer component of the color [0; 255].
 @param blue The blue 8 bit unsigned integer component of the color [0; 255].
 @param alpha The alpha 8 bit unsigned integer component of the color [0; 255].
 @result New color structure.
 */
NS_INLINE RGBAByteColor RGBAByteColorMakeWithRGBABytes(const uint8_t red,
													   const uint8_t green,
													   const uint8_t blue,
													   const uint8_t alpha)
{
	RGBAByteColor c;
	c.red = red;
	c.green = green;
	c.blue = blue;
	c.alpha = alpha;
	return c;
}


/**
 @brief Create color structure from RGB components.
 @detailed Create color structure from float RGB components.
 @param red The red float component of the color [0.0f; 1.0f].
 @param green The green float component of the color [0.0f; 1.0f].
 @param blue The blue float component of the color [0.0f; 1.0f].
 @result New color structure with alpha value 255.
 */
NS_INLINE RGBAByteColor RGBAByteColorMakeWithRGB(const CGFloat red,
												 const CGFloat green,
												 const CGFloat blue)
{
	RGBAByteColor c;
	c.red = (uint8_t)(red * 255);
	c.green = (uint8_t)(green * 255);
	c.blue = (uint8_t)(blue * 255);
	c.alpha = 255;
	return c;
}


/**
 @brief Create color structure from RGBA components.
 @detailed Create color structure from float RGBA components. Each component is float value.
 @param red The red float component of the color [0.0f; 1.0f].
 @param green The green float component of the color [0.0f; 1.0f].
 @param blue The blue float component of the color [0.0f; 1.0f].
 @param alpha The alpha float component of the color [0.0f; 1.0f].
 @result New color structure with alpha value 255.
 */
NS_INLINE RGBAByteColor RGBAByteColorMakeWithRGBA(const CGFloat red,
												  const CGFloat green,
												  const CGFloat blue,
												  const CGFloat alpha)
{
	RGBAByteColor c;
	c.red = (uint8_t)(red * 255);
	c.green = (uint8_t)(green * 255);
	c.blue = (uint8_t)(blue * 255);
	c.alpha = (uint8_t)(alpha * 255);
	return c;
}


/**
 @brief Create color object from RGB components.
 @detailed Create color object from 8 bit unsigned integer RGB components.
 @param red The red 8 bit unsigned integer component of the color [0; 255].
 @param green The green 8 bit unsigned integer component of the color [0; 255].
 @param blue The blue 8 bit unsigned integer component of the color [0; 255].
 @result New color object.
 */
NS_INLINE UIColor * UIColorMakeWithRGB(uint8_t red,
									   uint8_t green,
									   uint8_t blue)
{
	return [UIColor colorWithRed:((CGFloat)red / 255.0)
						   green:((CGFloat)green / 255.0)
							blue:((CGFloat)blue / 255.0)
						   alpha:1.0];
}


/**
 @brief Create color object from RGBA components.
 @detailed Create color object from 8 bit unsigned integer RGBA components.
 @param red The red 8 bit unsigned integer component of the color [0; 255].
 @param green The green 8 bit unsigned integer component of the color [0; 255].
 @param blue The blue 8 bit unsigned integer component of the color [0; 255].
 @param alpha The alpha 8 bit unsigned integer component of the color [0; 255].
 @result New color object.
 */
NS_INLINE UIColor * UIColorMakeWithRGBA(uint8_t red,
										uint8_t green,
										uint8_t blue,
										uint8_t alpha)
{
	return [UIColor colorWithRed:((CGFloat)red / 255.0)
						   green:((CGFloat)green / 255.0)
							blue:((CGFloat)blue / 255.0)
						   alpha:((CGFloat)alpha / 255.0)];
}


/**
 @brief Create color object from HEX string.
 @param hexString The color HEX string with format: @"FF00FF" or @"#FF00FF". Case is ignored.
 @result New color object.
 */
NS_INLINE UIColor * UIColorMakeWithHexString(NSString * hexString)
{
	if (hexString)
	{
#if defined(DEBUG)
		assert([hexString isKindOfClass:[NSString class]]);
#endif
		const char * formatString = NULL;
		switch ([hexString length])
		{
			case 6: formatString = "%2x%2x%2x"; break;
			case 7: formatString = "#%2x%2x%2x"; break;
			default: break;
		}
		if (formatString)
		{
			unsigned int r, g, b;
			const int readed = sscanf([[hexString lowercaseString] UTF8String], formatString, &r, &g, &b);
			if (readed == 3)
			{
				return [UIColor colorWithRed:(r < 255) ? (CGFloat)r / 255.0 : 1.0
									   green:(g < 255) ? (CGFloat)g / 255.0 : 1.0
										blue:(b < 255) ? (CGFloat)b / 255.0 : 1.0
									   alpha:1.0];
			}
		}
	}
	return nil;
}

#endif

