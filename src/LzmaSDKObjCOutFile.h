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


#ifndef __LZMASDKOBJCOUTFILE_H__
#define __LZMASDKOBJCOUTFILE_H__

#include "LzmaAppleCommon.h"
#include "LzmaSDKObjCTypes.h"
#include "LzmaSDKObjCCommon.h"

#include "../lzma/CPP/Common/MyCom.h"
#include "../lzma/CPP/Common/MyString.h"
#include "../lzma/CPP/7zip/Common/FileStreams.h"
#include "../lzma/C/7zCrc.h"

#ifndef SAFE_FREE
#define SAFE_FREE(m) if(m){free(m);m=NULL;}
#endif

#ifndef SAFE_DELETE
#define SAFE_DELETE(o) if(o){delete o;o=NULL;}
#endif

namespace LzmaSDKObjC
{

	class OutFile :  public IOutStream, public CMyUnknownImp
	{
	private:
		FILE * _f;
		uint32_t _index;

	public:
		MY_UNKNOWN_IMP1(IOutStream)

		STDMETHOD(Write)(const void *data, UInt32 size, UInt32 *processedSize);
		STDMETHOD(Seek)(Int64 offset, UInt32 seekOrigin, UInt64 *newPosition);
		STDMETHOD(SetSize)(UInt64 newSize);

		uint32_t index() const { return _index; }
		void setIndex(uint32_t i) { _index = i; }
		bool open(const char * path);
		void close();

		OutFile();
		virtual ~OutFile();
	};

}

#endif 
