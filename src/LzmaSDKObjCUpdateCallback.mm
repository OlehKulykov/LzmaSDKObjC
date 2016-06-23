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


#include <Foundation/Foundation.h>

#import "LzmaSDKObjCUpdateCallback.h"
#include "../lzma/CPP/Common/Defs.h"
#include "../lzma/CPP/Windows/PropVariant.h"

#import "LzmaSDKObjCMutableItem.h"
#import "LzmaSDKObjCMutableItem+Private.h"
#import "LzmaSDKObjCItem+Private.h"

namespace LzmaSDKObjC
{
	class NSDataFileStream: public ISequentialInStream, public CMyUnknownImp {
	private:
		NSData * _data;
		NSUInteger _pos;
	public:
		MY_UNKNOWN_IMP1(ISequentialInStream)
		STDMETHOD(Read)(void *data, UInt32 size, UInt32 *processedSize);
		NSDataFileStream(NSData * data) : _data(data), _pos(0) { }
	};

	STDMETHODIMP NSDataFileStream::Read(void *data, UInt32 size, UInt32 *processedSize) {
		NSRange range = NSMakeRange(_pos, 0);
		if (size > 0) {
			const NSUInteger len = [_data length];
			const NSUInteger left = len > range.location ? len - range.location : 0;
			range.length = MIN(left, size);
			if (range.length) {
				_pos += range.length;
				[_data getBytes:data range:range];
			}
		}

		if (processedSize) *processedSize = (UInt32)range.length;
		return S_OK;
	}

	STDMETHODIMP UpdateCallback::SetTotal(UInt64 size) {
		_total = size;
		if (coder) coder->onProgress(0);
		return S_OK;
	}

	STDMETHODIMP UpdateCallback::SetCompleted(const UInt64 * completeValue) {
		if (completeValue && coder) {
			const long double complete = *completeValue;
			const float progress = (_total > 0) ? (float)(complete / _total) : 0;
			coder->onProgress(progress);
		}
		return S_OK;
	}

	STDMETHODIMP UpdateCallback::GetUpdateItemInfo(UInt32 index, Int32 *newData, Int32 *newProperties, UInt32 *indexInArchive) {
		if (newData) {
			*newData = BoolToInt(true);
		}

		if (newProperties) {
			*newProperties = BoolToInt(true);
		}

		if (indexInArchive) {
			*indexInArchive = (UInt32)(Int32)-1;
		}

		return S_OK;
	}

	STDMETHODIMP UpdateCallback::GetProperty(UInt32 index, PROPID propID, PROPVARIANT *value) {
		NSMutableArray * arr = (__bridge NSMutableArray *)items;
		LzmaSDKObjCMutableItem * item = (arr && index < [arr count]) ? [arr objectAtIndex:index] : nil;
		if (!item) return S_FALSE;

		NWindows::NCOM::CPropVariant prop;
		if (propID == kpidIsAnti)
		{
			prop = false;
			prop.Detach(value);
			return S_OK;
		}

	  switch (propID) {
		  case kpidPath: prop = UString((const wchar_t*)[item.path cStringUsingEncoding:NSUTF32LittleEndianStringEncoding]); break;
		  case kpidIsDir: prop = item.isDirectory ? true : false; break;
		  case kpidSize: prop = item->_orgSize; break;
//		  case kpidAttrib: prop = dirItem.Attrib; break;
		  case kpidCTime: prop = Common::UnixTimeToFILETIME(item->_cDate); break;
		  case kpidATime: prop = Common::UnixTimeToFILETIME(item->_aDate); break;
		  case kpidMTime: prop = Common::UnixTimeToFILETIME(item->_mDate); break;
	  }
		prop.Detach(value);
		return S_OK;
	}

	STDMETHODIMP UpdateCallback::GetStream(UInt32 index, ISequentialInStream **inStream) {
		NSMutableArray * arr = (__bridge NSMutableArray *)items;
		LzmaSDKObjCMutableItem * item = (arr && index < [arr count]) ? [arr objectAtIndex:index] : nil;
		if (!item) return S_FALSE;

		if (item.isDirectory) return S_OK;

		NSData * data = item.fileData;
		if (data) {
			NSDataFileStream * stream = new NSDataFileStream(data);
			CMyComPtr<ISequentialInStream> inStreamLoc(stream);
			*inStream = inStreamLoc.Detach();
			return S_OK;
		}

//		{
//			CInFileStream *inStreamSpec = new CInFileStream;
//			CMyComPtr<ISequentialInStream> inStreamLoc(inStreamSpec);
//			FString path = DirPrefix + dirItem.FullPath;
//			if (!inStreamSpec->Open(path))
//			{
//				DWORD sysError = ::GetLastError();
//				FailedCodes.Add(sysError);
//				FailedFiles.Add(path);
//				// if (systemError == ERROR_SHARING_VIOLATION)
//				{
//					PrintNewLine();
//					PrintError("WARNING: can't open file");
//					// PrintString(NError::MyFormatMessageW(systemError));
//					return S_FALSE;
//				}
//				// return sysError;
//			}
//			*inStream = inStreamLoc.Detach();
//		}
		return S_OK;
	}

	STDMETHODIMP UpdateCallback::SetOperationResult(Int32 operationResult) {
//		m_NeedBeClosed = true;
		return S_OK;
	}

	STDMETHODIMP UpdateCallback::GetVolumeSize(UInt32 index, UInt64 *size) {
//		if (VolumesSizes.Size() == 0)
//			return S_FALSE;
//		if (index >= (UInt32)VolumesSizes.Size())
//			index = VolumesSizes.Size() - 1;
//		*size = VolumesSizes[index];
		return S_OK;
	}

	STDMETHODIMP UpdateCallback::GetVolumeStream(UInt32 index, ISequentialOutStream **volumeStream) {
//		wchar_t temp[16];
//		ConvertUInt32ToString(index + 1, temp);
//		UString res = temp;
//		while (res.Len() < 2)
//			res.InsertAtFront(L'0');
//		UString fileName = VolName;
//		fileName += L'.';
//		fileName += res;
//		fileName += VolExt;
//		COutFileStream *streamSpec = new COutFileStream;
//		CMyComPtr<ISequentialOutStream> streamLoc(streamSpec);
//		if (!streamSpec->Create(us2fs(fileName), false))
//			return ::GetLastError();
//		*volumeStream = streamLoc.Detach();
		return S_OK;
	}

	STDMETHODIMP UpdateCallback::CryptoGetTextPassword(BSTR *password) {
		if (coder) {
			UString w(coder->onGetVoidCallback1());
			if (w.Len() > 0) return StringToBstr(w, password);
		}
		return S_OK;
	}

	STDMETHODIMP UpdateCallback::CryptoGetTextPassword2(Int32 *passwordIsDefined, BSTR *password) {
		if (passwordIsDefined) *passwordIsDefined = BoolToInt(false);
		if (coder) {
			UString w(coder->onGetVoidCallback1());
			if (w.Len() > 0) {
				if (passwordIsDefined) *passwordIsDefined = BoolToInt(true);
				return StringToBstr(w, password);
			}
		}
		return S_OK;
	}

	UpdateCallback::UpdateCallback() : LzmaSDKObjC::LastErrorHolder(),
		_total(0),
		items(NULL),
		coder(NULL)
	{
		
	}

	UpdateCallback::~UpdateCallback() {

	}
}
