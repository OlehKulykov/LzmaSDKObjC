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


#include "LzmaSDKObjCFileDecoder.h"

#include "../lzma/CPP/Common/MyWindows.h"
#include "../lzma/CPP/Common/Defs.h"
#include "../lzma/CPP/Common/MyGuidDef.h"
#include "../lzma/CPP/Common/IntToString.h"
#include "../lzma/CPP/Common/StringConvert.h"

#include "../lzma/CPP/Windows/DLL.h"
#include "../lzma/CPP/Windows/FileDir.h"
#include "../lzma/CPP/Windows/FileFind.h"
#include "../lzma/CPP/Windows/FileName.h"
#include "../lzma/CPP/Windows/NtCheck.h"
#include "../lzma/CPP/Windows/PropVariant.h"
#include "../lzma/CPP/Windows/PropVariantConv.h"

#include "../lzma/CPP/7zip/Common/FileStreams.h"
#include "../lzma/CPP/7zip/Archive/IArchive.h"
#include "../lzma/CPP/7zip/IPassword.h"

#include "../lzma/C/7zVersion.h"
#include "../lzma/C/7zCrc.h"
#include "../lzma/C/Aes.h"
#include "../lzma/C/XzCrc64.h"

#include "LzmaSDKObjCCommon.h"
#include "LzmaSDKObjCInFile.h"
#include "LzmaSDKObjCOpenCallback.h"
#include "LzmaSDKObjCOutFile.h"
#include "LzmaSDKObjCExtractCallback.h"

STDAPI CreateObject(const GUID *clsid, const GUID *iid, void **outObject);

namespace LzmaSDKObjC
{

	bool FileDecoder::process(const uint32_t * itemsIndices,
							  const uint32_t itemsCount,
							  const char * path /* = NULL */,
							  bool isWithFullPaths /* = false */)
	{
		this->cleanExtractCallbackRef();

		LzmaSDKObjC::ExtractCallback * extractCallback = new LzmaSDKObjC::ExtractCallback();
		if (!extractCallback) return false;

		if (path)
		{
			if (!extractCallback->prepare(path, isWithFullPaths)) return false;
		}
		else
		{
			extractCallback->setIsTest(true);
		}

		_extractCallbackRef = extractCallback;
		extractCallback->setCoder(this);
		extractCallback->setArchive(_archive);

		_extractCallback = extractCallback;

		const HRESULT result = _archive->Extract(itemsIndices, itemsCount, false, _extractCallback);
		extractCallback->setArchive(NULL);

		if (result == S_OK)
		{
			DEBUG_LOG("Extract OK")
		}
		else
		{
			DEBUG_LOG("Extract Error")
		}

		return (result == S_OK);
	}

	bool FileDecoder::readIteratorProperty(PROPVARIANT * property, const uint32_t identifier)
	{
		return (_iterateIndex < _itemsCount) ? (_archive->GetProperty(_iterateIndex, identifier, property) == S_OK) : false;
	}

	bool FileDecoder::openFile(const char * path)
	{
		this->cleanOpenCallbackRef();

		LzmaSDKObjC::InFile * inFile = new LzmaSDKObjC::InFile();
		if (!inFile) return false;
		_inFile = inFile;

		LzmaSDKObjC::OpenCallback * openCallback = new LzmaSDKObjC::OpenCallback();
		if (!openCallback) return false;
		_openCallbackRef = openCallback;
		openCallback->setCoder(this);
		_openCallback = openCallback;

		if (!inFile->open(path)) return false;
		if (_archive->Open(_inFile, 0, _openCallback) == S_OK)
		{
			UInt32 numItems = 0;
			if (_archive->GetNumberOfItems(&numItems) != S_OK) return false;
			_itemsCount = numItems;
			return true;
		}
		return false;
	}

	bool FileDecoder::findCodec(const LzmaSDKObjCFileType type)
	{
		if (type)
		{
			const GUID * clsid = NULL;
			switch (type)
			{
				case LzmaSDKObjCFileType7z: clsid = &LzmaSDKObjCCLSIDFormat7z; break;
				case LzmaSDKObjCFileTypeXz: clsid = &LzmaSDKObjCCLSIDFormatXz; break;
				default: return false; break;
			}
			if (CreateObject(clsid, &IID_IInArchive, (void **)&_archive) != S_OK) return false;
			return (_archive != NULL);
		}
		return false;
	}

	uint32_t FileDecoder::itemsCount() const { return _itemsCount; }
	void FileDecoder::iterateStart() { _iterateIndex = 0; }
	bool FileDecoder::iterateNext() { return (++_iterateIndex < _itemsCount); }
	uint32_t FileDecoder::iteratorIndex() const { return _iterateIndex; };

	void FileDecoder::onExtractProgress(const float progress)
	{
		if (context && setFloatCallback2) setFloatCallback2(context, progress);
		DEBUG_LOG("FileDecoder::onExtractProgress = %f", progress)
	}

	UString FileDecoder::onGetVoidCallback1()
	{
		wchar_t * w = (context && getVoidCallback1) ? (wchar_t *)getVoidCallback1(context) : NULL;
		UString r;
		if (w) { r = w; free(w); }
		return r;
	}

	static char _isOneTimeStaticInitialized = 0;
	static void _oneTimeStaticInitializer()
	{
		if (_isOneTimeStaticInitialized) return;
		_isOneTimeStaticInitialized = 1;
		CrcGenerateTable();
		AesGenTables();
		Crc64GenerateTable();
	}

	FileDecoder::FileDecoder() :
		_openCallbackRef(NULL),
		_extractCallbackRef(NULL),
		_itemsCount(0),
		_iterateIndex(0),
		context(NULL),
		getVoidCallback1(NULL),
		setFloatCallback2(NULL)
	{
		_oneTimeStaticInitializer();
	}

	void FileDecoder::cleanOpenCallbackRef()
	{
		CMyComPtr<IArchiveOpenCallback> op = _openCallback;
		if (op != NULL)
		{
			// pointer exists & retained localy 'op', can use actual class ref.
			LzmaSDKObjC::OpenCallback * o = (LzmaSDKObjC::OpenCallback *)_openCallbackRef;
			if (o) o->setCoder(NULL);
		}

		_openCallbackRef = NULL;
		_openCallback.Release();
	}

	void FileDecoder::cleanExtractCallbackRef()
	{
		CMyComPtr<IArchiveExtractCallback> ep = _extractCallback;
		if (ep != NULL)
		{
			// pointer exists & retained localy 'op', can use actual class ref.
			LzmaSDKObjC::ExtractCallback * e = (LzmaSDKObjC::ExtractCallback *)_extractCallbackRef;
			if (e) e->setCoder(NULL);
		}

		_extractCallbackRef = NULL;
		_extractCallback.Release();
	}

	FileDecoder::~FileDecoder()
	{
		this->cleanOpenCallbackRef();
		this->cleanExtractCallbackRef();
	}

}



