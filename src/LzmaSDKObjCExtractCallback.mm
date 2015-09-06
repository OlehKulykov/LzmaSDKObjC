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

#include <Foundation/Foundation.h>
#include "LzmaSDKObjCExtractCallback.h"
#include "../lzma/CPP/Windows/PropVariant.h"

namespace LzmaSDKObjC
{
	STDMETHODIMP ExtractCallback::ReportExtractResult(UInt32 indexType, UInt32 index, Int32 opRes)
	{
		DEBUG_LOG("ExtractCallback::ReportExtractResult")

		return S_OK;
	}

	STDMETHODIMP ExtractCallback::SetRatioInfo(const UInt64 *inSize, const UInt64 *outSize)
	{
		DEBUG_LOG("ExtractCallback::SetRatioInfo")
		return S_OK;
	}

	STDMETHODIMP ExtractCallback::SetTotal(UInt64 size)
	{
		_total = size;
		if (_coder) _coder->onExtractProgress(0);
		DEBUG_LOG("ExtractCallback::SetTotal = %llu", _total)
		return S_OK;
	}

	STDMETHODIMP ExtractCallback::SetCompleted(const UInt64 * completeValue)
	{
		if (completeValue)
		{
			const long double complete = *completeValue;
			const float progress = (_total > 0) ? (float)(complete / _total) : 0;
			if (_coder) _coder->onExtractProgress(progress);
		}
		DEBUG_LOG("ExtractCallback::SetCompleted = %llu", *completeValue)
		return S_OK;
	}

