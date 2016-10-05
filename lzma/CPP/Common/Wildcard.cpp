// Common/Wildcard.cpp

#include "StdAfx.h"

#include "Wildcard.h"

bool g_CaseSensitive =
#ifdef _WIN32
false;
#else
true;
#endif


bool IsPath1PrefixedByPath2(const wchar_t *s1, const wchar_t *s2)
{
	if (g_CaseSensitive)
		return IsString1PrefixedByString2(s1, s2);
	return IsString1PrefixedByString2_NoCase(s1, s2);
}

int CompareFileNames(const wchar_t *s1, const wchar_t *s2) STRING_UNICODE_THROW
{
	if (g_CaseSensitive)
		return wcscmp(s1, s2);
	return MyStringCompareNoCase(s1, s2);
}

