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


#include "LzmaSDKObjCFileEncoder.h"
#include "LzmaSDKObjCUpdateCallback.h"

#include "../lzma/CPP/7zip/Archive/DllExports2.h" // custom header with `STDAPI CreateObject(const GUID *clsid, const GUID *iid, void **outObject);`
#include "../lzma/CPP/7zip/Archive/IArchive.h"
#include "../lzma/CPP/7zip/IPassword.h"

namespace LzmaSDKObjC
{
	void FileEncoder::cleanUpdateCallbackRef() {
		CMyComPtr<IArchiveUpdateCallback2> updateCallback = _updateCallback;
		if (updateCallback != NULL && _updateCallbackRef) {
			_updateCallbackRef->coder = NULL;
		}

		_updateCallbackRef = NULL;
		_updateCallback.Release();
	}

	void FileEncoder::cleanOutFileStreamRef() {
		CMyComPtr<IOutStream> outFileStream = _outFileStream;
		if (outFileStream != NULL && _outFileStreamRef) {
			_outFileStreamRef->Close();
		}

		_outFileStreamRef = NULL;
		_outFileStream.Release();
	}

	bool FileEncoder::prepare(const LzmaSDKObjCFileType type) {
		this->clearLastError();
		if (type != LzmaSDKObjCFileType7z) {
			this->setLastError(E_ABORT, __LINE__, __FILE__, "Unsupported encoding type: %i", (int)type);
			return false;
		}
		createObject(type, &IID_IOutArchive, (void **)&_archive);
		return (_archive != NULL && this->lastError() == NULL);
	}

	bool FileEncoder::openFile(const char * path) {
		this->cleanOutFileStreamRef();
		this->cleanUpdateCallbackRef();
		this->clearLastError();

		_outFileStreamRef = new COutFileStream();
		if (!_outFileStreamRef) {
			this->setLastError(E_ABORT, __LINE__, __FILE__, "Can't create archive out stream object for path: %s", path);
			return false;
		}

		_outFileStream = CMyComPtr<IOutStream>(_outFileStreamRef);
		if (!_outFileStreamRef->Create(path, false)) {
			this->setLastError(E_ABORT, __LINE__, __FILE__, "Can't create archive out file for path: %s", path);
			return false;
		}

		_updateCallbackRef = new LzmaSDKObjC::UpdateCallback();
		if (!_updateCallbackRef) {
			this->setLastError(E_ABORT, __LINE__, __FILE__, "Can't create archive update callback object for path: %s", path);
			return false;
		}

		_updateCallback = CMyComPtr<IArchiveUpdateCallback2>(_updateCallbackRef);

		const wchar_t *names[] = {
			L"s",
			L"x"
		};
		NWindows::NCOM::CPropVariant values[2] = {
			solid,    // solid mode ON
			(UInt32)compressionLevel // compression level = 9 - ultra
		};
		CMyComPtr<ISetProperties> setProperties;
		_archive->QueryInterface(IID_ISetProperties, (void **)&setProperties);
		if (!setProperties) {
			//			 PrintError("ISetProperties unsupported");
			return 1;
		}

		int res = setProperties->SetProperties(names, values, 2);

		return true;
	}

	bool FileEncoder::encodeItems(void * items, const uint32_t numItems) {
		this->clearLastError();
		if (_updateCallbackRef) {
			_updateCallbackRef->clearLastError();
			_updateCallbackRef->items = items;
			_updateCallbackRef->coder = this;
			const HRESULT result = _archive->UpdateItems(_outFileStream, numItems, _updateCallback);
			if (result == S_OK) return true;
			this->setLastError(_updateCallbackRef);
		}
		return S_FALSE;
	}

	FileEncoder::FileEncoder() : LzmaSDKObjC::BaseCoder(),
		_updateCallbackRef(NULL),
		_outFileStreamRef(NULL),
		solid(true),
		compressionLevel(5)
	{
		
	}
	
	FileEncoder::~FileEncoder()
	{
		this->cleanOutFileStreamRef();
		this->cleanUpdateCallbackRef();
	}
}
