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


#ifndef __LZMASDKOBJCFILEDECODER_H__
#define __LZMASDKOBJCFILEDECODER_H__

#include "LzmaAppleCommon.h"
#include "LzmaSDKObjCTypes.h"

#include "../lzma/CPP/7zip/Archive/IArchive.h"
#include "../lzma/CPP/7zip/IPassword.h"
#include "../lzma/CPP/Common/MyCom.h"
#include "../lzma/CPP/Common/MyString.h"
#include "../lzma/CPP/Windows/PropVariant.h"

#include "LzmaSDKObjCICoder.h"

namespace LzmaSDKObjC
{
	class FileDecoder : public LzmaSDKObjC::ICoder
	{
	private:
		void * _openCallbackRef;
		void * _extractCallbackRef;

		CMyComPtr<IInArchive> _archive;
		CMyComPtr<IInStream> _inFile;
		CMyComPtr<IArchiveOpenCallback> _openCallback;
		CMyComPtr<IArchiveExtractCallback> _extractCallback;

		uint32_t _itemsCount;
		uint32_t _iterateIndex;

		void cleanOpenCallbackRef();
		void cleanExtractCallbackRef();

	public:
		void * context;
		LzmaSDKObjCGetVoidCallback getVoidCallback1;
		LzmaSDKObjCSetFloatCallback setFloatCallback2;

		uint32_t itemsCount() const;
		void iterateStart();
		bool iterateNext();
		uint32_t iteratorIndex() const;

		bool readIteratorProperty(PROPVARIANT * property, const uint32_t identifier);

		bool extract(const uint32_t * itemsIndices,
					 const uint32_t itemsCount,
					 const char * path,
					 bool isWithFullPaths);

		bool findCodec(const LzmaSDKObjCFileType type);
		bool openFile(const char * path);

		// LzmaObjc::ICoder
		virtual void onExtractProgress(const float progress);
		virtual UString onGetVoidCallback1();

		FileDecoder();
		virtual ~FileDecoder();
	};
}

#endif 
