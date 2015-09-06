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


#ifndef __LZMASDKOBJCCOMMON_H__
#define __LZMASDKOBJCCOMMON_H__

#include "LzmaSDKObjCTypes.h"

/**
 @detailed
 - CFilterCoder allocate buff for reading, was (1 << 20)
 - ISequentialOutStream max read block size, or available size, was (1 << 31)
 */
LZMASDKOBJC_EXTERN unsigned int kLzmaSDKObjCStreamReadSize;


/**
 @detailed
 - ISequentialOutStream max write block size, or available size, was (1 << 31)
 */
LZMASDKOBJC_EXTERN unsigned int kLzmaSDKObjCStreamWriteSize;


/**
 @detailed
 - Lzma CDecoder in buffer, buff with coded data, was (1 << 20)
 - Lzma2 CDecoder in buffer, buff with coded data, was (1 << 20)
 */
LZMASDKOBJC_EXTERN unsigned int kLzmaSDKObjCDecoderReadSize;


/**
 @detailed
 - Lzma CDecoder out buffer, buff for decoded data, was (1 << 22)
 - Lzma2 CDecoder out buffer, buff for decoded data, was (1 << 22)
 */
LZMASDKOBJC_EXTERN unsigned int kLzmaSDKObjCDecoderWriteSize;


#endif
