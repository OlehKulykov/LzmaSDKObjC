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
		createObject(type, &IID_IOutArchive, (void **)&_archive);
		return (_archive != NULL && this->lastError() == NULL);
	}

	bool FileEncoder::openFile(const char * path) {
		this->cleanOutFileStreamRef();
		this->cleanUpdateCallbackRef();
		
		_outFileStreamRef = new COutFileStream();
		_outFileStream = CMyComPtr<IOutStream>(_outFileStreamRef);
		if (!_outFileStreamRef->Create(path, false)) {
//			PrintError("can't create archive file");
			return false;
		}

		_updateCallbackRef = new LzmaSDKObjC::UpdateCallback();
		_updateCallback = CMyComPtr<IArchiveUpdateCallback2>(_updateCallbackRef);

		return true;
	}

	bool FileEncoder::encodeItems(void * items, const UInt32 numItems) {
		if (_updateCallbackRef) {
			_updateCallbackRef->items = items;
			_updateCallbackRef->coder = this;
			const HRESULT result = _archive->UpdateItems(_outFileStream, numItems, _updateCallback);
			return result == S_OK;
		}
		return S_FALSE;
	}

	FileEncoder::FileEncoder() : LzmaSDKObjC::BaseCoder(),
		_updateCallbackRef(NULL),
		_outFileStreamRef(NULL)
	{
		
	}
	
	FileEncoder::~FileEncoder()
	{
		this->cleanOutFileStreamRef();
		this->cleanUpdateCallbackRef();
	}
}