	STDMETHODIMP ExtractCallback::GetStream(UInt32 index,
											ISequentialOutStream **outStream,
											Int32 askExtractMode)
	{
		*outStream = NULL;
		_outFileStream.Release();

//  _outFileStream.Release();
//
//  {
//	  // Get Name
//	  NCOM::CPropVariant prop;
//	  RINOK(_archiveHandler->GetProperty(index, kpidPath, &prop));
//
//	  UString fullPath;
//	  if (prop.vt == VT_EMPTY)
//		  fullPath = kEmptyFileAlias;
//	  else
//	  {
//		  if (prop.vt != VT_BSTR)
//			  return E_FAIL;
//		  fullPath = prop.bstrVal;
//	  }
//	  _filePath = fullPath;
//  }
//
//  if (askExtractMode != NArchive::NExtract::NAskMode::kExtract)
//	  return S_OK;
//
//  {
//	  // Get Attrib
//	  NCOM::CPropVariant prop;
//	  RINOK(_archiveHandler->GetProperty(index, kpidAttrib, &prop));
//	  if (prop.vt == VT_EMPTY)
//	  {
//		  _processedFileInfo.Attrib = 0;
//		  _processedFileInfo.AttribDefined = false;
//	  }
//	  else
//	  {
//		  if (prop.vt != VT_UI4)
//			  return E_FAIL;
//		  _processedFileInfo.Attrib = prop.ulVal;
//		  _processedFileInfo.AttribDefined = true;
//	  }
//  }
//
//  RINOK(IsArchiveItemFolder(_archiveHandler, index, _processedFileInfo.isDir));
//
//  {
//	  // Get Modified Time
//	  NCOM::CPropVariant prop;
//	  RINOK(_archiveHandler->GetProperty(index, kpidMTime, &prop));
//	  _processedFileInfo.MTimeDefined = false;
//	  switch(prop.vt)
//	  {
//		  case VT_EMPTY:
//			  // _processedFileInfo.MTime = _utcMTimeDefault;
//			  break;
//		  case VT_FILETIME:
//			  _processedFileInfo.MTime = prop.filetime;
//			  _processedFileInfo.MTimeDefined = true;
//			  break;
//		  default:
//			  return E_FAIL;
//	  }
//
//  }
//  {
//	  // Get Size
//	  NCOM::CPropVariant prop;
//	  RINOK(_archiveHandler->GetProperty(index, kpidSize, &prop));
//	  UInt64 newFileSize;
//	  /* bool newFileSizeDefined = */ ConvertPropVariantToUInt64(prop, newFileSize);
//  }
//
//
//  {
//	  // Create folders for file
//	  int slashPos = _filePath.ReverseFind_PathSepar();
//	  if (slashPos >= 0)
//		  CreateComplexDir(_directoryPath + us2fs(_filePath.Left(slashPos)));
//  }
//
//  FString fullProcessedPath = _directoryPath + us2fs(_filePath);
//  _diskFilePath = fullProcessedPath;
//
//  if (_processedFileInfo.isDir)
//  {
//	  CreateComplexDir(fullProcessedPath);
//  }
//  else
//  {
//	  NFind::CFileInfo fi;
//	  if (fi.Find(fullProcessedPath))
//	  {
//		  if (!DeleteFileAlways(fullProcessedPath))
//		  {
		//			  PrintError("Can not delete output file", fullProcessedPath);
		//			  return E_ABORT;
		//		  }
		//	  }
		//
		if (!_archive) return E_ABORT;
		NWindows::NCOM::CPropVariant pathProp;
		RINOK(_archive->GetProperty(index, kpidPath, &pathProp));

		PROPVARIANT isDirProp;
		RINOK(_archive->GetProperty(index, kpidIsDir, &isDirProp));

		if (isDirProp.vt != VT_BOOL || isDirProp.boolVal) return E_ABORT;

		NSString * archivePath = [[NSString alloc] initWithBytes:pathProp.bstrVal length:wcslen(pathProp.bstrVal) * sizeof(wchar_t) encoding:NSUTF32LittleEndianStringEncoding];
		if (!archivePath || [archivePath length] == 0) return E_ABORT;

		NSString * fullPath = [NSString stringWithUTF8String:_dstPath];
		NSString * fileName = [archivePath lastPathComponent];
		if (!fileName || [fileName length] == 0) return E_ABORT;

		if (_isFullPath)
		{
			NSString * subPath = [archivePath stringByDeletingLastPathComponent];
			if (subPath && [subPath length]) fullPath = [fullPath stringByAppendingPathComponent:subPath];
		}

		fullPath = [fullPath stringByAppendingPathComponent:fileName];

		_outFileStreamRef = new LzmaSDKObjC::OutFile();
		if (!_outFileStreamRef) return E_ABORT;
		if (!_outFileStreamRef->open([fullPath UTF8String])) return E_ABORT;

		CMyComPtr<ISequentialOutStream> outStreamLoc = _outFileStreamRef;
		//	  if (!_outFileStreamSpec->Open(fullProcessedPath, CREATE_ALWAYS))
		//	  {
		//		  PrintError("Can not open output file", fullProcessedPath);
		//		  return E_ABORT;
		//	  }
		_outFileStream = outStreamLoc;
		*outStream = outStreamLoc.Detach();
		//  }
  return S_OK;
	}

	STDMETHODIMP ExtractCallback::PrepareOperation(Int32 askExtractMode)
	{
//  _extractMode = false;
//  switch (askExtractMode)
//  {
//	  case NArchive::NExtract::NAskMode::kExtract:  _extractMode = true; break;
//  };
//  switch (askExtractMode)
//  {
//	  case NArchive::NExtract::NAskMode::kExtract:  PrintString(kExtractingString); break;
//	  case NArchive::NExtract::NAskMode::kTest:  PrintString(kTestingString); break;
//	  case NArchive::NExtract::NAskMode::kSkip:  PrintString(kSkippingString); break;
//  };
//  PrintString(_filePath);
  return S_OK;
	}

