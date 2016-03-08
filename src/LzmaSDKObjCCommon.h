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


#ifndef __LZMASDKOBJCCOMMON_H__
#define __LZMASDKOBJCCOMMON_H__

#include <stdio.h>

#include "../lzma/CPP/Common/MyGuidDef.h"
#include "../lzma/CPP/Common/MyWindows.h"
#include "LzmaSDKObjCTypes.h"

LZMASDKOBJC_EXTERN const GUID LzmaSDKObjCCLSIDFormat7z;

LZMASDKOBJC_EXTERN const GUID LzmaSDKObjCCLSIDFormatXz;

LZMASDKOBJC_EXTERN uint64_t LzmaSDKObjCPROPVARIANTGetUInt64(PROPVARIANT * prop);

LZMASDKOBJC_EXTERN bool LzmaSDKObjCPROPVARIANTGetBool(PROPVARIANT * prop);

LZMASDKOBJC_EXTERN time_t LzmaSDKObjCFILETIMEToUnixTime(const FILETIME filetime);

#endif 
