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


#include "LzmaSDKObjCOpenCallback.h"


namespace LzmaSDKObjC
{

	STDMETHODIMP OpenCallback::SetTotal(const UInt64 * files, const UInt64 * bytes)
	{
		LZMASDK_DEBUG_LOG("OpenCallback::SetTotal")
		return S_OK;
	}

	STDMETHODIMP OpenCallback::SetCompleted(const UInt64 * files, const UInt64 * bytes)
	{
		LZMASDK_DEBUG_LOG("OpenCallback::SetCompleted")
		return S_OK;
	}

	STDMETHODIMP OpenCallback::CryptoGetTextPassword(BSTR *password)
	{
		LZMASDK_DEBUG_LOG("OpenCallback::CryptoGetTextPassword")
		if (_coder)
		{
			UString w = _coder->onGetVoidCallback1();
			if (w.Len() > 0) return StringToBstr(w, password);
		}
		this->setLastError(E_ABORT, __LINE__, __FILE__, "Password is required, but there is no coder or password is empty");
		return E_ABORT;
	}

	STDMETHODIMP OpenCallback::CryptoGetTextPassword2(Int32 *passwordIsDefined, BSTR *password)
	{
		LZMASDK_DEBUG_LOG("OpenCallback::CryptoGetTextPassword2")

		if (passwordIsDefined) *passwordIsDefined = 0;
		if (_coder)
		{
			UString w = _coder->onGetVoidCallback1();
			if (w.Len() > 0)
			{
				if (passwordIsDefined) *passwordIsDefined = 1;
				return StringToBstr(w, password);
			}
		}
		this->setLastError(E_ABORT, __LINE__, __FILE__, "Password is required, but there is no coder or password is empty");
		return E_ABORT;
	}

	OpenCallback::OpenCallback() : LzmaSDKObjC::LastErrorHolder(),
		_coder(NULL)
	{

	}
	
	OpenCallback::~OpenCallback()
	{

	}
	
}