	STDMETHODIMP ExtractCallback::SetOperationResult(Int32 operationResult)
	{
//  switch (operationResult)
//  {
//	  case NArchive::NExtract::NOperationResult::kOK:
//		  break;
//	  default:
//	  {
//		  NumErrors++;
//		  PrintString("  :  ");
//		  const char *s = NULL;
//		  switch (operationResult)
//		  {
//			  case NArchive::NExtract::NOperationResult::kUnsupportedMethod:
//				  s = kUnsupportedMethod;
//				  break;
//			  case NArchive::NExtract::NOperationResult::kCRCError:
//				  s = kCRCFailed;
//				  break;
//			  case NArchive::NExtract::NOperationResult::kDataError:
//				  s = kDataError;
//				  break;
//			  case NArchive::NExtract::NOperationResult::kUnavailable:
//				  s = kUnavailableData;
//				  break;
//			  case NArchive::NExtract::NOperationResult::kUnexpectedEnd:
//				  s = kUnexpectedEnd;
//				  break;
//			  case NArchive::NExtract::NOperationResult::kDataAfterEnd:
//				  s = kDataAfterEnd;
//				  break;
//			  case NArchive::NExtract::NOperationResult::kIsNotArc:
//				  s = kIsNotArc;
//				  break;
//			  case NArchive::NExtract::NOperationResult::kHeadersError:
//				  s = kHeadersError;
//				  break;
//		  }
//		  if (s)
//		  {
//			  PrintString("Error : ");
//			  PrintString(s);
//		  }
//		  else
//		  {
//			  char temp[16];
//			  ConvertUInt32ToString(operationResult, temp);
//			  PrintString("Error #");
//			  PrintString(temp);
//		  }
//	  }
//  }
//
		if (_outFileStream != NULL && _outFileStreamRef)
		{
			_outFileStreamRef->close();
		}
		_outFileStream.Release();
		_outFileStreamRef = NULL;
		//  if (_extractMode && _processedFileInfo.AttribDefined)
		//	  SetFileAttrib(_diskFilePath, _processedFileInfo.Attrib);
		//  PrintNewLine();
		return S_OK;
	}

	STDMETHODIMP ExtractCallback::CryptoGetTextPassword(BSTR *password)
	{
		DEBUG_LOG("ExtractCallback::CryptoGetTextPassword")
		if (_coder)
		{
			UString w = _coder->onGetVoidCallback1();
			if (w.Len() > 0) return StringToBstr(w, password);
		}
		return E_ABORT;
	}

	STDMETHODIMP ExtractCallback::CryptoGetTextPassword2(Int32 *passwordIsDefined, BSTR *password)
	{
		DEBUG_LOG("ExtractCallback::CryptoGetTextPassword2")
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
		return E_ABORT;
	}

	bool ExtractCallback::prepare(const char * extractPath, bool isFullPath)
	{
		_dstPath = extractPath;
		_isFullPath = isFullPath;

		NSString * path = [NSString stringWithUTF8String:extractPath];

		NSFileManager * manager = [[NSFileManager alloc] init];
		BOOL isDir = NO;
		if ([manager fileExistsAtPath:path isDirectory:&isDir])
		{
			if (!isDir) return false;
		}
		else
		{
			NSError * error = nil;
			if (![manager createDirectoryAtPath:path withIntermediateDirectories:YES attributes:nil error:&error] || error) return false;
		}

//		NSString * tmpPath = [NSTemporaryDirectory() stringByAppendingPathComponent:[[NSProcessInfo processInfo] globallyUniqueString]];
//		if ([manager fileExistsAtPath:tmpPath]) return false;
//		if ([manager changeCurrentDirectoryPath:tmpPath]) return false;
//		_tmpPath = [tmpPath UTF8String];

		return true;
	}

	ExtractCallback::ExtractCallback() :
		_outFileStreamRef(NULL),
		_coder(NULL),
		_archive(NULL),
		_total(0),
		_isFullPath(false)
	{

	}

	ExtractCallback::~ExtractCallback()
	{

	}
	
}

