// Windows/System.cpp

#include "StdAfx.h"

#include "../Common/MyWindows.h"

#include "../Common/Defs.h"

#include "System.h"

#if defined(__APPLE__)
#include <mach/mach_host.h>
#endif

namespace NWindows {
namespace NSystem {

UInt32 GetNumberOfProcessors()
{
#if defined(__APPLE__)
	host_basic_info_data_t hostInfo;
	mach_msg_type_number_t infoCount;

	infoCount = HOST_BASIC_INFO_COUNT;
	host_info( mach_host_self(), HOST_BASIC_INFO, (host_info_t)&hostInfo, &infoCount ) ;

	return (unsigned int)(hostInfo.max_cpus);
#else
  SYSTEM_INFO systemInfo;
  GetSystemInfo(&systemInfo);
  return (UInt32)systemInfo.dwNumberOfProcessors;
#endif
}

#if !defined(__APPLE__)
#ifndef UNDER_CE

#if !defined(_WIN64) && defined(__GNUC__)

typedef struct _MY_MEMORYSTATUSEX {
  DWORD dwLength;
  DWORD dwMemoryLoad;
  DWORDLONG ullTotalPhys;
  DWORDLONG ullAvailPhys;
  DWORDLONG ullTotalPageFile;
  DWORDLONG ullAvailPageFile;
  DWORDLONG ullTotalVirtual;
  DWORDLONG ullAvailVirtual;
  DWORDLONG ullAvailExtendedVirtual;
} MY_MEMORYSTATUSEX, *MY_LPMEMORYSTATUSEX;

#else

#define MY_MEMORYSTATUSEX MEMORYSTATUSEX
#define MY_LPMEMORYSTATUSEX LPMEMORYSTATUSEX

#endif

typedef BOOL (WINAPI *GlobalMemoryStatusExP)(MY_LPMEMORYSTATUSEX lpBuffer);

#endif
#endif

UInt64 GetRamSize()
{
#if defined(__APPLE__)
	assert(0);
	return 10*1024*1024;
#else
  #ifndef UNDER_CE
  MY_MEMORYSTATUSEX stat;
  stat.dwLength = sizeof(stat);
  #endif
  #ifdef _WIN64
  if (!::GlobalMemoryStatusEx(&stat))
    return 0;
  return MyMin(stat.ullTotalVirtual, stat.ullTotalPhys);
  #else
  #ifndef UNDER_CE
  GlobalMemoryStatusExP globalMemoryStatusEx = (GlobalMemoryStatusExP)
      ::GetProcAddress(::GetModuleHandle(TEXT("kernel32.dll")), "GlobalMemoryStatusEx");
  if (globalMemoryStatusEx != 0 && globalMemoryStatusEx(&stat))
    return MyMin(stat.ullTotalVirtual, stat.ullTotalPhys);
  #endif
  {
    MEMORYSTATUS stat;
    stat.dwLength = sizeof(stat);
    ::GlobalMemoryStatus(&stat);
    return MyMin(stat.dwTotalVirtual, stat.dwTotalPhys);
  }
  #endif
#endif
}

}}
