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
#include <zlib.h>

#ifndef __NSDATA_INLINEOBJCZIP_H__
#define __NSDATA_INLINEOBJCZIP_H__ 1

#if defined(DEBUG) || defined(_DEBUG)
#ifndef DEBUG
#define DEBUG 1
#endif
#endif


/**
 @brief Get zip compressed data with compression ratio.
 @detailed Need to add dependecy of the zlib library.
 @param dataToCompress The data for compress.
 @param compressionRatio Float compression ratio value in range [0.0f; 1.0f].
 @return Zip compressed data or nil on error or dataToCompress is empty.
 */
NS_INLINE NSData * NSDataGetZipCompressDataWithRatio(NSData * dataToCompress, const CGFloat compressionRatio)
{
	if (!dataToCompress) return nil;

#if defined(DEBUG)
	assert([dataToCompress isKindOfClass:[NSData class]]);
#endif

	z_stream zipStream = { 0 };
	zipStream.avail_in = (uInt)[dataToCompress length];

	if (zipStream.avail_in == 0) return nil;

	zipStream.next_in = (Bytef *)[dataToCompress bytes];

	const uInt outBufferSize = 32 * 1024;
	Bytef outBuffer[outBufferSize];
	zipStream.next_out = outBuffer;
	zipStream.avail_out = outBufferSize;

	if (compressionRatio < 0.0f) deflateInit(&zipStream, Z_NO_COMPRESSION);
	else if (compressionRatio > 1.0f) deflateInit(&zipStream, Z_BEST_COMPRESSION);
	else deflateInit(&zipStream, (int)(compressionRatio * 9.0f));

	NSMutableData * compressedBuffer = [NSMutableData data];
	while (zipStream.avail_in != 0)
	{
		if (deflate(&zipStream, Z_NO_FLUSH) != Z_OK)
		{
			deflateEnd(&zipStream);
			return nil;
		}
		if (zipStream.avail_out == 0)
		{
			const NSUInteger len = [compressedBuffer length];
			[compressedBuffer appendBytes:outBuffer length:outBufferSize];
			if ((len + outBufferSize) != [compressedBuffer length])
			{
				deflateEnd(&zipStream);
				return nil;
			}
			zipStream.next_out = outBuffer;
			zipStream.avail_out = outBufferSize;
		}
	}

	int result = Z_OK;
	while (result == Z_OK)
	{
		if (zipStream.avail_out == 0)
		{
			const NSUInteger len = [compressedBuffer length];
			[compressedBuffer appendBytes:outBuffer length:outBufferSize];
			if ((len + outBufferSize) != [compressedBuffer length])
			{
				deflateEnd(&zipStream);
				return nil;
			}
			zipStream.next_out = outBuffer;
			zipStream.avail_out = outBufferSize;
		}
		result = deflate(&zipStream, Z_FINISH);
	}

	if (result != Z_STREAM_END)
	{
		deflateEnd(&zipStream);
		return nil;
	}

	const NSUInteger len = [compressedBuffer length];
	[compressedBuffer appendBytes:outBuffer length:outBufferSize - zipStream.avail_out];
	if ((len + outBufferSize - zipStream.avail_out) != [compressedBuffer length])
	{
		deflateEnd(&zipStream);
		return nil;
	}

	deflateEnd(&zipStream);
	return compressedBuffer;
}


/**
 @brief Get zip decompressed data.
 @detailed Need to add dependecy of the zlib library.
 @param zipData Zip compressed data.
 @return Decompressed data or nil on error or data is not zip compressed.
 */
NS_INLINE NSData * NSDataGetZipDecompressData(NSData * zipData)
{
	if (!zipData) return nil;
#if defined(DEBUG)
	assert([zipData isKindOfClass:[NSData class]]);
#endif

	z_stream zipStream = { 0 };
	zipStream.avail_in = (uInt)[zipData length];

	if (zipStream.avail_in == 0) return nil;

	zipStream.next_in = (Bytef *)[zipData bytes];

	int result = inflateInit(&zipStream);
	if (result != Z_OK) return nil;

	const uInt outBuffSize = 32 * 1024;
	Bytef outBuff[outBuffSize];
	NSMutableData * unCompressedData = [NSMutableData data];
	do
	{
		zipStream.avail_out = outBuffSize;
		zipStream.next_out = outBuff;

		result = inflate(&zipStream, Z_NO_FLUSH);
		if (result == Z_STREAM_ERROR)
		{
			inflateEnd(&zipStream);
			return nil;
		}
		switch (result)
		{
			case Z_NEED_DICT:
				result = Z_DATA_ERROR;
			case Z_DATA_ERROR:
			case Z_MEM_ERROR:
				inflateEnd(&zipStream);
				return nil;
		}
		const int haveSize = outBuffSize - zipStream.avail_out;
		if (haveSize > 0)
		{
			const NSUInteger len = [unCompressedData length];
			[unCompressedData appendBytes:outBuff length:haveSize];
			if ((len + haveSize) != [unCompressedData length])
			{
				inflateEnd(&zipStream);
				return nil;
			}
		}
		else
		{
			inflateEnd(&zipStream);
			return nil;
		}
	} while (zipStream.avail_out == 0);

	inflateEnd(&zipStream);
	if (result == Z_STREAM_END) return unCompressedData;

	return nil;
}

#endif

