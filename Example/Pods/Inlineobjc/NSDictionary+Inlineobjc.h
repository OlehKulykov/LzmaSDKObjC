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


#ifndef __NSDICTIONARY_INLINEOBJC_H__
#define __NSDICTIONARY_INLINEOBJC_H__ 1

#if defined(DEBUG) || defined(_DEBUG)
#ifndef DEBUG
#define DEBUG 1
#endif
#endif


/**
 @brief Get text XML property list file data.
 @return Property list file data as XML version 1.0.
 */
NS_INLINE NSData * NSDictionaryGetPropertyListData(NSDictionary * dictionary)
{
	if (dictionary)
	{
#if defined(DEBUG)
		assert([dictionary isKindOfClass:[NSDictionary class]]);
#endif
		NSError * error = nil;
		NSData * res = [NSPropertyListSerialization dataWithPropertyList:dictionary
																  format:NSPropertyListXMLFormat_v1_0
																 options:0
																   error:&error];
		if (!error) return res;
	}
	return nil;
}

/**
 @brief Get binary property list file data.
 @return Binary property list file data.
 */
NS_INLINE NSData * NSDictionaryGetBinaryPropertyListData(NSDictionary * dictionary)
{
	if (dictionary)
	{
#if defined(DEBUG)
		assert([dictionary isKindOfClass:[NSDictionary class]]);
#endif
		NSError * error = nil;
		NSData * res = [NSPropertyListSerialization dataWithPropertyList:dictionary
																  format:NSPropertyListBinaryFormat_v1_0
																 options:0
																   error:&error];
		if (!error) return res;
	}
	return nil;
}


/**
 @brief Get dictionary from property list file data, XML or binary.
 @return Dictionary object or nil.
 */
NS_INLINE NSDictionary * NSDictionaryCreateWithPropertyListData(NSData * plistData)
{
	if (plistData)
	{
#if defined(DEBUG)
		assert([plistData isKindOfClass:[NSData class]]);
#endif
		NSError * error = nil;
		NSPropertyListFormat format = (NSPropertyListFormat)0;
		id res =  [NSPropertyListSerialization propertyListWithData:plistData
															options:0
															 format:&format
															  error:&error];
		if (!error && res)
		{
			return [res isKindOfClass:[NSDictionary class]] ? (NSDictionary *)res : nil;
		}
	}
	return nil;
}

#endif
