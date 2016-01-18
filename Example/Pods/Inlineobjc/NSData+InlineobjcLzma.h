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


#import <Foundation/Foundation.h>

#ifndef __NSDATA_INLINEOBJCLZMA_H__
#define __NSDATA_INLINEOBJCLZMA_H__ 1

#if defined(DEBUG) || defined(_DEBUG)
#ifndef DEBUG
#define DEBUG 1
#endif
#endif

#define __LZMA_PROPS_SIZE 5
#define __LZMA_kMaxHistorySize ((uint32_t)3 << 29)
#define __LZMA_kBlockSizeMax ((1 << __LZMA_NUM_BLOCK_SIZE_BITS) - 1)
#define __LZMA_kBlockSize (9 << 10)
#define __LZMA_kUnpackBlockSize (1 << 18)
#define __LZMA_kMatchArraySize (1 << 21)
#define __LZMA_kMatchRecordMaxSize ((__LZMA_MATCH_LEN_MAX * 2 + 3) * __LZMA_MATCH_LEN_MAX)
#define __LZMA_kNumMaxDirectBits (31)
#define __LZMA_kNumTopBits 24
#define __LZMA_kTopValue ((uint32_t)1 << __LZMA_kNumTopBits)
#define __LZMA_kNumBitModelTotalBits 11
#define __LZMA_kBitModelTotal (1 << __LZMA_kNumBitModelTotalBits)
#define __LZMA_kNumMoveBits 5
#define __LZMA_kProbInitValue (__LZMA_kBitModelTotal >> 1)
#define __LZMA_kNumMoveReducingBits 4
#define __LZMA_kNumBitPriceShiftBits 4
#define __LZMA_kBitPrice (1 << __LZMA_kNumBitPriceShiftBits)
#define __LZMA_NUM_REPS 4
#define __LZMA_kNumOpts (1 << 12)
#define __LZMA_kNumLenToPosStates 4
#define __LZMA_kNumPosSlotBits 6
#define __LZMA_kDicLogSizeMin 0
#define __LZMA_kDicLogSizeMax 32
#define __LZMA_kDistTableSizeMax (__LZMA_kDicLogSizeMax * 2)
#define __LZMA_kNumAlignBits 4
#define __LZMA_kAlignTableSize (1 << __LZMA_kNumAlignBits)
#define __LZMA_kAlignMask (__LZMA_kAlignTableSize - 1)
#define __LZMA_kStartPosModelIndex 4
#define __LZMA_kEndPosModelIndex 14
#define __LZMA_kNumPosModels (__LZMA_kEndPosModelIndex - __LZMA_kStartPosModelIndex)
#define __LZMA_kNumFullDistances (1 << (__LZMA_kEndPosModelIndex >> 1))
#define __LZMA_MATCH_LEN_MIN 2
#define __LZMA_MATCH_LEN_MAX (__LZMA_MATCH_LEN_MIN + __LZMA_kLenNumSymbolsTotal - 1)
#define __LZMA_kLenNumLowBits 3
#define __LZMA_kLenNumLowSymbols (1 << __LZMA_kLenNumLowBits)
#define __LZMA_kLenNumMidBits 3
#define __LZMA_kLenNumMidSymbols (1 << __LZMA_kLenNumMidBits)
#define __LZMA_kLenNumHighBits 8
#define __LZMA_kLenNumHighSymbols (1 << __LZMA_kLenNumHighBits)
#define __LZMA_kLenNumSymbolsTotal (__LZMA_kLenNumLowSymbols + __LZMA_kLenNumMidSymbols + __LZMA_kLenNumHighSymbols)
#define __LZMA_kNumStates 12
#define __LZMA_PB_MAX 4
#define __LZMA_LC_MAX 8
#define __LZMA_LP_MAX 4
#define __LZMA_NUM_PB_STATES_MAX (1 << __LZMA_PB_MAX)
#define __LZMA_kDicLogSizeMaxCompress 32
#define __LZMA_SZ_OK 0
#define __LZMA_SZ_ERROR_DATA 1
#define __LZMA_SZ_ERROR_MEM 2
#define __LZMA_SZ_ERROR_CRC 3
#define __LZMA_SZ_ERROR_UNSUPPORTED 4
#define __LZMA_SZ_ERROR_PARAM 5
#define __LZMA_SZ_ERROR_INPUT_EOF 6
#define __LZMA_SZ_ERROR_OUTPUT_EOF 7
#define __LZMA_SZ_ERROR_READ 8
#define __LZMA_SZ_ERROR_WRITE 9
#define __LZMA_SZ_ERROR_PROGRESS 10
#define __LZMA_SZ_ERROR_FAIL 11
#define __LZMA_SZ_ERROR_THREAD 12
#define __LZMA_SZ_ERROR_ARCHIVE 16
#define __LZMA_SZ_ERROR_NO_ARCHIVE 17
#define __LZMA_RINOK(x) { int __result__ = (x); if (__result__ != 0) return __result__; }
#define __LZMA_kEmptyHashValue 0
#define __LZMA_kCrcPoly 0xEDB88320
#define __LZMA_kMaxValForNormalize ((uint32_t)0xFFFFFFFF)
#define __LZMA_kNormalizeStepMin (1 << 10)
#define __LZMA_kNormalizeMask (~(__LZMA_kNormalizeStepMin - 1))
#define __LZMA_kHash2Size (1 << 10)
#define __LZMA_kHash3Size (1 << 16)
#define __LZMA_kHash4Size (1 << 20)
#define __LZMA_kFix3HashSize (__LZMA_kHash2Size)
#define __LZMA_kFix4HashSize (__LZMA_kHash2Size + __LZMA_kHash3Size)
#define __LZMA_kFix5HashSize (__LZMA_kHash2Size + __LZMA_kHash3Size + __LZMA_kHash4Size)
#define __LZMA_kBigHashDicLimit ((uint32_t)1 << 24)
#define __LZMA_RangeEnc_GetProcessed(p) ((p)->processed + ((p)->buf - (p)->bufBase) + (p)->cacheSize)
#define __LZMA_RC_BUF_SIZE (1 << 16)
#define __LZMA_kDicLogSizeMaxCompress 32
#define __LZMA_kInfinityPrice (1 << 30)
#define __LZMA_REQUIRED_INPUT_MAX 20
#define __LZMA_RC_INIT_SIZE 5
#define __LZMA_DIC_MIN (1 << 12)
#define __LZMA_BASE_SIZE 1846
#define __LZMA_LIT_SIZE 0x300
#define __LZMA_kNumPosBitsMax 4
#define __LZMA_kNumPosStatesMax (1 << __LZMA_kNumPosBitsMax)
#define __LZMA_LenChoice 0
#define __LZMA_LenChoice2 (__LZMA_LenChoice + 1)
#define __LZMA_LenLow (__LZMA_LenChoice2 + 1)
#define __LZMA_LenMid (__LZMA_LenLow + (__LZMA_kNumPosStatesMax << __LZMA_kLenNumLowBits))
#define __LZMA_LenHigh (__LZMA_LenMid + (__LZMA_kNumPosStatesMax << __LZMA_kLenNumMidBits))
#define __LZMA_kNumLenProbs (__LZMA_LenHigh + __LZMA_kLenNumHighSymbols)
#define __LZMA_kNumLitStates 7
#define __LZMA_IsMatch 0
#define __LZMA_IsRep (__LZMA_IsMatch + (__LZMA_kNumStates << __LZMA_kNumPosBitsMax))
#define __LZMA_IsRepG0 (__LZMA_IsRep + __LZMA_kNumStates)
#define __LZMA_IsRepG1 (__LZMA_IsRepG0 + __LZMA_kNumStates)
#define __LZMA_IsRepG2 (__LZMA_IsRepG1 + __LZMA_kNumStates)
#define __LZMA_IsRep0Long (__LZMA_IsRepG2 + __LZMA_kNumStates)
#define __LZMA_PosSlot (__LZMA_IsRep0Long + (__LZMA_kNumStates << __LZMA_kNumPosBitsMax))
#define __LZMA_SpecPos (__LZMA_PosSlot + (__LZMA_kNumLenToPosStates << __LZMA_kNumPosSlotBits))
#define __LZMA_Align (__LZMA_SpecPos + __LZMA_kNumFullDistances - __LZMA_kEndPosModelIndex)
#define __LZMA_LenCoder (__LZMA_Align + __LZMA_kAlignTableSize)
#define __LZMA_RepLenCoder (__LZMA_LenCoder + __LZMA_kNumLenProbs)
#define __LZMA_Literal (__LZMA_RepLenCoder + __LZMA_kNumLenProbs)
#define __LZMA_LzmaProps_GetNumProbs(p) (__LZMA_Literal + ((uint32_t)__LZMA_LIT_SIZE << ((p)->lc + (p)->lp)))
#define __LZMA_ChangePair(smallDist, bigDist) (((bigDist) >> 7) > (smallDist))
#define __LZMA_kMatchMinLen 2
#define __LZMA_kMatchSpecLenStart (__LZMA_kMatchMinLen + __LZMA_kLenNumLowSymbols + __LZMA_kLenNumMidSymbols + __LZMA_kLenNumHighSymbols)
#define __LZMA_LzmaProps_GetNumProbs(p) (__LZMA_Literal + ((uint32_t)__LZMA_LIT_SIZE << ((p)->lc + (p)->lp)))
#define __LZMA_HASH2_CALC hv = cur[0] | ((uint32_t)cur[1] << 8);
#define __LZMA_HASH3_CALC { \
uint32_t temp = p->crc[cur[0]] ^ cur[1]; \
h2 = temp & (__LZMA_kHash2Size - 1); \
hv = (temp ^ ((uint32_t)cur[2] << 8)) & p->hashMask; }

#define __LZMA_HASH4_CALC { \
uint32_t temp = p->crc[cur[0]] ^ cur[1]; \
h2 = temp & (__LZMA_kHash2Size - 1); \
temp ^= ((uint32_t)cur[2] << 8); \
h3 = temp & (__LZMA_kHash3Size - 1); \
hv = (temp ^ (p->crc[cur[3]] << 5)) & p->hashMask; }

#define __LZMA_HASH5_CALC { \
uint32_t temp = p->crc[cur[0]] ^ cur[1]; \
h2 = temp & (__LZMA_kHash2Size - 1); \
temp ^= ((uint32_t)cur[2] << 8); \
h3 = temp & (__LZMA_kHash3Size - 1); \
temp ^= (p->crc[cur[3]] << 5); \
h4 = temp & (__LZMA_kHash4Size - 1); \
hv = (temp ^ (p->crc[cur[4]] << 3)) & p->hashMask; }

#define __LZMA_HASH_ZIP_CALC hv = ((cur[2] | ((uint32_t)cur[0] << 8)) ^ p->crc[cur[1]]) & 0xFFFF;

#define __LZMA_MT_HASH2_CALC \
h2 = (p->crc[cur[0]] ^ cur[1]) & (__LZMA_kHash2Size - 1);

#define __LZMA_MT_HASH3_CALC { \
uint32_t temp = p->crc[cur[0]] ^ cur[1]; \
h2 = temp & (__LZMA_kHash2Size - 1); \
h3 = (temp ^ ((uint32_t)cur[2] << 8)) & (__LZMA_kHash3Size - 1); }

#define __LZMA_MT_HASH4_CALC { \
uint32_t temp = p->crc[cur[0]] ^ cur[1]; \
h2 = temp & (__LZMA_kHash2Size - 1); \
temp ^= ((uint32_t)cur[2] << 8); \
h3 = temp & (__LZMA_kHash3Size - 1); \
h4 = (temp ^ (p->crc[cur[3]] << 5)) & (kHash4Size - 1); }

typedef struct {
	int level;       /*  0 <= level <= 9 */
	uint32_t dictSize; /* (1 << 12) <= dictSize <= (1 << 27) for 32-bit version
						(1 << 12) <= dictSize <= (1 << 30) for 64-bit version
						default = (1 << 24) */
	uint64_t reduceSize; /* estimated size of data that will be compressed. default = 0xFFFFFFFF.
						  Encoder uses this value to reduce dictionary size */
	int lc;          /* 0 <= lc <= 8, default = 3 */
	int lp;          /* 0 <= lp <= 4, default = 0 */
	int pb;          /* 0 <= pb <= 4, default = 2 */
	int algo;        /* 0 - fast, 1 - normal, default = 1 */
	int fb;          /* 5 <= fb <= 273, default = 32 */
	int btMode;      /* 0 - hashChain Mode, 1 - binTree mode - normal, default = 1 */
	int numHashBytes; /* 2, 3 or 4, default = 4 */
	uint32_t mc;        /* 1 <= mc <= (1 << 30), default = 32 */
	unsigned writeEndMark;  /* 0 - do not write EOPM, 1 - write EOPM, default = 0 */
	int numThreads;  /* 1 or 2, default = 2 */
} __LZMA_CLzmaEncProps;

static void __LZMA_LzmaEncProps_Init(__LZMA_CLzmaEncProps *p) {
	p->level = 5;
	p->dictSize = p->mc = 0;
	p->reduceSize = (uint64_t)(int64_t)-1;
	p->lc = p->lp = p->pb = p->algo = p->fb = p->btMode = p->numHashBytes = p->numThreads = -1;
	p->writeEndMark = 0;
}

typedef struct {
	int (*Progress)(void *p, uint64_t inSize, uint64_t outSize);
} __LZMA_ICompressProgress;

typedef void (*__LZMA_Mf_Init_Func)(void *object);
typedef uint32_t (*__LZMA_Mf_GetNumAvailableBytes_Func)(void *object);
typedef const uint8_t * (*__LZMA_Mf_GetPointerToCurrentPos_Func)(void *object);
typedef uint32_t (*__LZMA_Mf_GetMatches_Func)(void *object, uint32_t *distances);
typedef void (*__LZMA_Mf_Skip_Func)(void *object, uint32_t);

typedef struct {
	__LZMA_Mf_Init_Func Init;
	__LZMA_Mf_GetNumAvailableBytes_Func GetNumAvailableBytes;
	__LZMA_Mf_GetPointerToCurrentPos_Func GetPointerToCurrentPos;
	__LZMA_Mf_GetMatches_Func GetMatches;
	__LZMA_Mf_Skip_Func Skip;
} __LZMA_IMatchFinder;

typedef struct {
	size_t (*Write)(void *p, const void *buf, size_t size);
} __LZMA_ISeqOutStream;

typedef struct {
	uint32_t range;
	uint8_t cache;
	uint64_t low;
	uint64_t cacheSize;
	uint8_t *buf;
	uint8_t *bufLim;
	uint8_t *bufBase;
	__LZMA_ISeqOutStream *outStream;
	uint64_t processed;
	int res;
} __LZMA_CRangeEnc;

typedef struct {
	int (*Read)(void *p, void *buf, size_t *size);
} __LZMA_ISeqInStream;

typedef struct {
	uint8_t *buffer;
	uint32_t pos;
	uint32_t posLimit;
	uint32_t streamPos;
	uint32_t lenLimit;
	uint32_t cyclicBufferPos;
	uint32_t cyclicBufferSize; /* it must be = (historySize + 1) */
	uint8_t streamEndWasReached;
	uint8_t btMode;
	uint8_t bigHash;
	uint8_t directInput;
	uint32_t matchMaxLen;
	uint32_t *hash;
	uint32_t *son;
	uint32_t hashMask;
	uint32_t cutValue;
	uint8_t *bufferBase;
	__LZMA_ISeqInStream *stream;
	uint32_t blockSize;
	uint32_t keepSizeBefore;
	uint32_t keepSizeAfter;
	uint32_t numHashBytes;
	size_t directInputRem;
	uint32_t historySize;
	uint32_t fixedHashSize;
	uint32_t hashSizeSum;
	int result;
	uint32_t crc[256];
	size_t numRefs;
} __LZMA_CMatchFinder;

typedef unsigned __LZMA_CState;

typedef struct {
	__LZMA_CState state;
	uint32_t price;
	uint32_t posPrev2;
	uint32_t backPrev2;
	uint32_t posPrev;
	uint32_t backPrev;
	uint32_t backs[__LZMA_NUM_REPS];
	int prev1IsChar;
	int prev2;
} __LZMA_COptimal;

typedef struct {
	uint16_t choice;
	uint16_t choice2;
	uint16_t low[__LZMA_NUM_PB_STATES_MAX << __LZMA_kLenNumLowBits];
	uint16_t mid[__LZMA_NUM_PB_STATES_MAX << __LZMA_kLenNumMidBits];
	uint16_t high[__LZMA_kLenNumHighSymbols];
} __LZMA_CLenEnc;

typedef struct {
	__LZMA_CLenEnc p;
	uint32_t tableSize;
	uint32_t prices[__LZMA_NUM_PB_STATES_MAX][__LZMA_kLenNumSymbolsTotal];
	uint32_t counters[__LZMA_NUM_PB_STATES_MAX];
} __LZMA_CLenPriceEnc;

typedef struct {
	uint16_t *litProbs;
	uint32_t state;
	uint32_t reps[__LZMA_NUM_REPS];
	uint16_t isMatch[__LZMA_kNumStates][__LZMA_NUM_PB_STATES_MAX];
	uint16_t isRep[__LZMA_kNumStates];
	uint16_t isRepG0[__LZMA_kNumStates];
	uint16_t isRepG1[__LZMA_kNumStates];
	uint16_t isRepG2[__LZMA_kNumStates];
	uint16_t isRep0Long[__LZMA_kNumStates][__LZMA_NUM_PB_STATES_MAX];
	uint16_t posSlotEncoder[__LZMA_kNumLenToPosStates][1 << __LZMA_kNumPosSlotBits];
	uint16_t posEncoders[__LZMA_kNumFullDistances - __LZMA_kEndPosModelIndex];
	uint16_t posAlignEncoder[1 << __LZMA_kNumAlignBits];
	__LZMA_CLenPriceEnc lenEnc;
	__LZMA_CLenPriceEnc repLenEnc;
} __LZMA_CSaveState;

typedef struct {
	void *matchFinderObj;
	__LZMA_IMatchFinder matchFinder;
	uint32_t optimumEndIndex;
	uint32_t optimumCurrentIndex;
	uint32_t longestMatchLength;
	uint32_t numPairs;
	uint32_t numAvail;
	uint32_t numFastBytes;
	uint32_t additionalOffset;
	uint32_t reps[__LZMA_NUM_REPS];
	uint32_t state;
	unsigned lc, lp, pb;
	unsigned lpMask, pbMask;
	unsigned lclp;
	uint16_t *litProbs;
	uint8_t fastMode;
	uint8_t writeEndMark;
	uint8_t finished;
	uint8_t multiThread;
	uint8_t needInit;
	uint64_t nowPos64;
	uint32_t matchPriceCount;
	uint32_t alignPriceCount;
	uint32_t distTableSize;
	uint32_t dictSize;
	int result;
	__LZMA_CRangeEnc rc;
	__LZMA_CMatchFinder matchFinderBase;
	__LZMA_COptimal opt[__LZMA_kNumOpts];
	uint32_t ProbPrices[__LZMA_kBitModelTotal >> __LZMA_kNumMoveReducingBits];
	uint32_t matches[__LZMA_MATCH_LEN_MAX * 2 + 2 + 1];
	uint32_t posSlotPrices[__LZMA_kNumLenToPosStates][__LZMA_kDistTableSizeMax];
	uint32_t distancesPrices[__LZMA_kNumLenToPosStates][__LZMA_kNumFullDistances];
	uint32_t alignPrices[__LZMA_kAlignTableSize];
	uint16_t isMatch[__LZMA_kNumStates][__LZMA_NUM_PB_STATES_MAX];
	uint16_t isRep[__LZMA_kNumStates];
	uint16_t isRepG0[__LZMA_kNumStates];
	uint16_t isRepG1[__LZMA_kNumStates];
	uint16_t isRepG2[__LZMA_kNumStates];
	uint16_t isRep0Long[__LZMA_kNumStates][__LZMA_NUM_PB_STATES_MAX];
	uint16_t posSlotEncoder[__LZMA_kNumLenToPosStates][1 << __LZMA_kNumPosSlotBits];
	uint16_t posEncoders[__LZMA_kNumFullDistances - __LZMA_kEndPosModelIndex];
	uint16_t posAlignEncoder[1 << __LZMA_kNumAlignBits];
	__LZMA_CLenPriceEnc lenEnc;
	__LZMA_CLenPriceEnc repLenEnc;
	__LZMA_CSaveState saveState;
} __LZMA_CLzmaEnc;

typedef struct {
	void *(*Alloc)(void *p, size_t size);
	void (*Free)(void *p, void *address);
} __LZMA_ISzAlloc;

typedef void * __LZMA_CLzmaEncHandle;

static void __LZMA_RangeEnc_Construct(__LZMA_CRangeEnc *p) {
	p->outStream = 0;
	p->bufBase = 0;
}

static void __LZMA_MatchFinder_SetDefaultSettings(__LZMA_CMatchFinder *p) {
	p->cutValue = 32;
	p->btMode = 1;
	p->numHashBytes = 4;
	p->bigHash = 0;
}

static void __LZMA_MatchFinder_Construct(__LZMA_CMatchFinder *p) {
	p->bufferBase = NULL;
	p->directInput = 0;
	p->hash = NULL;
	__LZMA_MatchFinder_SetDefaultSettings(p);
	for (uint32_t i = 0; i < 256; i++)
	{
		uint32_t r = i;
		for (unsigned j = 0; j < 8; j++) r = (r >> 1) ^ (__LZMA_kCrcPoly & ~((r & 1) - 1));
		p->crc[i] = r;
	}
}

static void __LZMA_LzmaEncProps_Normalize(__LZMA_CLzmaEncProps *p) {
	int level = p->level;
	if (level < 0) level = 5;
	p->level = level;
	if (p->dictSize == 0) p->dictSize = (level <= 5 ? (1 << (level * 2 + 14)) : (level == 6 ? (1 << 25) : (1 << 26)));
	if (p->dictSize > p->reduceSize)
	{
		unsigned i;
		for (i = 11; i <= 30; i++)
		{
			if ((uint32_t)p->reduceSize <= ((uint32_t)2 << i)) { p->dictSize = ((uint32_t)2 << i); break; }
			if ((uint32_t)p->reduceSize <= ((uint32_t)3 << i)) { p->dictSize = ((uint32_t)3 << i); break; }
		}
	}
	if (p->lc < 0) p->lc = 3;
	if (p->lp < 0) p->lp = 0;
	if (p->pb < 0) p->pb = 2;
	if (p->algo < 0) p->algo = (level < 5 ? 0 : 1);
	if (p->fb < 0) p->fb = (level < 7 ? 32 : 64);
	if (p->btMode < 0) p->btMode = (p->algo == 0 ? 0 : 1);
	if (p->numHashBytes < 0) p->numHashBytes = 4;
	if (p->mc == 0) p->mc = (16 + (p->fb >> 1)) >> (p->btMode ? 0 : 1);
	if (p->numThreads < 0) p->numThreads = 1;
}

static int __LZMA_LzmaEnc_SetProps(__LZMA_CLzmaEncHandle pp, const __LZMA_CLzmaEncProps *props2) {
	__LZMA_CLzmaEnc *p = (__LZMA_CLzmaEnc *)pp;
	__LZMA_CLzmaEncProps props = *props2;
	__LZMA_LzmaEncProps_Normalize(&props);
	if (props.lc > __LZMA_LC_MAX
		|| props.lp > __LZMA_LP_MAX
		|| props.pb > __LZMA_PB_MAX
		|| props.dictSize > ((uint64_t)1 << __LZMA_kDicLogSizeMaxCompress)
		|| props.dictSize > __LZMA_kMaxHistorySize)
		return __LZMA_SZ_ERROR_PARAM;

	p->dictSize = props.dictSize;
	{
		unsigned fb = props.fb;
		if (fb < 5) fb = 5;
		if (fb > __LZMA_MATCH_LEN_MAX) fb = __LZMA_MATCH_LEN_MAX;
		p->numFastBytes = fb;
	}
	p->lc = props.lc;
	p->lp = props.lp;
	p->pb = props.pb;
	p->fastMode = (props.algo == 0);
	p->matchFinderBase.btMode = (uint8_t)(props.btMode ? 1 : 0);
	{
		uint32_t numHashBytes = 4;
		if (props.btMode)
		{
			if (props.numHashBytes < 2) numHashBytes = 2;
			else if (props.numHashBytes < 4) numHashBytes = props.numHashBytes;
		}
		p->matchFinderBase.numHashBytes = numHashBytes;
	}
	p->matchFinderBase.cutValue = props.mc;
	p->writeEndMark = props.writeEndMark;
	return __LZMA_SZ_OK;
}

static void __LZMA_LzmaEnc_InitPriceTables(uint32_t *ProbPrices) {
	for (uint32_t i = (1 << __LZMA_kNumMoveReducingBits) / 2; i < __LZMA_kBitModelTotal; i += (1 << __LZMA_kNumMoveReducingBits))
	{
		const int kCyclesBits = __LZMA_kNumBitPriceShiftBits;
		uint32_t w = i;
		uint32_t bitCount = 0;
		for (int j = 0; j < kCyclesBits; j++)
		{
			w = w * w;
			bitCount <<= 1;
			while (w >= ((uint32_t)1 << 16)) { w >>= 1; bitCount++; }
		}
		ProbPrices[i >> __LZMA_kNumMoveReducingBits] = ((__LZMA_kNumBitModelTotalBits << kCyclesBits) - 15 - bitCount);
	}
}

static void __LZMA_LzmaEnc_Construct(__LZMA_CLzmaEnc *p) {
	__LZMA_RangeEnc_Construct(&p->rc);
	__LZMA_MatchFinder_Construct(&p->matchFinderBase);
	{
		__LZMA_CLzmaEncProps props;
		__LZMA_LzmaEncProps_Init(&props);
		__LZMA_LzmaEnc_SetProps(p, &props);
	}
	__LZMA_LzmaEnc_InitPriceTables(p->ProbPrices);
	p->litProbs = 0;
	p->saveState.litProbs = 0;
}

static __LZMA_CLzmaEncHandle __LZMA_LzmaEnc_Create(__LZMA_ISzAlloc *alloc) {
	void * p = alloc->Alloc(alloc, sizeof(__LZMA_CLzmaEnc));
	if (p != 0) __LZMA_LzmaEnc_Construct((__LZMA_CLzmaEnc *)p);
	return p;
}

static int __LZMA_LzmaEnc_WriteProperties(__LZMA_CLzmaEncHandle pp, uint8_t *props, size_t *size) {
	__LZMA_CLzmaEnc *p = (__LZMA_CLzmaEnc *)pp;
	unsigned i;
	uint32_t dictSize = p->dictSize;
	if (*size < __LZMA_PROPS_SIZE) return __LZMA_SZ_ERROR_PARAM;
	*size = __LZMA_PROPS_SIZE;
	props[0] = (uint8_t)((p->pb * 5 + p->lp) * 9 + p->lc);
	if (dictSize >= ((uint32_t)1 << 22))
	{
		uint32_t kDictMask = ((uint32_t)1 << 20) - 1;
		if (dictSize < (uint32_t)0xFFFFFFFF - kDictMask) dictSize = (dictSize + kDictMask) & ~kDictMask;
	}
	else for (i = 11; i <= 30; i++)
	{
		if (dictSize <= ((uint32_t)2 << i)) { dictSize = (2 << i); break; }
		if (dictSize <= ((uint32_t)3 << i)) { dictSize = (3 << i); break; }
	}
	for (i = 0; i < 4; i++) props[1 + i] = (uint8_t)(dictSize >> (8 * i));
	return __LZMA_SZ_OK;
}

typedef struct {
	__LZMA_ISeqOutStream funcTable;
	uint8_t *data;
	size_t rem;
	uint8_t overflow;
} __LZMA_CSeqOutStreamBuf;

static void __LZMA_LzmaEnc_SetInputBuf(__LZMA_CLzmaEnc *p, const uint8_t *src, size_t srcLen) {
	p->matchFinderBase.directInput = 1;
	p->matchFinderBase.bufferBase = (uint8_t *)src;
	p->matchFinderBase.directInputRem = srcLen;
}

static size_t __LZMA_MyWrite(void *pp, const void *data, size_t size) {
	__LZMA_CSeqOutStreamBuf *p = (__LZMA_CSeqOutStreamBuf *)pp;
	if (p->rem < size) { size = p->rem; p->overflow = 1; }
	memcpy(p->data, data, size);
	p->rem -= size;
	p->data += size;
	return size;
}

static int __LZMA_RangeEnc_Alloc(__LZMA_CRangeEnc *p, __LZMA_ISzAlloc *alloc) {
	if (p->bufBase == 0)
	{
		p->bufBase = (uint8_t *)alloc->Alloc(alloc, __LZMA_RC_BUF_SIZE);
		if (p->bufBase == 0) return 0;
		p->bufLim = p->bufBase + __LZMA_RC_BUF_SIZE;
	}
	return 1;
}

static void __LZMA_RangeEnc_Free(__LZMA_CRangeEnc *p, __LZMA_ISzAlloc *alloc) {
	alloc->Free(alloc, p->bufBase);
	p->bufBase = 0;
}

static void __LZMA_LzmaEnc_FreeLits(__LZMA_CLzmaEnc *p, __LZMA_ISzAlloc *alloc) {
	alloc->Free(alloc, p->litProbs);
	alloc->Free(alloc, p->saveState.litProbs);
	p->litProbs = 0;
	p->saveState.litProbs = 0;
}

static void __LZMA_MatchFinder_FreeThisClassMemory(__LZMA_CMatchFinder *p, __LZMA_ISzAlloc *alloc) {
	alloc->Free(alloc, p->hash);
	p->hash = NULL;
}

static void __LZMA_LzInWindow_Free(__LZMA_CMatchFinder *p, __LZMA_ISzAlloc *alloc) {
	if (!p->directInput) { alloc->Free(alloc, p->bufferBase); p->bufferBase = NULL; }
}

void __LZMA_MatchFinder_Free(__LZMA_CMatchFinder *p, __LZMA_ISzAlloc *alloc) {
	__LZMA_MatchFinder_FreeThisClassMemory(p, alloc);
	__LZMA_LzInWindow_Free(p, alloc);
}

static int __LZMA_LzInWindow_Create(__LZMA_CMatchFinder *p, uint32_t keepSizeReserv, __LZMA_ISzAlloc *alloc) {
	uint32_t blockSize = p->keepSizeBefore + p->keepSizeAfter + keepSizeReserv;
	if (p->directInput)
	{
		p->blockSize = blockSize;
		return 1;
	}
	if (!p->bufferBase || p->blockSize != blockSize)
	{
		__LZMA_LzInWindow_Free(p, alloc);
		p->blockSize = blockSize;
		p->bufferBase = (uint8_t *)alloc->Alloc(alloc, (size_t)blockSize);
	}
	return (p->bufferBase != NULL);
}

static uint32_t* __LZMA_AllocRefs(size_t num, __LZMA_ISzAlloc *alloc) {
	size_t sizeInBytes = (size_t)num * sizeof(uint32_t);
	if (sizeInBytes / sizeof(uint32_t) != num) return NULL;
	return (uint32_t *)alloc->Alloc(alloc, sizeInBytes);
}

static int __LZMA_MatchFinder_Create(__LZMA_CMatchFinder *p, uint32_t historySize,
									 uint32_t keepAddBufferBefore, uint32_t matchMaxLen, uint32_t keepAddBufferAfter, __LZMA_ISzAlloc *alloc) {
	uint32_t sizeReserv;
	if (historySize > __LZMA_kMaxHistorySize)
	{
		__LZMA_MatchFinder_Free(p, alloc);
		return 0;
	}
	sizeReserv = historySize >> 1;
	if (historySize >= ((uint32_t)3 << 30)) sizeReserv = historySize >> 3;
	else if (historySize >= ((uint32_t)2 << 30)) sizeReserv = historySize >> 2;
	sizeReserv += (keepAddBufferBefore + matchMaxLen + keepAddBufferAfter) / 2 + (1 << 19);
	p->keepSizeBefore = historySize + keepAddBufferBefore + 1;
	p->keepSizeAfter = matchMaxLen + keepAddBufferAfter;
	if (__LZMA_LzInWindow_Create(p, sizeReserv, alloc))
	{
		uint32_t newCyclicBufferSize = historySize + 1;
		uint32_t hs;
		p->matchMaxLen = matchMaxLen;
		{
			p->fixedHashSize = 0;
			if (p->numHashBytes == 2) hs = (1 << 16) - 1;
			else
			{
				hs = historySize - 1;
				hs |= (hs >> 1);
				hs |= (hs >> 2);
				hs |= (hs >> 4);
				hs |= (hs >> 8);
				hs >>= 1;
				hs |= 0xFFFF;
				if (hs > (1 << 24))
				{
					if (p->numHashBytes == 3) hs = (1 << 24) - 1;
					else hs >>= 1;
				}
			}
			p->hashMask = hs;
			hs++;
			if (p->numHashBytes > 2) p->fixedHashSize += __LZMA_kHash2Size;
			if (p->numHashBytes > 3) p->fixedHashSize += __LZMA_kHash3Size;
			if (p->numHashBytes > 4) p->fixedHashSize += __LZMA_kHash4Size;
			hs += p->fixedHashSize;
		}
		{
			p->historySize = historySize;
			p->hashSizeSum = hs;
			p->cyclicBufferSize = newCyclicBufferSize;
			size_t numSons = newCyclicBufferSize;
			if (p->btMode) numSons <<= 1;
			size_t newSize = hs + numSons;
			if (p->hash && p->numRefs == newSize) return 1;
			__LZMA_MatchFinder_FreeThisClassMemory(p, alloc);
			p->numRefs = newSize;
			p->hash = __LZMA_AllocRefs(newSize, alloc);
			if (p->hash)
			{
				p->son = p->hash + p->hashSizeSum;
				return 1;
			}
		}
	}
	__LZMA_MatchFinder_Free(p, alloc);
	return 0;
}

static void __LZMA_MatchFinder_ReadBlock(__LZMA_CMatchFinder *p) {
	if (p->streamEndWasReached || p->result != __LZMA_SZ_OK) return;
	if (p->directInput)
	{
		uint32_t curSize = 0xFFFFFFFF - p->streamPos;
		if (curSize > p->directInputRem)
			curSize = (uint32_t)p->directInputRem;
		p->directInputRem -= curSize;
		p->streamPos += curSize;
		if (p->directInputRem == 0) p->streamEndWasReached = 1;
		return;
	}

	for (;;)
	{
		uint8_t *dest = p->buffer + (p->streamPos - p->pos);
		size_t size = (p->bufferBase + p->blockSize - dest);
		if (size == 0) return;
		p->result = p->stream->Read(p->stream, dest, &size);
		if (p->result != __LZMA_SZ_OK) return;
		if (size == 0)
		{
			p->streamEndWasReached = 1;
			return;
		}
		p->streamPos += (uint32_t)size;
		if (p->streamPos - p->pos > p->keepSizeAfter) return;
	}
}

static void __LZMA_MatchFinder_SetLimits(__LZMA_CMatchFinder *p) {
	uint32_t limit = __LZMA_kMaxValForNormalize - p->pos;
	uint32_t limit2 = p->cyclicBufferSize - p->cyclicBufferPos;
	if (limit2 < limit) limit = limit2;
	limit2 = p->streamPos - p->pos;
	if (limit2 <= p->keepSizeAfter)
	{
		if (limit2 > 0) limit2 = 1;
	}
	else limit2 -= p->keepSizeAfter;
	if (limit2 < limit) limit = limit2;
	{
		uint32_t lenLimit = p->streamPos - p->pos;
		if (lenLimit > p->matchMaxLen) lenLimit = p->matchMaxLen;
		p->lenLimit = lenLimit;
	}
	p->posLimit = p->pos + limit;
}

static void __LZMA_MatchFinder_Init(__LZMA_CMatchFinder *p) {
	uint32_t *hash = p->hash;
	uint32_t num = p->hashSizeSum;
	for (uint32_t i = 0; i < num; i++) hash[i] = __LZMA_kEmptyHashValue;
	p->cyclicBufferPos = 0;
	p->buffer = p->bufferBase;
	p->pos = p->streamPos = p->cyclicBufferSize;
	p->result = __LZMA_SZ_OK;
	p->streamEndWasReached = 0;
	__LZMA_MatchFinder_ReadBlock(p);
	__LZMA_MatchFinder_SetLimits(p);
}

static uint32_t __LZMA_MatchFinder_GetNumAvailableBytes(__LZMA_CMatchFinder *p) { return p->streamPos - p->pos; }
static uint8_t *__LZMA_MatchFinder_GetPointerToCurrentPos(__LZMA_CMatchFinder *p) { return p->buffer; }
static void __LZMA_MatchFinder_CheckLimits(__LZMA_CMatchFinder *p);

#define __LZMA_MOVE_POS \
++p->cyclicBufferPos; \
p->buffer++; \
if (++p->pos == p->posLimit) __LZMA_MatchFinder_CheckLimits(p);

static void __LZMA_MatchFinder_MovePos(__LZMA_CMatchFinder *p) { __LZMA_MOVE_POS; }

#define __LZMA_GET_MATCHES_HEADER2(minLen, ret_op) \
uint32_t lenLimit; uint32_t hv; const uint8_t *cur; uint32_t curMatch; \
lenLimit = p->lenLimit; { if (lenLimit < minLen) { __LZMA_MatchFinder_MovePos(p); ret_op; }} \
cur = p->buffer;

#define __LZMA_GET_MATCHES_HEADER(minLen) __LZMA_GET_MATCHES_HEADER2(minLen, return 0)

#define __LZMA_UPDATE_maxLen { \
ptrdiff_t diff = (ptrdiff_t)0 - d2; \
const uint8_t *c = cur + maxLen; \
const uint8_t *lim = cur + lenLimit; \
for (; c != lim; c++) if (*(c + diff) != *c) break; \
maxLen = (uint32_t)(c - cur); }

static uint32_t __LZMA_MatchFinder_GetSubValue(__LZMA_CMatchFinder *p) { return (p->pos - p->historySize - 1) & __LZMA_kNormalizeMask; }

static void __LZMA_MatchFinder_Normalize3(uint32_t subValue, uint32_t *items, size_t numItems) {
	for (size_t i = 0; i < numItems; i++) {
		uint32_t value = items[i];
		if (value <= subValue) value = __LZMA_kEmptyHashValue;
		else value -= subValue;
		items[i] = value;
	}
}

static void __LZMA_MatchFinder_ReduceOffsets(__LZMA_CMatchFinder *p, uint32_t subValue) {
	p->posLimit -= subValue;
	p->pos -= subValue;
	p->streamPos -= subValue;
}

static void __LZMA_MatchFinder_Normalize(__LZMA_CMatchFinder *p) {
	uint32_t subValue = __LZMA_MatchFinder_GetSubValue(p);
	__LZMA_MatchFinder_Normalize3(subValue, p->hash, p->numRefs);
	__LZMA_MatchFinder_ReduceOffsets(p, subValue);
}

static int __LZMA_MatchFinder_NeedMove(__LZMA_CMatchFinder *p) {
	if (p->directInput) return 0;
	return ((size_t)(p->bufferBase + p->blockSize - p->buffer) <= p->keepSizeAfter);
}

static void __LZMA_MatchFinder_MoveBlock(__LZMA_CMatchFinder *p) {
	memmove(p->bufferBase,
			p->buffer - p->keepSizeBefore,
			(size_t)(p->streamPos - p->pos + p->keepSizeBefore));
	p->buffer = p->bufferBase + p->keepSizeBefore;
}

static void __LZMA_MatchFinder_CheckAndMoveAndRead(__LZMA_CMatchFinder *p) {
	if (__LZMA_MatchFinder_NeedMove(p)) __LZMA_MatchFinder_MoveBlock(p);
	__LZMA_MatchFinder_ReadBlock(p);
}

static void __LZMA_MatchFinder_CheckLimits(__LZMA_CMatchFinder *p) {
	if (p->pos == __LZMA_kMaxValForNormalize) __LZMA_MatchFinder_Normalize(p);
	if (!p->streamEndWasReached && p->keepSizeAfter == p->streamPos - p->pos) __LZMA_MatchFinder_CheckAndMoveAndRead(p);
	if (p->cyclicBufferPos == p->cyclicBufferSize) p->cyclicBufferPos = 0;
	__LZMA_MatchFinder_SetLimits(p);
}

#define __LZMA_MOVE_POS_RET __LZMA_MOVE_POS return offset;

static uint32_t * __LZMA_Hc_GetMatchesSpec(uint32_t lenLimit, uint32_t curMatch, uint32_t pos, const uint8_t *cur, uint32_t *son,
										   uint32_t _cyclicBufferPos, uint32_t _cyclicBufferSize, uint32_t cutValue,
										   uint32_t *distances, uint32_t maxLen) {
	son[_cyclicBufferPos] = curMatch;
	for (;;)
	{
		uint32_t delta = pos - curMatch;
		if (cutValue-- == 0 || delta >= _cyclicBufferSize) return distances;
		{
			const uint8_t *pb = cur - delta;
			curMatch = son[_cyclicBufferPos - delta + ((delta > _cyclicBufferPos) ? _cyclicBufferSize : 0)];
			if (pb[maxLen] == cur[maxLen] && *pb == *cur)
			{
				uint32_t len = 0;
				while (++len != lenLimit) if (pb[len] != cur[len]) break;
				if (maxLen < len)
				{
					*distances++ = maxLen = len;
					*distances++ = delta - 1;
					if (len == lenLimit) return distances;
				}
			}
		}
	}
}

#define __LZMA_MF_PARAMS(p) p->pos, p->buffer, p->son, p->cyclicBufferPos, p->cyclicBufferSize, p->cutValue

static uint32_t __LZMA_Hc4_MatchFinder_GetMatches(__LZMA_CMatchFinder *p, uint32_t *distances) {
	uint32_t h2, h3, d2, d3, maxLen, offset, pos;
	__LZMA_GET_MATCHES_HEADER(4)
	__LZMA_HASH4_CALC;
	uint32_t *hash = p->hash;
	pos = p->pos;
	d2 = pos - hash[h2];
	d3 = pos - hash[__LZMA_kFix3HashSize + h3];
	curMatch = hash[__LZMA_kFix4HashSize + hv];
	hash[h2] = pos;
	hash[__LZMA_kFix3HashSize + h3] = hash[__LZMA_kFix4HashSize + hv] = pos;
	maxLen = 0;
	offset = 0;
	if (d2 < p->cyclicBufferSize && *(cur - d2) == *cur)
	{
		distances[0] = maxLen = 2;
		distances[1] = d2 - 1;
		offset = 2;
	}
	if (d2 != d3 && d3 < p->cyclicBufferSize && *(cur - d3) == *cur)
	{
		maxLen = 3;
		distances[offset + 1] = d3 - 1;
		offset += 2;
		d2 = d3;
	}
	if (offset != 0)
	{
		__LZMA_UPDATE_maxLen
		distances[offset - 2] = maxLen;
		if (maxLen == lenLimit)
		{
			p->son[p->cyclicBufferPos] = curMatch;
			__LZMA_MOVE_POS_RET;
		}
	}
	if (maxLen < 3) maxLen = 3;
	offset = (uint32_t)(__LZMA_Hc_GetMatchesSpec(lenLimit, curMatch, __LZMA_MF_PARAMS(p), distances + offset, maxLen) - (distances));
	__LZMA_MOVE_POS_RET
}

#define __LZMA_SKIP_HEADER(minLen) __LZMA_GET_MATCHES_HEADER2(minLen, continue)

static void __LZMA_Hc4_MatchFinder_Skip(__LZMA_CMatchFinder *p, uint32_t num) {
	do {
		uint32_t h2, h3;
		__LZMA_SKIP_HEADER(4)
		__LZMA_HASH4_CALC;
		uint32_t *hash = p->hash;
		curMatch = hash[__LZMA_kFix4HashSize + hv];
		hash[h2] = hash[__LZMA_kFix3HashSize + h3] = hash[__LZMA_kFix4HashSize + hv] = p->pos;
		p->son[p->cyclicBufferPos] = curMatch;
		__LZMA_MOVE_POS
	}
	while (--num != 0);
}

static uint32_t * __LZMA_GetMatchesSpec1(uint32_t lenLimit, uint32_t curMatch, uint32_t pos, const uint8_t *cur, uint32_t *son,
										 uint32_t _cyclicBufferPos, uint32_t _cyclicBufferSize, uint32_t cutValue,
										 uint32_t *distances, uint32_t maxLen) {
	uint32_t *ptr0 = son + (_cyclicBufferPos << 1) + 1;
	uint32_t *ptr1 = son + (_cyclicBufferPos << 1);
	uint32_t len0 = 0, len1 = 0;
	for (;;) {
		uint32_t delta = pos - curMatch;
		if (cutValue-- == 0 || delta >= _cyclicBufferSize)
		{
			*ptr0 = *ptr1 = __LZMA_kEmptyHashValue;
			return distances;
		}
		{
			uint32_t *pair = son + ((_cyclicBufferPos - delta + ((delta > _cyclicBufferPos) ? _cyclicBufferSize : 0)) << 1);
			const uint8_t *pb = cur - delta;
			uint32_t len = (len0 < len1 ? len0 : len1);
			if (pb[len] == cur[len])
			{
				if (++len != lenLimit && pb[len] == cur[len])
					while (++len != lenLimit)
						if (pb[len] != cur[len])
							break;
				if (maxLen < len)
				{
					*distances++ = maxLen = len;
					*distances++ = delta - 1;
					if (len == lenLimit)
					{
						*ptr1 = pair[0];
						*ptr0 = pair[1];
						return distances;
					}
				}
			}
			if (pb[len] < cur[len])
			{
				*ptr1 = curMatch;
				ptr1 = pair + 1;
				curMatch = *ptr1;
				len1 = len;
			}
			else
			{
				*ptr0 = curMatch;
				ptr0 = pair;
				curMatch = *ptr0;
				len0 = len;
			}
		}
	}
}

#define __LZMA_GET_MATCHES_FOOTER(offset, maxLen) \
offset = (uint32_t)(__LZMA_GetMatchesSpec1(lenLimit, curMatch, __LZMA_MF_PARAMS(p), \
distances + offset, maxLen) - distances); __LZMA_MOVE_POS_RET;

static uint32_t __LZMA_Bt2_MatchFinder_GetMatches(__LZMA_CMatchFinder *p, uint32_t *distances) {
	uint32_t offset;
	__LZMA_GET_MATCHES_HEADER(2)
	__LZMA_HASH2_CALC;
	curMatch = p->hash[hv];
	p->hash[hv] = p->pos;
	offset = 0;
	__LZMA_GET_MATCHES_FOOTER(offset, 1)
}

static void __LZMA_SkipMatchesSpec(uint32_t lenLimit, uint32_t curMatch, uint32_t pos, const uint8_t *cur, uint32_t *son,
								   uint32_t _cyclicBufferPos, uint32_t _cyclicBufferSize, uint32_t cutValue) {
	uint32_t *ptr0 = son + (_cyclicBufferPos << 1) + 1;
	uint32_t *ptr1 = son + (_cyclicBufferPos << 1);
	uint32_t len0 = 0, len1 = 0;
	for (;;) {
		uint32_t delta = pos - curMatch;
		if (cutValue-- == 0 || delta >= _cyclicBufferSize)
		{
			*ptr0 = *ptr1 = __LZMA_kEmptyHashValue;
			return;
		}
		{
			uint32_t *pair = son + ((_cyclicBufferPos - delta + ((delta > _cyclicBufferPos) ? _cyclicBufferSize : 0)) << 1);
			const uint8_t *pb = cur - delta;
			uint32_t len = (len0 < len1 ? len0 : len1);
			if (pb[len] == cur[len])
			{
				while (++len != lenLimit)
					if (pb[len] != cur[len])
						break;
				{
					if (len == lenLimit)
					{
						*ptr1 = pair[0];
						*ptr0 = pair[1];
						return;
					}
				}
			}
			if (pb[len] < cur[len])
			{
				*ptr1 = curMatch;
				ptr1 = pair + 1;
				curMatch = *ptr1;
				len1 = len;
			}
			else
			{
				*ptr0 = curMatch;
				ptr0 = pair;
				curMatch = *ptr0;
				len0 = len;
			}
		}
	}
}

#define __LZMA_SKIP_FOOTER \
__LZMA_SkipMatchesSpec(lenLimit, curMatch, __LZMA_MF_PARAMS(p)); __LZMA_MOVE_POS;

static void __LZMA_Bt2_MatchFinder_Skip(__LZMA_CMatchFinder *p, uint32_t num) {
	do {
		__LZMA_SKIP_HEADER(2)
		__LZMA_HASH2_CALC;
		curMatch = p->hash[hv];
		p->hash[hv] = p->pos;
		__LZMA_SKIP_FOOTER
	}
	while (--num != 0);
}

static uint32_t __LZMA_Bt3_MatchFinder_GetMatches(__LZMA_CMatchFinder *p, uint32_t *distances) {
	uint32_t h2, d2, maxLen, offset, pos;
	__LZMA_GET_MATCHES_HEADER(3)
	__LZMA_HASH3_CALC;
	uint32_t *hash = p->hash;
	pos = p->pos;
	d2 = pos - hash[h2];
	curMatch = hash[__LZMA_kFix3HashSize + hv];
	hash[h2] = pos;
	hash[__LZMA_kFix3HashSize + hv] = pos;
	maxLen = 2;
	offset = 0;
	if (d2 < p->cyclicBufferSize && *(cur - d2) == *cur)
	{
		__LZMA_UPDATE_maxLen
		distances[0] = maxLen;
		distances[1] = d2 - 1;
		offset = 2;
		if (maxLen == lenLimit)
		{
			__LZMA_SkipMatchesSpec(lenLimit, curMatch, __LZMA_MF_PARAMS(p));
			__LZMA_MOVE_POS_RET;
		}
	}
	__LZMA_GET_MATCHES_FOOTER(offset, maxLen)
}

static void __LZMA_Bt3_MatchFinder_Skip(__LZMA_CMatchFinder *p, uint32_t num) {
	do {
		uint32_t h2;
		__LZMA_SKIP_HEADER(3)
		__LZMA_HASH3_CALC;
		uint32_t *hash = p->hash;
		curMatch = hash[__LZMA_kFix3HashSize + hv];
		hash[h2] = hash[__LZMA_kFix3HashSize + hv] = p->pos;
		__LZMA_SKIP_FOOTER
	} while (--num != 0);
}

static uint32_t __LZMA_Bt4_MatchFinder_GetMatches(__LZMA_CMatchFinder *p, uint32_t *distances) {
	uint32_t h2, h3, d2, d3, maxLen, offset, pos;
	__LZMA_GET_MATCHES_HEADER(4)
	__LZMA_HASH4_CALC;
	uint32_t *hash = p->hash;
	pos = p->pos;
	d2 = pos - hash[h2];
	d3 = pos - hash[__LZMA_kFix3HashSize + h3];
	curMatch = hash[__LZMA_kFix4HashSize + hv];
	hash[h2] = pos;
	hash[__LZMA_kFix3HashSize + h3] = pos;
	hash[__LZMA_kFix4HashSize + hv] = pos;
	maxLen = 0;
	offset = 0;
	if (d2 < p->cyclicBufferSize && *(cur - d2) == *cur)
	{
		distances[0] = maxLen = 2;
		distances[1] = d2 - 1;
		offset = 2;
	}
	if (d2 != d3 && d3 < p->cyclicBufferSize && *(cur - d3) == *cur)
	{
		maxLen = 3;
		distances[offset + 1] = d3 - 1;
		offset += 2;
		d2 = d3;
	}
	if (offset != 0)
	{
		__LZMA_UPDATE_maxLen
		distances[offset - 2] = maxLen;
		if (maxLen == lenLimit)
		{
			__LZMA_SkipMatchesSpec(lenLimit, curMatch, __LZMA_MF_PARAMS(p));
			__LZMA_MOVE_POS_RET;
		}
	}
	if (maxLen < 3) maxLen = 3;
	__LZMA_GET_MATCHES_FOOTER(offset, maxLen)
}

static void __LZMA_Bt4_MatchFinder_Skip(__LZMA_CMatchFinder *p, uint32_t num) {
	do {
		uint32_t h2, h3;
		__LZMA_SKIP_HEADER(4)
		__LZMA_HASH4_CALC;
		uint32_t *hash = p->hash;
		curMatch = hash[__LZMA_kFix4HashSize + hv];
		hash[h2] = hash[__LZMA_kFix3HashSize + h3] = hash[__LZMA_kFix4HashSize + hv] = p->pos;
		__LZMA_SKIP_FOOTER
	} while (--num != 0);
}

static void __LZMA_MatchFinder_CreateVTable(__LZMA_CMatchFinder *p, __LZMA_IMatchFinder *vTable) {
	vTable->Init = (__LZMA_Mf_Init_Func)__LZMA_MatchFinder_Init;
	vTable->GetNumAvailableBytes = (__LZMA_Mf_GetNumAvailableBytes_Func)__LZMA_MatchFinder_GetNumAvailableBytes;
	vTable->GetPointerToCurrentPos = (__LZMA_Mf_GetPointerToCurrentPos_Func)__LZMA_MatchFinder_GetPointerToCurrentPos;
	if (!p->btMode)
	{
		vTable->GetMatches = (__LZMA_Mf_GetMatches_Func)__LZMA_Hc4_MatchFinder_GetMatches;
		vTable->Skip = (__LZMA_Mf_Skip_Func)__LZMA_Hc4_MatchFinder_Skip;
	}
	else if (p->numHashBytes == 2)
	{
		vTable->GetMatches = (__LZMA_Mf_GetMatches_Func)__LZMA_Bt2_MatchFinder_GetMatches;
		vTable->Skip = (__LZMA_Mf_Skip_Func)__LZMA_Bt2_MatchFinder_Skip;
	}
	else if (p->numHashBytes == 3)
	{
		vTable->GetMatches = (__LZMA_Mf_GetMatches_Func)__LZMA_Bt3_MatchFinder_GetMatches;
		vTable->Skip = (__LZMA_Mf_Skip_Func)__LZMA_Bt3_MatchFinder_Skip;
	}
	else
	{
		vTable->GetMatches = (__LZMA_Mf_GetMatches_Func)__LZMA_Bt4_MatchFinder_GetMatches;
		vTable->Skip = (__LZMA_Mf_Skip_Func)__LZMA_Bt4_MatchFinder_Skip;
	}
}

static int __LZMA_LzmaEnc_Alloc(__LZMA_CLzmaEnc *p, uint32_t keepWindowSize, __LZMA_ISzAlloc *alloc, __LZMA_ISzAlloc *allocBig) {
	uint32_t beforeSize = __LZMA_kNumOpts;
	if (!__LZMA_RangeEnc_Alloc(&p->rc, alloc)) return __LZMA_SZ_ERROR_MEM;

	{
		unsigned lclp = p->lc + p->lp;
		if (p->litProbs == 0 || p->saveState.litProbs == 0 || p->lclp != lclp)
		{
			__LZMA_LzmaEnc_FreeLits(p, alloc);
			p->litProbs = (uint16_t *)alloc->Alloc(alloc, ((uint32_t)0x300 << lclp) * sizeof(uint16_t));
			p->saveState.litProbs = (uint16_t *)alloc->Alloc(alloc, ((uint32_t)0x300 << lclp) * sizeof(uint16_t));
			if (p->litProbs == 0 || p->saveState.litProbs == 0)
			{
				__LZMA_LzmaEnc_FreeLits(p, alloc);
				return __LZMA_SZ_ERROR_MEM;
			}
			p->lclp = lclp;
		}
	}
	p->matchFinderBase.bigHash = (uint8_t)(p->dictSize > __LZMA_kBigHashDicLimit ? 1 : 0);
	if (beforeSize + p->dictSize < keepWindowSize) beforeSize = keepWindowSize - p->dictSize;
	{
		if (!__LZMA_MatchFinder_Create(&p->matchFinderBase, p->dictSize, beforeSize, p->numFastBytes, __LZMA_MATCH_LEN_MAX, allocBig)) return __LZMA_SZ_ERROR_MEM;
		p->matchFinderObj = &p->matchFinderBase;
		__LZMA_MatchFinder_CreateVTable(&p->matchFinderBase, &p->matchFinder);
	}
	return __LZMA_SZ_OK;
}

static void __LZMA_RangeEnc_Init(__LZMA_CRangeEnc *p) {
	p->low = 0;
	p->range = 0xFFFFFFFF;
	p->cacheSize = 1;
	p->cache = 0;
	p->buf = p->bufBase;
	p->processed = 0;
	p->res = __LZMA_SZ_OK;
}

static void __LZMA_LenEnc_Init(__LZMA_CLenEnc *p) {
	unsigned i;
	p->choice = p->choice2 = __LZMA_kProbInitValue;
	for (i = 0; i < (__LZMA_NUM_PB_STATES_MAX << __LZMA_kLenNumLowBits); i++) p->low[i] = __LZMA_kProbInitValue;
	for (i = 0; i < (__LZMA_NUM_PB_STATES_MAX << __LZMA_kLenNumMidBits); i++) p->mid[i] = __LZMA_kProbInitValue;
	for (i = 0; i < __LZMA_kLenNumHighSymbols; i++) p->high[i] = __LZMA_kProbInitValue;
}

static void __LZMA_LzmaEnc_Init(__LZMA_CLzmaEnc *p) {
	p->state = 0;
	for (uint32_t i = 0 ; i < __LZMA_NUM_REPS; i++) p->reps[i] = 0;
	__LZMA_RangeEnc_Init(&p->rc);
	for (uint32_t i = 0; i < __LZMA_kNumStates; i++)
	{
		for (uint32_t j = 0; j < __LZMA_NUM_PB_STATES_MAX; j++)
		{
			p->isMatch[i][j] = __LZMA_kProbInitValue;
			p->isRep0Long[i][j] = __LZMA_kProbInitValue;
		}
		p->isRep[i] = __LZMA_kProbInitValue;
		p->isRepG0[i] = __LZMA_kProbInitValue;
		p->isRepG1[i] = __LZMA_kProbInitValue;
		p->isRepG2[i] = __LZMA_kProbInitValue;
	}
	{
		uint32_t num = (uint32_t)0x300 << (p->lp + p->lc);
		uint16_t *probs = p->litProbs;
		for (uint32_t i = 0; i < num; i++) probs[i] = __LZMA_kProbInitValue;
	}
	{
		for (uint32_t i = 0; i < __LZMA_kNumLenToPosStates; i++)
		{
			uint16_t *probs = p->posSlotEncoder[i];
			for (uint32_t j = 0; j < (1 << __LZMA_kNumPosSlotBits); j++) probs[j] = __LZMA_kProbInitValue;
		}
	}
	{
		for (uint32_t i = 0; i < __LZMA_kNumFullDistances - __LZMA_kEndPosModelIndex; i++) p->posEncoders[i] = __LZMA_kProbInitValue;
	}
	__LZMA_LenEnc_Init(&p->lenEnc.p);
	__LZMA_LenEnc_Init(&p->repLenEnc.p);
	for (uint32_t i = 0; i < (1 << __LZMA_kNumAlignBits); i++) p->posAlignEncoder[i] = __LZMA_kProbInitValue;
	p->optimumEndIndex = 0;
	p->optimumCurrentIndex = 0;
	p->additionalOffset = 0;
	p->pbMask = (1 << p->pb) - 1;
	p->lpMask = (1 << p->lp) - 1;
}

static unsigned char __LZMA__BitScanReverse(unsigned long *firstBit1Index, unsigned long scanNum) {
	unsigned char isNonzero;
	isNonzero = (unsigned char)scanNum;
	if (scanNum != 0) {
		size_t index = __builtin_clz(scanNum);
		*firstBit1Index = index ^ 31;
	}
	else *firstBit1Index = 0;
	return isNonzero;
}

#define __LZMA_BSR2_RET(pos, res) { unsigned long i; __LZMA__BitScanReverse(&i, (pos)); res = (i + i) + ((pos >> (i - 1)) & 1); }

static uint32_t __LZMA_GetPosSlot1(uint32_t pos) {
	uint32_t res;
	__LZMA_BSR2_RET(pos, res);
	return res;
}

#define __LZMA_GetPosSlot2(pos, res) { __LZMA_BSR2_RET(pos, res); }
#define __LZMA_GetPosSlot(pos, res) { if (pos < 2) res = pos; else __LZMA_BSR2_RET(pos, res); }

#define __LZMA_GET_PRICEa(prob, symbol) \
ProbPrices[((prob) ^ ((-((int)(symbol))) & (__LZMA_kBitModelTotal - 1))) >> __LZMA_kNumMoveReducingBits];

static uint32_t __LZMA_RcTree_ReverseGetPrice(const uint16_t *probs, int numBitLevels, uint32_t symbol, const uint32_t *ProbPrices) {
	uint32_t price = 0;
	uint32_t m = 1;
	for (int i = numBitLevels; i != 0; i--)
	{
		uint32_t bit = symbol & 1;
		symbol >>= 1;
		price += __LZMA_GET_PRICEa(probs[m], bit);
		m = (m << 1) | bit;
	}
	return price;
}

static uint32_t __LZMA_RcTree_GetPrice(const uint16_t *probs, int numBitLevels, uint32_t symbol, const uint32_t *ProbPrices) {
	uint32_t price = 0;
	symbol |= (1 << numBitLevels);
	while (symbol != 1)
	{
		price += __LZMA_GET_PRICEa(probs[symbol >> 1], symbol & 1);
		symbol >>= 1;
	}
	return price;
}

static void __LZMA_FillDistancesPrices(__LZMA_CLzmaEnc *p) {
	uint32_t tempPrices[__LZMA_kNumFullDistances];
	uint32_t lenToPosState;
	for (uint32_t i = __LZMA_kStartPosModelIndex; i < __LZMA_kNumFullDistances; i++)
	{
		uint32_t posSlot = __LZMA_GetPosSlot1(i);
		uint32_t footerBits = ((posSlot >> 1) - 1);
		uint32_t base = ((2 | (posSlot & 1)) << footerBits);
		tempPrices[i] = __LZMA_RcTree_ReverseGetPrice(p->posEncoders + base - posSlot - 1, footerBits, i - base, p->ProbPrices);
	}

	for (lenToPosState = 0; lenToPosState < __LZMA_kNumLenToPosStates; lenToPosState++)
	{
		const uint16_t *encoder = p->posSlotEncoder[lenToPosState];
		uint32_t *posSlotPrices = p->posSlotPrices[lenToPosState];
		for (uint32_t posSlot = 0; posSlot < p->distTableSize; posSlot++)
			posSlotPrices[posSlot] = __LZMA_RcTree_GetPrice(encoder, __LZMA_kNumPosSlotBits, posSlot, p->ProbPrices);
		for (uint32_t posSlot = __LZMA_kEndPosModelIndex; posSlot < p->distTableSize; posSlot++)
			posSlotPrices[posSlot] += ((((posSlot >> 1) - 1) - __LZMA_kNumAlignBits) << __LZMA_kNumBitPriceShiftBits);

		{
			uint32_t *distancesPrices = p->distancesPrices[lenToPosState];
			uint32_t i;
			for (i = 0; i < __LZMA_kStartPosModelIndex; i++) distancesPrices[i] = posSlotPrices[i];
			for (; i < __LZMA_kNumFullDistances; i++) distancesPrices[i] = posSlotPrices[__LZMA_GetPosSlot1(i)] + tempPrices[i];
		}
	}
	p->matchPriceCount = 0;
}

static void __LZMA_FillAlignPrices(__LZMA_CLzmaEnc *p) {
	for (uint32_t i = 0; i < __LZMA_kAlignTableSize; i++) p->alignPrices[i] = __LZMA_RcTree_ReverseGetPrice(p->posAlignEncoder, __LZMA_kNumAlignBits, i, p->ProbPrices);
	p->alignPriceCount = 0;
}

#define __LZMA_GET_PRICE_0a(prob) ProbPrices[(prob) >> __LZMA_kNumMoveReducingBits]
#define __LZMA_GET_PRICE_1a(prob) ProbPrices[((prob) ^ (__LZMA_kBitModelTotal - 1)) >> __LZMA_kNumMoveReducingBits]

static void __LZMA_LenEnc_SetPrices(__LZMA_CLenEnc *p, uint32_t posState, uint32_t numSymbols, uint32_t *prices, const uint32_t *ProbPrices) {
	uint32_t a0 = __LZMA_GET_PRICE_0a(p->choice);
	uint32_t a1 = __LZMA_GET_PRICE_1a(p->choice);
	uint32_t b0 = a1 + __LZMA_GET_PRICE_0a(p->choice2);
	uint32_t b1 = a1 + __LZMA_GET_PRICE_1a(p->choice2);
	uint32_t i = 0;
	for (i = 0; i < __LZMA_kLenNumLowSymbols; i++)
	{
		if (i >= numSymbols) return;
		prices[i] = a0 + __LZMA_RcTree_GetPrice(p->low + (posState << __LZMA_kLenNumLowBits), __LZMA_kLenNumLowBits, i, ProbPrices);
	}
	for (; i < __LZMA_kLenNumLowSymbols + __LZMA_kLenNumMidSymbols; i++)
	{
		if (i >= numSymbols) return;
		prices[i] = b0 + __LZMA_RcTree_GetPrice(p->mid + (posState << __LZMA_kLenNumMidBits), __LZMA_kLenNumMidBits, i - __LZMA_kLenNumLowSymbols, ProbPrices);
	}
	for (; i < numSymbols; i++)
		prices[i] = b1 + __LZMA_RcTree_GetPrice(p->high, __LZMA_kLenNumHighBits, i - __LZMA_kLenNumLowSymbols - __LZMA_kLenNumMidSymbols, ProbPrices);
}

static void __LZMA_LenPriceEnc_UpdateTable(__LZMA_CLenPriceEnc *p, uint32_t posState, const uint32_t *ProbPrices) {
	__LZMA_LenEnc_SetPrices(&p->p, posState, p->tableSize, p->prices[posState], ProbPrices);
	p->counters[posState] = p->tableSize;
}

static void __LZMA_LenPriceEnc_UpdateTables(__LZMA_CLenPriceEnc *p, uint32_t numPosStates, const uint32_t *ProbPrices) {
	for (uint32_t posState = 0; posState < numPosStates; posState++) __LZMA_LenPriceEnc_UpdateTable(p, posState, ProbPrices);
}

static void __LZMA_LzmaEnc_InitPrices(__LZMA_CLzmaEnc *p) {
	if (!p->fastMode)
	{
		__LZMA_FillDistancesPrices(p);
		__LZMA_FillAlignPrices(p);
	}
	p->lenEnc.tableSize = p->repLenEnc.tableSize = p->numFastBytes + 1 - __LZMA_MATCH_LEN_MIN;
	__LZMA_LenPriceEnc_UpdateTables(&p->lenEnc, 1 << p->pb, p->ProbPrices);
	__LZMA_LenPriceEnc_UpdateTables(&p->repLenEnc, 1 << p->pb, p->ProbPrices);
}

static int __LZMA_LzmaEnc_AllocAndInit(__LZMA_CLzmaEnc *p, uint32_t keepWindowSize, __LZMA_ISzAlloc *alloc, __LZMA_ISzAlloc *allocBig) {
	uint32_t i;
	for (i = 0; i < (uint32_t)__LZMA_kDicLogSizeMaxCompress; i++)
		if (p->dictSize <= ((uint32_t)1 << i))
			break;
	p->distTableSize = i * 2;
	p->finished = 0;
	p->result = __LZMA_SZ_OK;
	__LZMA_RINOK(__LZMA_LzmaEnc_Alloc(p, keepWindowSize, alloc, allocBig));
	__LZMA_LzmaEnc_Init(p);
	__LZMA_LzmaEnc_InitPrices(p);
	p->nowPos64 = 0;
	return __LZMA_SZ_OK;
}

static int __LZMA_LzmaEnc_MemPrepare(__LZMA_CLzmaEncHandle pp, const uint8_t *src, size_t srcLen,
									 uint32_t keepWindowSize, __LZMA_ISzAlloc *alloc, __LZMA_ISzAlloc *allocBig) {
	__LZMA_CLzmaEnc *p = (__LZMA_CLzmaEnc *)pp;
	__LZMA_LzmaEnc_SetInputBuf(p, src, srcLen);
	p->needInit = 1;
	return __LZMA_LzmaEnc_AllocAndInit(p, keepWindowSize, alloc, allocBig);
}

static int __LZMA_CheckErrors(__LZMA_CLzmaEnc *p) {
	if (p->result != __LZMA_SZ_OK) return p->result;
	if (p->rc.res != __LZMA_SZ_OK) p->result = __LZMA_SZ_ERROR_WRITE;
	if (p->matchFinderBase.result != __LZMA_SZ_OK) p->result = __LZMA_SZ_ERROR_READ;
	if (p->result != __LZMA_SZ_OK) p->finished = 1;
	return p->result;
}

static void __LZMA_RangeEnc_FlushStream(__LZMA_CRangeEnc *p) {
	size_t num;
	if (p->res != __LZMA_SZ_OK) return;
	num = p->buf - p->bufBase;
	if (num != p->outStream->Write(p->outStream, p->bufBase, num)) p->res = __LZMA_SZ_ERROR_WRITE;
	p->processed += num;
	p->buf = p->bufBase;
}

static void __LZMA_RangeEnc_ShiftLow(__LZMA_CRangeEnc *p) {
	if ((uint32_t)p->low < (uint32_t)0xFF000000 || (unsigned)(p->low >> 32) != 0)
	{
		uint8_t temp = p->cache;
		do {
			uint8_t *buf = p->buf;
			*buf++ = (uint8_t)(temp + (uint8_t)(p->low >> 32));
			p->buf = buf;
			if (buf == p->bufLim) __LZMA_RangeEnc_FlushStream(p);
			temp = 0xFF;
		} while (--p->cacheSize != 0);
		p->cache = (uint8_t)((uint32_t)p->low >> 24);
	}
	p->cacheSize++;
	p->low = (uint32_t)p->low << 8;
}

static void __LZMA_RangeEnc_EncodeBit(__LZMA_CRangeEnc *p, uint16_t *prob, uint32_t symbol) {
	uint32_t ttt = *prob;
	uint32_t newBound = (p->range >> __LZMA_kNumBitModelTotalBits) * ttt;
	if (symbol == 0)
	{
		p->range = newBound;
		ttt += (__LZMA_kBitModelTotal - ttt) >> __LZMA_kNumMoveBits;
	}
	else
	{
		p->low += newBound;
		p->range -= newBound;
		ttt -= ttt >> __LZMA_kNumMoveBits;
	}
	*prob = (uint16_t)ttt;
	if (p->range < __LZMA_kTopValue)
	{
		p->range <<= 8;
		__LZMA_RangeEnc_ShiftLow(p);
	}
}

static void __LZMA_RcTree_Encode(__LZMA_CRangeEnc *rc, uint16_t *probs, int numBitLevels, uint32_t symbol) {
	uint32_t m = 1;
	for (int i = numBitLevels; i != 0;)
	{
		uint32_t bit;
		i--;
		bit = (symbol >> i) & 1;
		__LZMA_RangeEnc_EncodeBit(rc, probs + m, bit);
		m = (m << 1) | bit;
	}
}

static void __LZMA_LenEnc_Encode(__LZMA_CLenEnc *p, __LZMA_CRangeEnc *rc, uint32_t symbol, uint32_t posState) {
	if (symbol < __LZMA_kLenNumLowSymbols)
	{
		__LZMA_RangeEnc_EncodeBit(rc, &p->choice, 0);
		__LZMA_RcTree_Encode(rc, p->low + (posState << __LZMA_kLenNumLowBits), __LZMA_kLenNumLowBits, symbol);
	}
	else
	{
		__LZMA_RangeEnc_EncodeBit(rc, &p->choice, 1);
		if (symbol < __LZMA_kLenNumLowSymbols + __LZMA_kLenNumMidSymbols)
		{
			__LZMA_RangeEnc_EncodeBit(rc, &p->choice2, 0);
			__LZMA_RcTree_Encode(rc, p->mid + (posState << __LZMA_kLenNumMidBits), __LZMA_kLenNumMidBits, symbol - __LZMA_kLenNumLowSymbols);
		}
		else
		{
			__LZMA_RangeEnc_EncodeBit(rc, &p->choice2, 1);
			__LZMA_RcTree_Encode(rc, p->high, __LZMA_kLenNumHighBits, symbol - __LZMA_kLenNumLowSymbols - __LZMA_kLenNumMidSymbols);
		}
	}
}

static void __LZMA_LenEnc_Encode2(__LZMA_CLenPriceEnc *p, __LZMA_CRangeEnc *rc, uint32_t symbol, uint32_t posState, uint8_t updatePrice, const uint32_t *ProbPrices) {
	__LZMA_LenEnc_Encode(&p->p, rc, symbol, posState);
	if (updatePrice)
		if (--p->counters[posState] == 0)
			__LZMA_LenPriceEnc_UpdateTable(p, posState, ProbPrices);
}

#define __LZMA_GetLenToPosState(len) (((len) < __LZMA_kNumLenToPosStates + 1) ? (len) - 2 : __LZMA_kNumLenToPosStates - 1)

static void __LZMA_RangeEnc_EncodeDirectBits(__LZMA_CRangeEnc *p, uint32_t value, unsigned numBits) {
	do {
		p->range >>= 1;
		p->low += p->range & (0 - ((value >> --numBits) & 1));
		if (p->range < __LZMA_kTopValue)
		{
			p->range <<= 8;
			__LZMA_RangeEnc_ShiftLow(p);
		}
	} while (numBits != 0);
}

static void __LZMA_RcTree_ReverseEncode(__LZMA_CRangeEnc *rc, uint16_t *probs, int numBitLevels, uint32_t symbol) {
	uint32_t m = 1;
	for (int i = 0; i < numBitLevels; i++)
	{
		uint32_t bit = symbol & 1;
		__LZMA_RangeEnc_EncodeBit(rc, probs + m, bit);
		m = (m << 1) | bit;
		symbol >>= 1;
	}
}

static void __LZMA_WriteEndMarker(__LZMA_CLzmaEnc *p, uint32_t posState) {
	uint32_t len;
	__LZMA_RangeEnc_EncodeBit(&p->rc, &p->isMatch[p->state][posState], 1);
	__LZMA_RangeEnc_EncodeBit(&p->rc, &p->isRep[p->state], 0);
	const int kMatchNextStates[__LZMA_kNumStates] = {7, 7, 7, 7, 7, 7, 7, 10, 10, 10, 10, 10};
	p->state = kMatchNextStates[p->state];
	len = __LZMA_MATCH_LEN_MIN;
	__LZMA_LenEnc_Encode2(&p->lenEnc, &p->rc, len - __LZMA_MATCH_LEN_MIN, posState, !p->fastMode, p->ProbPrices);
	__LZMA_RcTree_Encode(&p->rc, p->posSlotEncoder[__LZMA_GetLenToPosState(len)], __LZMA_kNumPosSlotBits, (1 << __LZMA_kNumPosSlotBits) - 1);
	__LZMA_RangeEnc_EncodeDirectBits(&p->rc, (((uint32_t)1 << 30) - 1) >> __LZMA_kNumAlignBits, 30 - __LZMA_kNumAlignBits);
	__LZMA_RcTree_ReverseEncode(&p->rc, p->posAlignEncoder, __LZMA_kNumAlignBits, __LZMA_kAlignMask);
}

static void __LZMA_RangeEnc_FlushData(__LZMA_CRangeEnc *p) {
	for (int i = 0; i < 5; i++) __LZMA_RangeEnc_ShiftLow(p);
}

static int __LZMA_Flush(__LZMA_CLzmaEnc *p, uint32_t nowPos) {
	p->finished = 1;
	if (p->writeEndMark) __LZMA_WriteEndMarker(p, nowPos & p->pbMask);
	__LZMA_RangeEnc_FlushData(&p->rc);
	__LZMA_RangeEnc_FlushStream(&p->rc);
	return __LZMA_CheckErrors(p);
}

static uint32_t __LZMA_ReadMatchDistances(__LZMA_CLzmaEnc *p, uint32_t *numDistancePairsRes) {
	uint32_t lenRes = 0, numPairs;
	p->numAvail = p->matchFinder.GetNumAvailableBytes(p->matchFinderObj);
	numPairs = p->matchFinder.GetMatches(p->matchFinderObj, p->matches);
	if (numPairs > 0)
	{
		lenRes = p->matches[numPairs - 2];
		if (lenRes == p->numFastBytes)
		{
			uint32_t numAvail = p->numAvail;
			if (numAvail > __LZMA_MATCH_LEN_MAX)
				numAvail = __LZMA_MATCH_LEN_MAX;
			{
				const uint8_t *pbyCur = p->matchFinder.GetPointerToCurrentPos(p->matchFinderObj) - 1;
				const uint8_t *pby = pbyCur + lenRes;
				ptrdiff_t dif = (ptrdiff_t)-1 - p->matches[numPairs - 1];
				const uint8_t *pbyLim = pbyCur + numAvail;
				for (; pby != pbyLim && *pby == pby[dif]; pby++);
				lenRes = (uint32_t)(pby - pbyCur);
			}
		}
	}
	p->additionalOffset++;
	*numDistancePairsRes = numPairs;
	return lenRes;
}

static void __LZMA_LitEnc_Encode(__LZMA_CRangeEnc *p, uint16_t *probs, uint32_t symbol) {
	symbol |= 0x100;
	do {
		__LZMA_RangeEnc_EncodeBit(p, probs + (symbol >> 8), (symbol >> 7) & 1);
		symbol <<= 1;
	} while (symbol < 0x10000);
}

static void __LZMA_MovePos(__LZMA_CLzmaEnc *p, uint32_t num) {
	if (num != 0)
	{
		p->additionalOffset += num;
		p->matchFinder.Skip(p->matchFinderObj, num);
	}
}

static uint32_t __LZMA_GetOptimumFast(__LZMA_CLzmaEnc *p, uint32_t *backRes) {
	uint32_t numAvail, mainLen, mainDist, numPairs, repIndex, repLen, i;
	if (p->additionalOffset == 0) mainLen = __LZMA_ReadMatchDistances(p, &numPairs);
	else
	{
		mainLen = p->longestMatchLength;
		numPairs = p->numPairs;
	}

	numAvail = p->numAvail;
	*backRes = (uint32_t)-1;
	if (numAvail < 2) return 1;
	if (numAvail > __LZMA_MATCH_LEN_MAX) numAvail = __LZMA_MATCH_LEN_MAX;
	const uint8_t * data = p->matchFinder.GetPointerToCurrentPos(p->matchFinderObj) - 1;

	repLen = repIndex = 0;
	for (i = 0; i < __LZMA_NUM_REPS; i++)
	{
		uint32_t len;
		const uint8_t *data2 = data - p->reps[i] - 1;
		if (data[0] != data2[0] || data[1] != data2[1]) continue;
		for (len = 2; len < numAvail && data[len] == data2[len]; len++);
		if (len >= p->numFastBytes)
		{
			*backRes = i;
			__LZMA_MovePos(p, len - 1);
			return len;
		}
		if (len > repLen)
		{
			repIndex = i;
			repLen = len;
		}
	}
	const uint32_t * matches = p->matches;
	if (mainLen >= p->numFastBytes)
	{
		*backRes = matches[numPairs - 1] + __LZMA_NUM_REPS;
		__LZMA_MovePos(p, mainLen - 1);
		return mainLen;
	}
	mainDist = 0;
	if (mainLen >= 2)
	{
		mainDist = matches[numPairs - 1];
		while (numPairs > 2 && mainLen == matches[numPairs - 4] + 1)
		{
			if (!__LZMA_ChangePair(matches[numPairs - 3], mainDist)) break;
			numPairs -= 2;
			mainLen = matches[numPairs - 2];
			mainDist = matches[numPairs - 1];
		}
		if (mainLen == 2 && mainDist >= 0x80) mainLen = 1;
	}
	if (repLen >= 2 && (
						(repLen + 1 >= mainLen) ||
						(repLen + 2 >= mainLen && mainDist >= (1 << 9)) ||
						(repLen + 3 >= mainLen && mainDist >= (1 << 15))))
	{
		*backRes = repIndex;
		__LZMA_MovePos(p, repLen - 1);
		return repLen;
	}
	if (mainLen < 2 || numAvail <= 2) return 1;
	p->longestMatchLength = __LZMA_ReadMatchDistances(p, &p->numPairs);
	if (p->longestMatchLength >= 2)
	{
		uint32_t newDistance = matches[p->numPairs - 1];
		if ((p->longestMatchLength >= mainLen && newDistance < mainDist) ||
			(p->longestMatchLength == mainLen + 1 && !__LZMA_ChangePair(mainDist, newDistance)) ||
			(p->longestMatchLength > mainLen + 1) ||
			(p->longestMatchLength + 1 >= mainLen && mainLen >= 3 && __LZMA_ChangePair(newDistance, mainDist)))
			return 1;
	}
	data = p->matchFinder.GetPointerToCurrentPos(p->matchFinderObj) - 1;
	for (i = 0; i < __LZMA_NUM_REPS; i++)
	{
		uint32_t len, limit;
		const uint8_t *data2 = data - p->reps[i] - 1;
		if (data[0] != data2[0] || data[1] != data2[1]) continue;
		limit = mainLen - 1;
		for (len = 2; len < limit && data[len] == data2[len]; len++);
		if (len >= limit) return 1;
	}
	*backRes = mainDist + __LZMA_NUM_REPS;
	__LZMA_MovePos(p, mainLen - 2);
	return mainLen;
}

#define __LZMA_LIT_PROBS(pos, prevByte) (p->litProbs + ((((pos) & p->lpMask) << p->lc) + ((prevByte) >> (8 - p->lc))) * (uint32_t)0x300)
#define __LZMA_GET_PRICE_0(prob) p->ProbPrices[(prob) >> __LZMA_kNumMoveReducingBits]
#define __LZMA_IsCharState(s) ((s) < 7)

static uint32_t __LZMA_LitEnc_GetPriceMatched(const uint16_t *probs, uint32_t symbol, uint32_t matchByte, const uint32_t *ProbPrices) {
	uint32_t price = 0;
	uint32_t offs = 0x100;
	symbol |= 0x100;
	do {
		matchByte <<= 1;
		price += __LZMA_GET_PRICEa(probs[offs + (matchByte & offs) + (symbol >> 8)], (symbol >> 7) & 1);
		symbol <<= 1;
		offs &= ~(matchByte ^ symbol);
	} while (symbol < 0x10000);
	return price;
}

static uint32_t __LZMA_LitEnc_GetPrice(const uint16_t *probs, uint32_t symbol, const uint32_t *ProbPrices) {
	uint32_t price = 0;
	symbol |= 0x100;
	do {
		price += __LZMA_GET_PRICEa(probs[symbol >> 8], (symbol >> 7) & 1);
		symbol <<= 1;
	} while (symbol < 0x10000);
	return price;
}

#define __LZMA_MakeAsChar(p) (p)->backPrev = (uint32_t)(-1); (p)->prev1IsChar = 0;
#define __LZMA_GET_PRICE_1(prob) p->ProbPrices[((prob) ^ (__LZMA_kBitModelTotal - 1)) >> __LZMA_kNumMoveReducingBits]
#define __LZMA_MakeAsShortRep(p) (p)->backPrev = 0; (p)->prev1IsChar = 0;
#define __LZMA_GET_PRICE(prob, symbol) \
p->ProbPrices[((prob) ^ (((-(int)(symbol))) & (__LZMA_kBitModelTotal - 1))) >> __LZMA_kNumMoveReducingBits];

static uint32_t __LZMA_GetRepLen1Price(__LZMA_CLzmaEnc *p, uint32_t state, uint32_t posState) {
	return (__LZMA_GET_PRICE_0(p->isRepG0[state]) + __LZMA_GET_PRICE_0(p->isRep0Long[state][posState]));
}

static uint32_t __LZMA_GetPureRepPrice(__LZMA_CLzmaEnc *p, uint32_t repIndex, uint32_t state, uint32_t posState) {
	uint32_t price;
	if (repIndex == 0)
	{
		price = __LZMA_GET_PRICE_0(p->isRepG0[state]);
		price += __LZMA_GET_PRICE_1(p->isRep0Long[state][posState]);
	}
	else
	{
		price = __LZMA_GET_PRICE_1(p->isRepG0[state]);
		if (repIndex == 1) price += __LZMA_GET_PRICE_0(p->isRepG1[state]);
		else
		{
			price += __LZMA_GET_PRICE_1(p->isRepG1[state]);
			price += __LZMA_GET_PRICE(p->isRepG2[state], repIndex - 2);
		}
	}
	return price;
}

static uint32_t __LZMA_Backward(__LZMA_CLzmaEnc *p, uint32_t *backRes, uint32_t cur) {
	uint32_t posMem = p->opt[cur].posPrev;
	uint32_t backMem = p->opt[cur].backPrev;
	p->optimumEndIndex = cur;
	do {
		if (p->opt[cur].prev1IsChar)
		{
			__LZMA_MakeAsChar(&p->opt[posMem])
			p->opt[posMem].posPrev = posMem - 1;
			if (p->opt[cur].prev2)
			{
				p->opt[posMem - 1].prev1IsChar = 0;
				p->opt[posMem - 1].posPrev = p->opt[cur].posPrev2;
				p->opt[posMem - 1].backPrev = p->opt[cur].backPrev2;
			}
		}
		{
			uint32_t posPrev = posMem;
			uint32_t backCur = backMem;
			backMem = p->opt[posPrev].backPrev;
			posMem = p->opt[posPrev].posPrev;
			p->opt[posPrev].backPrev = backCur;
			p->opt[posPrev].posPrev = cur;
			cur = posPrev;
		}
	} while (cur != 0);
	*backRes = p->opt[0].backPrev;
	p->optimumCurrentIndex  = p->opt[0].posPrev;
	return p->optimumCurrentIndex;
}

#define __LZMA_IsShortRep(p) ((p)->backPrev == 0)

static uint32_t __LZMA_GetRepPrice(__LZMA_CLzmaEnc *p, uint32_t repIndex, uint32_t len, uint32_t state, uint32_t posState) {
	return (p->repLenEnc.prices[posState][len - __LZMA_MATCH_LEN_MIN] + __LZMA_GetPureRepPrice(p, repIndex, state, posState));
}

static uint32_t __LZMA_GetOptimum(__LZMA_CLzmaEnc *p, uint32_t position, uint32_t *backRes) {
	uint32_t numAvail, mainLen, numPairs, repMaxIndex, i, posState, lenEnd, len, cur;
	uint32_t matchPrice, repMatchPrice, normalMatchPrice;
	uint32_t reps[__LZMA_NUM_REPS], repLens[__LZMA_NUM_REPS];
	uint32_t *matches;
	uint8_t curByte, matchByte;
	if (p->optimumEndIndex != p->optimumCurrentIndex)
	{
		const __LZMA_COptimal *opt = &p->opt[p->optimumCurrentIndex];
		uint32_t lenRes = opt->posPrev - p->optimumCurrentIndex;
		*backRes = opt->backPrev;
		p->optimumCurrentIndex = opt->posPrev;
		return lenRes;
	}
	p->optimumCurrentIndex = p->optimumEndIndex = 0;
	if (p->additionalOffset == 0) mainLen = __LZMA_ReadMatchDistances(p, &numPairs);
	else
	{
		mainLen = p->longestMatchLength;
		numPairs = p->numPairs;
	}
	numAvail = p->numAvail;
	if (numAvail < 2)
	{
		*backRes = (uint32_t)(-1);
		return 1;
	}
	if (numAvail > __LZMA_MATCH_LEN_MAX) numAvail = __LZMA_MATCH_LEN_MAX;
	const uint8_t *data = p->matchFinder.GetPointerToCurrentPos(p->matchFinderObj) - 1;
	repMaxIndex = 0;
	for (i = 0; i < __LZMA_NUM_REPS; i++)
	{
		uint32_t lenTest;
		reps[i] = p->reps[i];
		const uint8_t *data2 = data - reps[i] - 1;
		if (data[0] != data2[0] || data[1] != data2[1])
		{
			repLens[i] = 0;
			continue;
		}
		for (lenTest = 2; lenTest < numAvail && data[lenTest] == data2[lenTest]; lenTest++);
		repLens[i] = lenTest;
		if (lenTest > repLens[repMaxIndex]) repMaxIndex = i;
	}
	if (repLens[repMaxIndex] >= p->numFastBytes)
	{
		*backRes = repMaxIndex;
		uint32_t lenRes = repLens[repMaxIndex];
		__LZMA_MovePos(p, lenRes - 1);
		return lenRes;
	}
	matches = p->matches;
	if (mainLen >= p->numFastBytes)
	{
		*backRes = matches[numPairs - 1] + __LZMA_NUM_REPS;
		__LZMA_MovePos(p, mainLen - 1);
		return mainLen;
	}
	curByte = *data;
	matchByte = *(data - (reps[0] + 1));
	if (mainLen < 2 && curByte != matchByte && repLens[repMaxIndex] < 2)
	{
		*backRes = (uint32_t)-1;
		return 1;
	}
	p->opt[0].state = (__LZMA_CState)p->state;
	posState = (position & p->pbMask);

	{
		const uint16_t *probs = __LZMA_LIT_PROBS(position, *(data - 1));
		p->opt[1].price = __LZMA_GET_PRICE_0(p->isMatch[p->state][posState]) +
		(!__LZMA_IsCharState(p->state) ?
		 __LZMA_LitEnc_GetPriceMatched(probs, curByte, matchByte, p->ProbPrices) :
		 __LZMA_LitEnc_GetPrice(probs, curByte, p->ProbPrices));
	}
	__LZMA_MakeAsChar(&p->opt[1]);
	matchPrice = __LZMA_GET_PRICE_1(p->isMatch[p->state][posState]);
	repMatchPrice = matchPrice + __LZMA_GET_PRICE_1(p->isRep[p->state]);
	if (matchByte == curByte)
	{
		uint32_t shortRepPrice = repMatchPrice + __LZMA_GetRepLen1Price(p, p->state, posState);
		if (shortRepPrice < p->opt[1].price)
		{
			p->opt[1].price = shortRepPrice;
			__LZMA_MakeAsShortRep(&p->opt[1]);
		}
	}
	lenEnd = ((mainLen >= repLens[repMaxIndex]) ? mainLen : repLens[repMaxIndex]);
	if (lenEnd < 2)
	{
		*backRes = p->opt[1].backPrev;
		return 1;
	}
	p->opt[1].posPrev = 0;
	for (i = 0; i < __LZMA_NUM_REPS; i++) p->opt[0].backs[i] = reps[i];
	len = lenEnd;
	do { p->opt[len--].price = __LZMA_kInfinityPrice; }	while (len >= 2);
	for (i = 0; i < __LZMA_NUM_REPS; i++)
	{
		uint32_t repLen = repLens[i];
		if (repLen < 2) continue;
		uint32_t price = repMatchPrice + __LZMA_GetPureRepPrice(p, i, p->state, posState);
		do {
			uint32_t curAndLenPrice = price + p->repLenEnc.prices[posState][repLen - 2];
			__LZMA_COptimal *opt = &p->opt[repLen];
			if (curAndLenPrice < opt->price)
			{
				opt->price = curAndLenPrice;
				opt->posPrev = 0;
				opt->backPrev = i;
				opt->prev1IsChar = 0;
			}
		} while (--repLen >= 2);
	}
	normalMatchPrice = matchPrice + __LZMA_GET_PRICE_0(p->isRep[p->state]);
	len = ((repLens[0] >= 2) ? repLens[0] + 1 : 2);
	if (len <= mainLen)
	{
		uint32_t offs = 0;
		while (len > matches[offs]) offs += 2;
		for (; ; len++)
		{
			uint32_t distance = matches[offs + 1];
			uint32_t curAndLenPrice = normalMatchPrice + p->lenEnc.prices[posState][len - __LZMA_MATCH_LEN_MIN];
			uint32_t lenToPosState = __LZMA_GetLenToPosState(len);
			if (distance < __LZMA_kNumFullDistances)
				curAndLenPrice += p->distancesPrices[lenToPosState][distance];
			else
			{
				uint32_t slot;
				__LZMA_GetPosSlot2(distance, slot);
				curAndLenPrice += p->alignPrices[distance & __LZMA_kAlignMask] + p->posSlotPrices[lenToPosState][slot];
			}
			__LZMA_COptimal *opt = &p->opt[len];
			if (curAndLenPrice < opt->price)
			{
				opt->price = curAndLenPrice;
				opt->posPrev = 0;
				opt->backPrev = distance + __LZMA_NUM_REPS;
				opt->prev1IsChar = 0;
			}
			if (len == matches[offs])
			{
				offs += 2;
				if (offs == numPairs) break;
			}
		}
	}
	cur = 0;
	const int kRepNextStates[__LZMA_kNumStates] = {8, 8, 8, 8, 8, 8, 8, 11, 11, 11, 11, 11};
	const int kMatchNextStates[__LZMA_kNumStates] = {7, 7, 7, 7, 7, 7, 7, 10, 10, 10, 10, 10};
	const int kLiteralNextStates[__LZMA_kNumStates] = {0, 0, 0, 0, 1, 2, 3, 4,  5,  6,   4, 5};
	const int kShortRepNextStates[__LZMA_kNumStates] = {9, 9, 9, 9, 9, 9, 9, 11, 11, 11, 11, 11};
	for (;;)
	{
		uint32_t numAvailFull, newLen, numPairs, posPrev, state, posState, startLen;
		uint32_t curPrice, curAnd1Price, matchPrice, repMatchPrice;
		uint8_t nextIsChar;
		uint8_t curByte, matchByte;
		const uint8_t *data;
		cur++;
		if (cur == lenEnd) return __LZMA_Backward(p, backRes, cur);
		newLen = __LZMA_ReadMatchDistances(p, &numPairs);
		if (newLen >= p->numFastBytes)
		{
			p->numPairs = numPairs;
			p->longestMatchLength = newLen;
			return __LZMA_Backward(p, backRes, cur);
		}
		position++;
		__LZMA_COptimal *curOpt = &p->opt[cur];
		posPrev = curOpt->posPrev;
		if (curOpt->prev1IsChar)
		{
			posPrev--;
			if (curOpt->prev2)
			{
				state = p->opt[curOpt->posPrev2].state;
				if (curOpt->backPrev2 < __LZMA_NUM_REPS) state = kRepNextStates[state];
				else state = kMatchNextStates[state];
			}
			else state = p->opt[posPrev].state;
			state = kLiteralNextStates[state];
		}
		else state = p->opt[posPrev].state;
		if (posPrev == cur - 1)
		{
			if (__LZMA_IsShortRep(curOpt)) state = kShortRepNextStates[state];
			else state = kLiteralNextStates[state];
		}
		else
		{
			uint32_t pos;
			const __LZMA_COptimal *prevOpt;
			if (curOpt->prev1IsChar && curOpt->prev2)
			{
				posPrev = curOpt->posPrev2;
				pos = curOpt->backPrev2;
				state = kRepNextStates[state];
			}
			else
			{
				pos = curOpt->backPrev;
				if (pos < __LZMA_NUM_REPS) state = kRepNextStates[state];
				else state = kMatchNextStates[state];
			}
			prevOpt = &p->opt[posPrev];
			if (pos < __LZMA_NUM_REPS)
			{
				uint32_t i;
				reps[0] = prevOpt->backs[pos];
				for (i = 1; i <= pos; i++) reps[i] = prevOpt->backs[i - 1];
				for (; i < __LZMA_NUM_REPS; i++) reps[i] = prevOpt->backs[i];
			}
			else
			{
				uint32_t i;
				reps[0] = (pos - __LZMA_NUM_REPS);
				for (i = 1; i < __LZMA_NUM_REPS; i++) reps[i] = prevOpt->backs[i - 1];
			}
		}
		curOpt->state = (__LZMA_CState)state;
		curOpt->backs[0] = reps[0];
		curOpt->backs[1] = reps[1];
		curOpt->backs[2] = reps[2];
		curOpt->backs[3] = reps[3];
		curPrice = curOpt->price;
		nextIsChar = 0;
		data = p->matchFinder.GetPointerToCurrentPos(p->matchFinderObj) - 1;
		curByte = *data;
		matchByte = *(data - (reps[0] + 1));
		posState = (position & p->pbMask);
		curAnd1Price = curPrice + __LZMA_GET_PRICE_0(p->isMatch[state][posState]);
		{
			const uint16_t *probs = __LZMA_LIT_PROBS(position, *(data - 1));
			curAnd1Price +=
			(!__LZMA_IsCharState(state) ?
			 __LZMA_LitEnc_GetPriceMatched(probs, curByte, matchByte, p->ProbPrices) :
			 __LZMA_LitEnc_GetPrice(probs, curByte, p->ProbPrices));
		}
		__LZMA_COptimal *nextOpt = &p->opt[cur + 1];
		if (curAnd1Price < nextOpt->price)
		{
			nextOpt->price = curAnd1Price;
			nextOpt->posPrev = cur;
			__LZMA_MakeAsChar(nextOpt);
			nextIsChar = 1;
		}
		matchPrice = curPrice + __LZMA_GET_PRICE_1(p->isMatch[state][posState]);
		repMatchPrice = matchPrice + __LZMA_GET_PRICE_1(p->isRep[state]);
		if (matchByte == curByte && !(nextOpt->posPrev < cur && nextOpt->backPrev == 0))
		{
			uint32_t shortRepPrice = repMatchPrice + __LZMA_GetRepLen1Price(p, state, posState);
			if (shortRepPrice <= nextOpt->price)
			{
				nextOpt->price = shortRepPrice;
				nextOpt->posPrev = cur;
				__LZMA_MakeAsShortRep(nextOpt);
				nextIsChar = 1;
			}
		}
		numAvailFull = p->numAvail;
		{
			uint32_t temp = __LZMA_kNumOpts - 1 - cur;
			if (temp < numAvailFull) numAvailFull = temp;
		}
		if (numAvailFull < 2) continue;
		numAvail = (numAvailFull <= p->numFastBytes ? numAvailFull : p->numFastBytes);
		if (!nextIsChar && matchByte != curByte)
		{
			uint32_t temp;
			uint32_t lenTest2;
			const uint8_t *data2 = data - reps[0] - 1;
			uint32_t limit = p->numFastBytes + 1;
			if (limit > numAvailFull) limit = numAvailFull;
			for (temp = 1; temp < limit && data[temp] == data2[temp]; temp++);
			lenTest2 = temp - 1;
			if (lenTest2 >= 2)
			{
				uint32_t state2 = kLiteralNextStates[state];
				uint32_t posStateNext = (position + 1) & p->pbMask;
				uint32_t nextRepMatchPrice = curAnd1Price +
				__LZMA_GET_PRICE_1(p->isMatch[state2][posStateNext]) +
				__LZMA_GET_PRICE_1(p->isRep[state2]);
				{
					uint32_t curAndLenPrice;
					__LZMA_COptimal *opt;
					uint32_t offset = cur + 1 + lenTest2;
					while (lenEnd < offset) p->opt[++lenEnd].price = __LZMA_kInfinityPrice;
					curAndLenPrice = nextRepMatchPrice + __LZMA_GetRepPrice(p, 0, lenTest2, state2, posStateNext);
					opt = &p->opt[offset];
					if (curAndLenPrice < opt->price)
					{
						opt->price = curAndLenPrice;
						opt->posPrev = cur + 1;
						opt->backPrev = 0;
						opt->prev1IsChar = 1;
						opt->prev2 = 0;
					}
				}
			}
		}
		startLen = 2;
		{
			uint32_t repIndex;
			for (repIndex = 0; repIndex < __LZMA_NUM_REPS; repIndex++)
			{
				uint32_t lenTest;
				uint32_t lenTestTemp;
				uint32_t price;
				const uint8_t *data2 = data - reps[repIndex] - 1;
				if (data[0] != data2[0] || data[1] != data2[1]) continue;
				for (lenTest = 2; lenTest < numAvail && data[lenTest] == data2[lenTest]; lenTest++);
				while (lenEnd < cur + lenTest) p->opt[++lenEnd].price = __LZMA_kInfinityPrice;
				lenTestTemp = lenTest;
				price = repMatchPrice + __LZMA_GetPureRepPrice(p, repIndex, state, posState);
				do {
					uint32_t curAndLenPrice = price + p->repLenEnc.prices[posState][lenTest - 2];
					__LZMA_COptimal *opt = &p->opt[cur + lenTest];
					if (curAndLenPrice < opt->price)
					{
						opt->price = curAndLenPrice;
						opt->posPrev = cur;
						opt->backPrev = repIndex;
						opt->prev1IsChar = 0;
					}
				} while (--lenTest >= 2);
				lenTest = lenTestTemp;
				if (repIndex == 0) startLen = lenTest + 1;

				{
					uint32_t lenTest2 = lenTest + 1;
					uint32_t limit = lenTest2 + p->numFastBytes;
					uint32_t nextRepMatchPrice;
					if (limit > numAvailFull) limit = numAvailFull;
					for (; lenTest2 < limit && data[lenTest2] == data2[lenTest2]; lenTest2++);
					lenTest2 -= lenTest + 1;
					if (lenTest2 >= 2)
					{
						uint32_t state2 = kRepNextStates[state];
						uint32_t posStateNext = (position + lenTest) & p->pbMask;
						uint32_t curAndLenCharPrice =
						price + p->repLenEnc.prices[posState][lenTest - 2] +
						__LZMA_GET_PRICE_0(p->isMatch[state2][posStateNext]) +
						__LZMA_LitEnc_GetPriceMatched(__LZMA_LIT_PROBS(position + lenTest, data[lenTest - 1]),
													  data[lenTest], data2[lenTest], p->ProbPrices);
						state2 = kLiteralNextStates[state2];
						posStateNext = (position + lenTest + 1) & p->pbMask;
						nextRepMatchPrice = curAndLenCharPrice +
						__LZMA_GET_PRICE_1(p->isMatch[state2][posStateNext]) +
						__LZMA_GET_PRICE_1(p->isRep[state2]);

						{
							uint32_t curAndLenPrice;
							__LZMA_COptimal *opt;
							uint32_t offset = cur + lenTest + 1 + lenTest2;
							while (lenEnd < offset) p->opt[++lenEnd].price = __LZMA_kInfinityPrice;
							curAndLenPrice = nextRepMatchPrice + __LZMA_GetRepPrice(p, 0, lenTest2, state2, posStateNext);
							opt = &p->opt[offset];
							if (curAndLenPrice < opt->price)
							{
								opt->price = curAndLenPrice;
								opt->posPrev = cur + lenTest + 1;
								opt->backPrev = 0;
								opt->prev1IsChar = 1;
								opt->prev2 = 1;
								opt->posPrev2 = cur;
								opt->backPrev2 = repIndex;
							}
						}
					}
				}
			}
		}
		if (newLen > numAvail)
		{
			newLen = numAvail;
			for (numPairs = 0; newLen > matches[numPairs]; numPairs += 2);
			matches[numPairs] = newLen;
			numPairs += 2;
		}
		if (newLen >= startLen)
		{
			uint32_t normalMatchPrice = matchPrice + __LZMA_GET_PRICE_0(p->isRep[state]);
			uint32_t offs, curBack, posSlot;
			uint32_t lenTest;
			while (lenEnd < cur + newLen) p->opt[++lenEnd].price = __LZMA_kInfinityPrice;
			offs = 0;
			while (startLen > matches[offs]) offs += 2;
			curBack = matches[offs + 1];
			__LZMA_GetPosSlot2(curBack, posSlot);
			for (lenTest = startLen; ; lenTest++)
			{
				uint32_t curAndLenPrice = normalMatchPrice + p->lenEnc.prices[posState][lenTest - __LZMA_MATCH_LEN_MIN];
				uint32_t lenToPosState = __LZMA_GetLenToPosState(lenTest);
				if (curBack < __LZMA_kNumFullDistances) curAndLenPrice += p->distancesPrices[lenToPosState][curBack];
				else curAndLenPrice += p->posSlotPrices[lenToPosState][posSlot] + p->alignPrices[curBack & __LZMA_kAlignMask];
				__LZMA_COptimal *opt = &p->opt[cur + lenTest];
				if (curAndLenPrice < opt->price)
				{
					opt->price = curAndLenPrice;
					opt->posPrev = cur;
					opt->backPrev = curBack + __LZMA_NUM_REPS;
					opt->prev1IsChar = 0;
				}
				if (lenTest == matches[offs])
				{
					const uint8_t *data2 = data - curBack - 1;
					uint32_t lenTest2 = lenTest + 1;
					uint32_t limit = lenTest2 + p->numFastBytes;
					uint32_t nextRepMatchPrice;
					if (limit > numAvailFull) limit = numAvailFull;
					for (; lenTest2 < limit && data[lenTest2] == data2[lenTest2]; lenTest2++);
					lenTest2 -= lenTest + 1;
					if (lenTest2 >= 2)
					{
						uint32_t state2 = kMatchNextStates[state];
						uint32_t posStateNext = (position + lenTest) & p->pbMask;
						uint32_t curAndLenCharPrice = curAndLenPrice +
						__LZMA_GET_PRICE_0(p->isMatch[state2][posStateNext]) +
						__LZMA_LitEnc_GetPriceMatched(__LZMA_LIT_PROBS(position + lenTest, data[lenTest - 1]),
													  data[lenTest], data2[lenTest], p->ProbPrices);
						state2 = kLiteralNextStates[state2];
						posStateNext = (posStateNext + 1) & p->pbMask;
						nextRepMatchPrice = curAndLenCharPrice +
						__LZMA_GET_PRICE_1(p->isMatch[state2][posStateNext]) +
						__LZMA_GET_PRICE_1(p->isRep[state2]);

						{
							uint32_t offset = cur + lenTest + 1 + lenTest2;
							uint32_t curAndLenPrice;
							__LZMA_COptimal *opt;
							while (lenEnd < offset) p->opt[++lenEnd].price = __LZMA_kInfinityPrice;
							curAndLenPrice = nextRepMatchPrice + __LZMA_GetRepPrice(p, 0, lenTest2, state2, posStateNext);
							opt = &p->opt[offset];
							if (curAndLenPrice < opt->price)
							{
								opt->price = curAndLenPrice;
								opt->posPrev = cur + lenTest + 1;
								opt->backPrev = 0;
								opt->prev1IsChar = 1;
								opt->prev2 = 1;
								opt->posPrev2 = cur;
								opt->backPrev2 = curBack + __LZMA_NUM_REPS;
							}
						}
					}
					offs += 2;
					if (offs == numPairs) break;
					curBack = matches[offs + 1];
					if (curBack >= __LZMA_kNumFullDistances) { __LZMA_GetPosSlot2(curBack, posSlot); }
				}
			}
		}
	}
}

static void __LZMA_LitEnc_EncodeMatched(__LZMA_CRangeEnc *p, uint16_t *probs, uint32_t symbol, uint32_t matchByte) {
	uint32_t offs = 0x100;
	symbol |= 0x100;
	do {
		matchByte <<= 1;
		__LZMA_RangeEnc_EncodeBit(p, probs + (offs + (matchByte & offs) + (symbol >> 8)), (symbol >> 7) & 1);
		symbol <<= 1;
		offs &= ~(matchByte ^ symbol);
	} while (symbol < 0x10000);
}

static int __LZMA_LzmaEnc_CodeOneBlock(__LZMA_CLzmaEnc *p, uint8_t useLimits, uint32_t maxPackSize, uint32_t maxUnpackSize) {
	const int kLiteralNextStates[__LZMA_kNumStates] = {0, 0, 0, 0, 1, 2, 3, 4,  5,  6, 4, 5};
	const int kMatchNextStates[__LZMA_kNumStates] = {7, 7, 7, 7, 7, 7, 7, 10, 10, 10, 10, 10};
	const int kRepNextStates[__LZMA_kNumStates] = {8, 8, 8, 8, 8, 8, 8, 11, 11, 11, 11, 11};
	const int kShortRepNextStates[__LZMA_kNumStates] = {9, 9, 9, 9, 9, 9, 9, 11, 11, 11, 11, 11};
	uint32_t nowPos32, startPos32;
	if (p->needInit)
	{
		p->matchFinder.Init(p->matchFinderObj);
		p->needInit = 0;
	}
	if (p->finished) return p->result;
	__LZMA_RINOK(__LZMA_CheckErrors(p));
	nowPos32 = (uint32_t)p->nowPos64;
	startPos32 = nowPos32;
	if (p->nowPos64 == 0)
	{
		uint32_t numPairs;
		uint8_t curByte;
		if (p->matchFinder.GetNumAvailableBytes(p->matchFinderObj) == 0) return __LZMA_Flush(p, nowPos32);
		__LZMA_ReadMatchDistances(p, &numPairs);
		__LZMA_RangeEnc_EncodeBit(&p->rc, &p->isMatch[p->state][0], 0);
		p->state = kLiteralNextStates[p->state];
		curByte = *(p->matchFinder.GetPointerToCurrentPos(p->matchFinderObj) - p->additionalOffset);
		__LZMA_LitEnc_Encode(&p->rc, p->litProbs, curByte);
		p->additionalOffset--;
		nowPos32++;
	}
	if (p->matchFinder.GetNumAvailableBytes(p->matchFinderObj) != 0)
		for (;;)
		{
	  uint32_t pos, len, posState;

	  if (p->fastMode) len = __LZMA_GetOptimumFast(p, &pos);
	  else len = __LZMA_GetOptimum(p, nowPos32, &pos);

	  posState = nowPos32 & p->pbMask;
	  if (len == 1 && pos == (uint32_t)-1)
	  {
		  __LZMA_RangeEnc_EncodeBit(&p->rc, &p->isMatch[p->state][posState], 0);
		  const uint8_t * data = p->matchFinder.GetPointerToCurrentPos(p->matchFinderObj) - p->additionalOffset;
		  uint8_t curByte = *data;
		  uint16_t * probs = __LZMA_LIT_PROBS(nowPos32, *(data - 1));
		  if (__LZMA_IsCharState(p->state)) __LZMA_LitEnc_Encode(&p->rc, probs, curByte);
		  else __LZMA_LitEnc_EncodeMatched(&p->rc, probs, curByte, *(data - p->reps[0] - 1));
		  p->state = kLiteralNextStates[p->state];
	  }
	  else
	  {
		  __LZMA_RangeEnc_EncodeBit(&p->rc, &p->isMatch[p->state][posState], 1);
		  if (pos < __LZMA_NUM_REPS)
		  {
			  __LZMA_RangeEnc_EncodeBit(&p->rc, &p->isRep[p->state], 1);
			  if (pos == 0)
			  {
				  __LZMA_RangeEnc_EncodeBit(&p->rc, &p->isRepG0[p->state], 0);
				  __LZMA_RangeEnc_EncodeBit(&p->rc, &p->isRep0Long[p->state][posState], ((len == 1) ? 0 : 1));
			  }
			  else
			  {
				  uint32_t distance = p->reps[pos];
				  __LZMA_RangeEnc_EncodeBit(&p->rc, &p->isRepG0[p->state], 1);
				  if (pos == 1) __LZMA_RangeEnc_EncodeBit(&p->rc, &p->isRepG1[p->state], 0);
				  else
				  {
					  __LZMA_RangeEnc_EncodeBit(&p->rc, &p->isRepG1[p->state], 1);
					  __LZMA_RangeEnc_EncodeBit(&p->rc, &p->isRepG2[p->state], pos - 2);
					  if (pos == 3) p->reps[3] = p->reps[2];
					  p->reps[2] = p->reps[1];
				  }
				  p->reps[1] = p->reps[0];
				  p->reps[0] = distance;
			  }
			  if (len == 1) p->state = kShortRepNextStates[p->state];
			  else
			  {
				  __LZMA_LenEnc_Encode2(&p->repLenEnc, &p->rc, len - __LZMA_MATCH_LEN_MIN, posState, !p->fastMode, p->ProbPrices);
				  p->state = kRepNextStates[p->state];
			  }
		  }
		  else
		  {
			  uint32_t posSlot;
			  __LZMA_RangeEnc_EncodeBit(&p->rc, &p->isRep[p->state], 0);
			  p->state = kMatchNextStates[p->state];
			  __LZMA_LenEnc_Encode2(&p->lenEnc, &p->rc, len - __LZMA_MATCH_LEN_MIN, posState, !p->fastMode, p->ProbPrices);
			  pos -= __LZMA_NUM_REPS;
			  __LZMA_GetPosSlot(pos, posSlot);
			  __LZMA_RcTree_Encode(&p->rc, p->posSlotEncoder[__LZMA_GetLenToPosState(len)], __LZMA_kNumPosSlotBits, posSlot);
			  if (posSlot >= __LZMA_kStartPosModelIndex)
			  {
				  uint32_t footerBits = ((posSlot >> 1) - 1);
				  uint32_t base = ((2 | (posSlot & 1)) << footerBits);
				  uint32_t posReduced = pos - base;
				  if (posSlot < __LZMA_kEndPosModelIndex) __LZMA_RcTree_ReverseEncode(&p->rc, p->posEncoders + base - posSlot - 1, footerBits, posReduced);
				  else
				  {
					  __LZMA_RangeEnc_EncodeDirectBits(&p->rc, posReduced >> __LZMA_kNumAlignBits, footerBits - __LZMA_kNumAlignBits);
					  __LZMA_RcTree_ReverseEncode(&p->rc, p->posAlignEncoder, __LZMA_kNumAlignBits, posReduced & __LZMA_kAlignMask);
					  p->alignPriceCount++;
				  }
			  }
			  p->reps[3] = p->reps[2];
			  p->reps[2] = p->reps[1];
			  p->reps[1] = p->reps[0];
			  p->reps[0] = pos;
			  p->matchPriceCount++;
		  }
	  }
	  p->additionalOffset -= len;
	  nowPos32 += len;
	  if (p->additionalOffset == 0)
	  {
		  uint32_t processed;
		  if (!p->fastMode)
		  {
			  if (p->matchPriceCount >= (1 << 7)) __LZMA_FillDistancesPrices(p);
			  if (p->alignPriceCount >= __LZMA_kAlignTableSize) __LZMA_FillAlignPrices(p);
		  }
		  if (p->matchFinder.GetNumAvailableBytes(p->matchFinderObj) == 0) break;
		  processed = nowPos32 - startPos32;
		  if (useLimits)
		  {
			  if (processed + __LZMA_kNumOpts + 300 >= maxUnpackSize ||
				  __LZMA_RangeEnc_GetProcessed(&p->rc) + __LZMA_kNumOpts * 2 >= maxPackSize)
				  break;
		  }
		  else if (processed >= (1 << 17))
		  {
			  p->nowPos64 += nowPos32 - startPos32;
			  return __LZMA_CheckErrors(p);
		  }
	  }
  }
	p->nowPos64 += nowPos32 - startPos32;
	return __LZMA_Flush(p, nowPos32);
}
static void __LZMA_LzmaEnc_Finish(__LZMA_CLzmaEncHandle pp) { }
static int __LZMA_LzmaEnc_Encode2(__LZMA_CLzmaEnc *p, __LZMA_ICompressProgress *progress)
{
	int res = __LZMA_SZ_OK;
	for (;;)
	{
		res = __LZMA_LzmaEnc_CodeOneBlock(p, 0, 0, 0);
		if (res != __LZMA_SZ_OK || p->finished != 0) break;
		if (progress != 0)
		{
			res = progress->Progress(progress, p->nowPos64, __LZMA_RangeEnc_GetProcessed(&p->rc));
			if (res != __LZMA_SZ_OK)
			{
				res = __LZMA_SZ_ERROR_PROGRESS;
				break;
			}
		}
	}
	__LZMA_LzmaEnc_Finish(p);
	return res;
}

static int __LZMA_LzmaEnc_MemEncode(__LZMA_CLzmaEncHandle pp, uint8_t *dest, size_t *destLen, const uint8_t *src, size_t srcLen,
									int writeEndMark, __LZMA_ICompressProgress *progress, __LZMA_ISzAlloc *alloc, __LZMA_ISzAlloc *allocBig) {
	__LZMA_CLzmaEnc *p = (__LZMA_CLzmaEnc *)pp;
	__LZMA_CSeqOutStreamBuf outStream;
	__LZMA_LzmaEnc_SetInputBuf(p, src, srcLen);
	outStream.funcTable.Write = __LZMA_MyWrite;
	outStream.data = dest;
	outStream.rem = *destLen;
	outStream.overflow = 0;
	p->writeEndMark = writeEndMark;
	p->rc.outStream = &outStream.funcTable;
	int res = __LZMA_LzmaEnc_MemPrepare(pp, src, srcLen, 0, alloc, allocBig);
	if (res == __LZMA_SZ_OK) res = __LZMA_LzmaEnc_Encode2(p, progress);
	*destLen -= outStream.rem;
	if (outStream.overflow) return __LZMA_SZ_ERROR_OUTPUT_EOF;
	return res;
}

static void __LZMA_LzmaEnc_Destruct(__LZMA_CLzmaEnc *p, __LZMA_ISzAlloc *alloc, __LZMA_ISzAlloc *allocBig) {
	__LZMA_MatchFinder_Free(&p->matchFinderBase, allocBig);
	__LZMA_LzmaEnc_FreeLits(p, alloc);
	__LZMA_RangeEnc_Free(&p->rc, alloc);
}

static void __LZMA_LzmaEnc_Destroy(__LZMA_CLzmaEncHandle p, __LZMA_ISzAlloc *alloc, __LZMA_ISzAlloc *allocBig) {
	__LZMA_LzmaEnc_Destruct((__LZMA_CLzmaEnc *)p, alloc, allocBig);
	alloc->Free(alloc, p);
}

static int __LZMA_LzmaEncode(uint8_t *dest, size_t *destLen, const uint8_t *src, size_t srcLen,
							 const __LZMA_CLzmaEncProps *props, uint8_t *propsEncoded, size_t *propsSize, int writeEndMark,
							 __LZMA_ICompressProgress *progress, __LZMA_ISzAlloc *alloc, __LZMA_ISzAlloc *allocBig) {
	__LZMA_CLzmaEnc *p = (__LZMA_CLzmaEnc *)__LZMA_LzmaEnc_Create(alloc);
	if (p == 0) return __LZMA_SZ_ERROR_MEM;

	int res = __LZMA_LzmaEnc_SetProps(p, props);
	if (res == __LZMA_SZ_OK)
	{
		res = __LZMA_LzmaEnc_WriteProperties(p, propsEncoded, propsSize);
		if (res == __LZMA_SZ_OK)
			res = __LZMA_LzmaEnc_MemEncode(p, dest, destLen, src, srcLen,
										   writeEndMark, progress, alloc, allocBig);
	}
	__LZMA_LzmaEnc_Destroy(p, alloc, allocBig);
	return res;
}

static void *__LZMA_MyAlloc(size_t size) {
	if (size == 0) return 0;
	return malloc(size);
}

static void __LZMA_MyFree(void *address) { free(address); }
static void *__LZMA_SzAlloc(void *p, size_t size) { return __LZMA_MyAlloc(size); }
static void __LZMA_SzFree(void *p, void *address) { __LZMA_MyFree(address); }
static int __LZMA_LzmaCompress(uint8_t *dest, size_t *destLen, const uint8_t *src, size_t srcLen,
							   uint8_t *outProps, size_t *outPropsSize,
							   int level, /* 0 <= level <= 9, default = 5 */
							   unsigned dictSize, /* use (1 << N) or (3 << N). 4 KB < dictSize <= 128 MB */
							   int lc, /* 0 <= lc <= 8, default = 3  */
							   int lp, /* 0 <= lp <= 4, default = 0  */
							   int pb, /* 0 <= pb <= 4, default = 2  */
							   int fb,  /* 5 <= fb <= 273, default = 32 */
							   int numThreads /* 1 or 2, default = 2 */
) {
	__LZMA_CLzmaEncProps props;
	__LZMA_LzmaEncProps_Init(&props);
	props.level = level;
	props.dictSize = dictSize;
	props.lc = lc;
	props.lp = lp;
	props.pb = pb;
	props.fb = fb;
	props.numThreads = numThreads;
	__LZMA_ISzAlloc g_Alloc = { __LZMA_SzAlloc, __LZMA_SzFree };
	return __LZMA_LzmaEncode(dest, destLen, src, srcLen, &props, outProps, outPropsSize, 0,
							 NULL, &g_Alloc, &g_Alloc);
}


/**
 @brief Get lzma compressed data with compression ratio.
 @warning First 4 bytes of compressed data is uint32 with decompressed size value.
 @param dataToCompress The data for compress.
 @param compressionRatio Float compression ratio value in range [0.0f; 1.0f].
 @return Lzma compressed data or nil on error or dataToCompress is empty. First 4 bytes of compressed data is uint32 with decompressed size value.
 */
NS_INLINE NSData * NSDataGetLzmaCompressDataWithRatio(NSData * dataToCompress, const CGFloat compressionRatio)
{
	if (!dataToCompress) return nil;
#if defined(DEBUG)
	assert([dataToCompress isKindOfClass:[NSData class]]);
#endif
	if ([dataToCompress length] == 0) return nil;
	uint32_t outSize = (uint32_t)(((size_t)[dataToCompress length] / 20) * 21) + (1 << 16);
	if (outSize == 0) return nil;
	size_t destLen = outSize;
	outSize += (__LZMA_PROPS_SIZE + sizeof(uint32_t));
	uint8_t * compressedBuffer = (uint8_t *)malloc(outSize);
	if (!compressedBuffer) return nil;
	int level = 0;
	if (compressionRatio < 0.0f) level = 0;
	else if (compressionRatio > 1.0f) level = 9;
	else level = (int)(compressionRatio * 9.0f);
	uint8_t * sizePtr = (uint8_t *)compressedBuffer;
	uint8_t * props = sizePtr + sizeof(uint32_t);
	uint8_t * dest = props + __LZMA_PROPS_SIZE;
	size_t outPropsSize = __LZMA_PROPS_SIZE;
	const int comprResult = __LZMA_LzmaCompress(dest,
												&destLen,
												(const uint8_t *)[dataToCompress bytes],
												(size_t)[dataToCompress length],
												props,
												&outPropsSize,
												level, // compr
												1 << 24,
												3,
												0,
												2,
												32,
												1);
	if (comprResult == __LZMA_SZ_OK)
	{
		uint32_t * int32Ptr = (uint32_t *)sizePtr;
		*int32Ptr = (uint32_t)[dataToCompress length];
		NSData * d = [NSData dataWithBytesNoCopy:compressedBuffer
										  length:(uint32_t)destLen + __LZMA_PROPS_SIZE + sizeof(uint32_t)
									freeWhenDone:YES];
		if (d) return d;
	}
	free(compressedBuffer);
	return nil;
}

typedef enum {
	__LZMA_STATUS_NOT_SPECIFIED,
	__LZMA_STATUS_FINISHED_WITH_MARK,
	__LZMA_STATUS_NOT_FINISHED,
	__LZMA_STATUS_NEEDS_MORE_INPUT,
	__LZMA_STATUS_MAYBE_FINISHED_WITHOUT_MARK
} __LZMA_ELzmaStatus;

typedef enum {
	__LZMA_FINISH_ANY,
	__LZMA_FINISH_END
} __LZMA_ELzmaFinishMode;

typedef struct {
	unsigned lc, lp, pb;
	uint32_t dicSize;
} __LZMA_CLzmaProps;

typedef struct {
	__LZMA_CLzmaProps prop;
	uint16_t *probs;
	uint8_t *dic;
	const uint8_t *buf;
	uint32_t range, code;
	size_t dicPos;
	size_t dicBufSize;
	uint32_t processedPos;
	uint32_t checkDicSize;
	unsigned state;
	uint32_t reps[4];
	unsigned remainLen;
	int needFlush;
	int needInitState;
	uint32_t numProbs;
	unsigned tempBufSize;
	uint8_t tempBuf[__LZMA_REQUIRED_INPUT_MAX];
} __LZMA_CLzmaDec;

#define __LZMA_LzmaDec_Construct(p) { (p)->dic = 0; (p)->probs = 0; }

static int __LZMA_LzmaProps_Decode(__LZMA_CLzmaProps *p, const uint8_t *data, unsigned size) {
	uint32_t dicSize;
	if (size < __LZMA_PROPS_SIZE) return __LZMA_SZ_ERROR_UNSUPPORTED;
	else dicSize = data[1] | ((uint32_t)data[2] << 8) | ((uint32_t)data[3] << 16) | ((uint32_t)data[4] << 24);
	if (dicSize < __LZMA_DIC_MIN) dicSize = __LZMA_DIC_MIN;
	p->dicSize = dicSize;
	uint8_t d = data[0];
	if (d >= (9 * 5 * 5)) return __LZMA_SZ_ERROR_UNSUPPORTED;
	p->lc = d % 9;
	d /= 9;
	p->pb = d / 5;
	p->lp = d % 5;
	return __LZMA_SZ_OK;
}

static void __LZMA_LzmaDec_FreeProbs(__LZMA_CLzmaDec *p, __LZMA_ISzAlloc *alloc) {
	alloc->Free(alloc, p->probs); p->probs = NULL;
}

static int __LZMA_LzmaDec_AllocateProbs2(__LZMA_CLzmaDec *p, const __LZMA_CLzmaProps *propNew, __LZMA_ISzAlloc *alloc) {
	uint32_t numProbs = __LZMA_LzmaProps_GetNumProbs(propNew);
	if (!p->probs || numProbs != p->numProbs)
	{
		__LZMA_LzmaDec_FreeProbs(p, alloc);
		p->probs = (uint16_t *)alloc->Alloc(alloc, numProbs * sizeof(uint16_t));
		p->numProbs = numProbs;
		if (!p->probs) return __LZMA_SZ_ERROR_MEM;
	}
	return __LZMA_SZ_OK;
}

static int __LZMA_LzmaDec_AllocateProbs(__LZMA_CLzmaDec *p, const uint8_t *props, unsigned propsSize, __LZMA_ISzAlloc *alloc) {
	__LZMA_CLzmaProps propNew;
	__LZMA_RINOK(__LZMA_LzmaProps_Decode(&propNew, props, propsSize));
	__LZMA_RINOK(__LZMA_LzmaDec_AllocateProbs2(p, &propNew, alloc));
	p->prop = propNew;
	return __LZMA_SZ_OK;
}

static void __LZMA_LzmaDec_InitDicAndState(__LZMA_CLzmaDec *p, uint8_t initDic, uint8_t initState) {
	p->needFlush = 1;
	p->remainLen = 0;
	p->tempBufSize = 0;
	if (initDic)
	{
		p->processedPos = 0;
		p->checkDicSize = 0;
		p->needInitState = 1;
	}
	if (initState) p->needInitState = 1;
}

static void __LZMA_LzmaDec_Init(__LZMA_CLzmaDec *p) {
	p->dicPos = 0;
	__LZMA_LzmaDec_InitDicAndState(p, 1, 1);
}

static void __LZMA_LzmaDec_WriteRem(__LZMA_CLzmaDec *p, size_t limit) {
	if (p->remainLen != 0 && p->remainLen < __LZMA_kMatchSpecLenStart)
	{
		uint8_t *dic = p->dic;
		size_t dicPos = p->dicPos;
		size_t dicBufSize = p->dicBufSize;
		unsigned len = p->remainLen;
		size_t rep0 = p->reps[0];
		size_t rem = limit - dicPos;
		if (rem < len) len = (unsigned)(rem);
		if (p->checkDicSize == 0 && p->prop.dicSize - p->processedPos <= len) p->checkDicSize = p->prop.dicSize;
		p->processedPos += len;
		p->remainLen -= len;
		while (len != 0)
		{
			len--;
			dic[dicPos] = dic[dicPos - rep0 + (dicPos < rep0 ? dicBufSize : 0)];
			dicPos++;
		}
		p->dicPos = dicPos;
	}
}

static void __LZMA_LzmaDec_InitStateReal(__LZMA_CLzmaDec *p) {
	size_t numProbs = __LZMA_LzmaProps_GetNumProbs(&p->prop);
	size_t i;
	uint16_t *probs = p->probs;
	for (i = 0; i < numProbs; i++) probs[i] = __LZMA_kBitModelTotal >> 1;
	p->reps[0] = p->reps[1] = p->reps[2] = p->reps[3] = 1;
	p->state = 0;
	p->needInitState = 0;
}

typedef enum {
	__LZMA_DUMMY_ERROR,
	__LZMA_DUMMY_LIT,
	__LZMA_DUMMY_MATCH,
	__LZMA_DUMMY_REP
} __LZMA_ELzmaDummy;

#define __LZMA_NORMALIZE_CHECK if (range < __LZMA_kTopValue) { if (buf >= bufLimit) return __LZMA_DUMMY_ERROR; range <<= 8; code = (code << 8) | (*buf++); }
#define __LZMA_IF_BIT_0_CHECK(p) ttt = *(p); __LZMA_NORMALIZE_CHECK; bound = (range >> __LZMA_kNumBitModelTotalBits) * ttt; if (code < bound)
#define __LZMA_UPDATE_0_CHECK range = bound;
#define __LZMA_UPDATE_1_CHECK range -= bound; code -= bound;
#define __LZMA_GET_BIT2_CHECK(p, i, A0, A1) __LZMA_IF_BIT_0_CHECK(p) \
{ __LZMA_UPDATE_0_CHECK; i = (i + i); A0; } else \
{ __LZMA_UPDATE_1_CHECK; i = (i + i) + 1; A1; }
#define __LZMA_GET_BIT_CHECK(p, i) __LZMA_GET_BIT2_CHECK(p, i, ; , ;)
#define __LZMA_TREE_DECODE_CHECK(probs, limit, i) \
{ i = 1; do { __LZMA_GET_BIT_CHECK(probs + i, i) } while (i < limit); i -= limit; }

static __LZMA_ELzmaDummy __LZMA_LzmaDec_TryDummy(const __LZMA_CLzmaDec *p, const uint8_t *buf, size_t inSize) {
	uint32_t range = p->range;
	uint32_t code = p->code;
	const uint8_t *bufLimit = buf + inSize;
	const uint16_t *probs = p->probs;
	unsigned state = p->state;
	__LZMA_ELzmaDummy res;
	{
		const uint16_t *prob;
		uint32_t bound;
		unsigned ttt;
		unsigned posState = (p->processedPos) & ((1 << p->prop.pb) - 1);

		prob = probs + __LZMA_IsMatch + (state << __LZMA_kNumPosBitsMax) + posState;
		__LZMA_IF_BIT_0_CHECK(prob)
		{
			__LZMA_UPDATE_0_CHECK
			prob = probs + __LZMA_Literal;
			if (p->checkDicSize != 0 || p->processedPos != 0)
				prob += ((uint32_t)__LZMA_LIT_SIZE *
						 ((((p->processedPos) & ((1 << (p->prop.lp)) - 1)) << p->prop.lc) +
						  (p->dic[(p->dicPos == 0 ? p->dicBufSize : p->dicPos) - 1] >> (8 - p->prop.lc))));

			if (state < __LZMA_kNumLitStates)
			{
				unsigned symbol = 1;
				do { __LZMA_GET_BIT_CHECK(prob + symbol, symbol) } while (symbol < 0x100);
			}
			else
			{
				unsigned matchByte = p->dic[p->dicPos - p->reps[0] +
											(p->dicPos < p->reps[0] ? p->dicBufSize : 0)];
				unsigned offs = 0x100;
				unsigned symbol = 1;
				do {
					unsigned bit;
					const uint16_t *probLit;
					matchByte <<= 1;
					bit = (matchByte & offs);
					probLit = prob + offs + bit + symbol;
					__LZMA_GET_BIT2_CHECK(probLit, symbol, offs &= ~bit, offs &= bit)
				} while (symbol < 0x100);
			}
			res = __LZMA_DUMMY_LIT;
		}
		else
		{
			unsigned len;
			__LZMA_UPDATE_1_CHECK;

			prob = probs + __LZMA_IsRep + state;
			__LZMA_IF_BIT_0_CHECK(prob)
			{
				__LZMA_UPDATE_0_CHECK;
				state = 0;
				prob = probs + __LZMA_LenCoder;
				res = __LZMA_DUMMY_MATCH;
			}
			else
			{
				__LZMA_UPDATE_1_CHECK;
				res = __LZMA_DUMMY_REP;
				prob = probs + __LZMA_IsRepG0 + state;
				__LZMA_IF_BIT_0_CHECK(prob)
				{
					__LZMA_UPDATE_0_CHECK;
					prob = probs + __LZMA_IsRep0Long + (state << __LZMA_kNumPosBitsMax) + posState;
					__LZMA_IF_BIT_0_CHECK(prob)
					{
						__LZMA_UPDATE_0_CHECK;
						__LZMA_NORMALIZE_CHECK;
						return __LZMA_DUMMY_REP;
					}
					else
					{
						__LZMA_UPDATE_1_CHECK;
					}
				}
				else
				{
					__LZMA_UPDATE_1_CHECK;
					prob = probs + __LZMA_IsRepG1 + state;
					__LZMA_IF_BIT_0_CHECK(prob)
					{
						__LZMA_UPDATE_0_CHECK;
					}
					else
					{
						__LZMA_UPDATE_1_CHECK;
						prob = probs + __LZMA_IsRepG2 + state;
						__LZMA_IF_BIT_0_CHECK(prob)
						{
							__LZMA_UPDATE_0_CHECK;
						}
						else
						{
							__LZMA_UPDATE_1_CHECK;
						}
					}
				}
				state = __LZMA_kNumStates;
				prob = probs + __LZMA_RepLenCoder;
			}
			{
				unsigned limit, offset;
				const uint16_t *probLen = prob + __LZMA_LenChoice;
				__LZMA_IF_BIT_0_CHECK(probLen)
				{
					__LZMA_UPDATE_0_CHECK;
					probLen = prob + __LZMA_LenLow + (posState << __LZMA_kLenNumLowBits);
					offset = 0;
					limit = 1 << __LZMA_kLenNumLowBits;
				}
				else
				{
					__LZMA_UPDATE_1_CHECK;
					probLen = prob + __LZMA_LenChoice2;
					__LZMA_IF_BIT_0_CHECK(probLen)
					{
						__LZMA_UPDATE_0_CHECK;
						probLen = prob + __LZMA_LenMid + (posState << __LZMA_kLenNumMidBits);
						offset = __LZMA_kLenNumLowSymbols;
						limit = 1 << __LZMA_kLenNumMidBits;
					}
					else
					{
						__LZMA_UPDATE_1_CHECK;
						probLen = prob + __LZMA_LenHigh;
						offset = __LZMA_kLenNumLowSymbols + __LZMA_kLenNumMidSymbols;
						limit = 1 << __LZMA_kLenNumHighBits;
					}
				}
				__LZMA_TREE_DECODE_CHECK(probLen, limit, len);
				len += offset;
			}
			if (state < 4)
			{
				unsigned posSlot;
				prob = probs + __LZMA_PosSlot +
				((len < __LZMA_kNumLenToPosStates ? len : __LZMA_kNumLenToPosStates - 1) <<
				 __LZMA_kNumPosSlotBits);
				__LZMA_TREE_DECODE_CHECK(prob, 1 << __LZMA_kNumPosSlotBits, posSlot);
				if (posSlot >= __LZMA_kStartPosModelIndex)
				{
					unsigned numDirectBits = ((posSlot >> 1) - 1);
					if (posSlot < __LZMA_kEndPosModelIndex)
					{
						prob = probs + __LZMA_SpecPos + ((2 | (posSlot & 1)) << numDirectBits) - posSlot - 1;
					}
					else
					{
						numDirectBits -= __LZMA_kNumAlignBits;
						do {
							__LZMA_NORMALIZE_CHECK
							range >>= 1;
							code -= range & (((code - range) >> 31) - 1);
						} while (--numDirectBits != 0);
						prob = probs + __LZMA_Align;
						numDirectBits = __LZMA_kNumAlignBits;
					}
					{
						unsigned i = 1;
						do {
							__LZMA_GET_BIT_CHECK(prob + i, i);
						} while (--numDirectBits != 0);
					}
				}
			}
		}
	}
	__LZMA_NORMALIZE_CHECK;
	return res;
}

#define __LZMA_NORMALIZE if (range < __LZMA_kTopValue) { range <<= 8; code = (code << 8) | (*buf++); }
#define __LZMA_IF_BIT_0(p) ttt = *(p); __LZMA_NORMALIZE; bound = (range >> __LZMA_kNumBitModelTotalBits) * ttt; if (code < bound)
#define __LZMA_UPDATE_0(p) range = bound; *(p) = (uint16_t)(ttt + ((__LZMA_kBitModelTotal - ttt) >> __LZMA_kNumMoveBits));
#define __LZMA_UPDATE_1(p) range -= bound; code -= bound; *(p) = (uint16_t)(ttt - (ttt >> __LZMA_kNumMoveBits));
#define __LZMA_GET_BIT2(p, i, A0, A1) __LZMA_IF_BIT_0(p) \
{ __LZMA_UPDATE_0(p); i = (i + i); A0; } else \
{ __LZMA_UPDATE_1(p); i = (i + i) + 1; A1; }
#define __LZMA_GET_BIT(p, i) __LZMA_GET_BIT2(p, i, ; , ;)
#define __LZMA_NORMAL_LITER_DEC __LZMA_GET_BIT(prob + symbol, symbol)
#define __LZMA_NORMAL_LITER_DEC __LZMA_GET_BIT(prob + symbol, symbol)
#define __LZMA_MATCHED_LITER_DEC \
matchByte <<= 1; \
bit = (matchByte & offs); \
probLit = prob + offs + bit + symbol; \
__LZMA_GET_BIT2(probLit, symbol, offs &= ~bit, offs &= bit)

#define __LZMA_TREE_GET_BIT(probs, i) { __LZMA_GET_BIT((probs + i), i); }
#define __LZMA_TREE_DECODE(probs, limit, i) \
{ i = 1; do { __LZMA_TREE_GET_BIT(probs, i); } while (i < limit); i -= limit; }

#define __LZMA_TREE_6_DECODE(probs, i) \
{ i = 1; \
	__LZMA_TREE_GET_BIT(probs, i); \
	__LZMA_TREE_GET_BIT(probs, i); \
	__LZMA_TREE_GET_BIT(probs, i); \
	__LZMA_TREE_GET_BIT(probs, i); \
	__LZMA_TREE_GET_BIT(probs, i); \
	__LZMA_TREE_GET_BIT(probs, i); \
	i -= 0x40; }

static int __LZMA_LzmaDec_DecodeReal(__LZMA_CLzmaDec *p, size_t limit, const uint8_t *bufLimit) {
	uint16_t *probs = p->probs;
	unsigned state = p->state;
	uint32_t rep0 = p->reps[0], rep1 = p->reps[1], rep2 = p->reps[2], rep3 = p->reps[3];
	unsigned pbMask = ((unsigned)1 << (p->prop.pb)) - 1;
	unsigned lpMask = ((unsigned)1 << (p->prop.lp)) - 1;
	unsigned lc = p->prop.lc;
	uint8_t *dic = p->dic;
	size_t dicBufSize = p->dicBufSize;
	size_t dicPos = p->dicPos;
	uint32_t processedPos = p->processedPos;
	uint32_t checkDicSize = p->checkDicSize;
	unsigned len = 0;
	const uint8_t *buf = p->buf;
	uint32_t range = p->range;
	uint32_t code = p->code;

	do {
		uint16_t *prob;
		uint32_t bound;
		unsigned ttt;
		unsigned posState = processedPos & pbMask;

		prob = probs + __LZMA_IsMatch + (state << __LZMA_kNumPosBitsMax) + posState;
		__LZMA_IF_BIT_0(prob)
		{
			unsigned symbol;
			__LZMA_UPDATE_0(prob);
			prob = probs + __LZMA_Literal;
			if (processedPos != 0 || checkDicSize != 0)
				prob += ((uint32_t)__LZMA_LIT_SIZE * (((processedPos & lpMask) << lc) +
													  (dic[(dicPos == 0 ? dicBufSize : dicPos) - 1] >> (8 - lc))));
			processedPos++;

			if (state < __LZMA_kNumLitStates)
			{
				state -= (state < 4) ? state : 3;
				symbol = 1;
				__LZMA_NORMAL_LITER_DEC
				__LZMA_NORMAL_LITER_DEC
				__LZMA_NORMAL_LITER_DEC
				__LZMA_NORMAL_LITER_DEC
				__LZMA_NORMAL_LITER_DEC
				__LZMA_NORMAL_LITER_DEC
				__LZMA_NORMAL_LITER_DEC
				__LZMA_NORMAL_LITER_DEC
			}
			else
			{
				unsigned matchByte = dic[dicPos - rep0 + (dicPos < rep0 ? dicBufSize : 0)];
				unsigned offs = 0x100;
				state -= (state < 10) ? 3 : 6;
				symbol = 1;
				{
					unsigned bit;
					uint16_t *probLit;
					__LZMA_MATCHED_LITER_DEC
					__LZMA_MATCHED_LITER_DEC
					__LZMA_MATCHED_LITER_DEC
					__LZMA_MATCHED_LITER_DEC
					__LZMA_MATCHED_LITER_DEC
					__LZMA_MATCHED_LITER_DEC
					__LZMA_MATCHED_LITER_DEC
					__LZMA_MATCHED_LITER_DEC
				}
			}

			dic[dicPos++] = (uint8_t)symbol;
			continue;
		}
		{
			__LZMA_UPDATE_1(prob);
			prob = probs + __LZMA_IsRep + state;
			__LZMA_IF_BIT_0(prob)
			{
				__LZMA_UPDATE_0(prob);
				state += __LZMA_kNumStates;
				prob = probs + __LZMA_LenCoder;
			}
			else
			{
				__LZMA_UPDATE_1(prob);
				if (checkDicSize == 0 && processedPos == 0) return __LZMA_SZ_ERROR_DATA;
				prob = probs + __LZMA_IsRepG0 + state;
				__LZMA_IF_BIT_0(prob)
				{
					__LZMA_UPDATE_0(prob);
					prob = probs + __LZMA_IsRep0Long + (state << __LZMA_kNumPosBitsMax) + posState;
					__LZMA_IF_BIT_0(prob)
					{
						__LZMA_UPDATE_0(prob);
						dic[dicPos] = dic[dicPos - rep0 + (dicPos < rep0 ? dicBufSize : 0)];
						dicPos++;
						processedPos++;
						state = state < __LZMA_kNumLitStates ? 9 : 11;
						continue;
					}
					__LZMA_UPDATE_1(prob);
				}
				else
				{
					uint32_t distance;
					__LZMA_UPDATE_1(prob);
					prob = probs + __LZMA_IsRepG1 + state;
					__LZMA_IF_BIT_0(prob)
					{
						__LZMA_UPDATE_0(prob);
						distance = rep1;
					}
					else
					{
						__LZMA_UPDATE_1(prob);
						prob = probs + __LZMA_IsRepG2 + state;
						__LZMA_IF_BIT_0(prob)
						{
							__LZMA_UPDATE_0(prob);
							distance = rep2;
						}
						else
						{
							__LZMA_UPDATE_1(prob);
							distance = rep3;
							rep3 = rep2;
						}
						rep2 = rep1;
					}
					rep1 = rep0;
					rep0 = distance;
				}
				state = state < __LZMA_kNumLitStates ? 8 : 11;
				prob = probs + __LZMA_RepLenCoder;
			}
			{
				uint16_t *probLen = prob + __LZMA_LenChoice;
				__LZMA_IF_BIT_0(probLen)
				{
					__LZMA_UPDATE_0(probLen);
					probLen = prob + __LZMA_LenLow + (posState << __LZMA_kLenNumLowBits);
					len = 1;
					__LZMA_TREE_GET_BIT(probLen, len);
					__LZMA_TREE_GET_BIT(probLen, len);
					__LZMA_TREE_GET_BIT(probLen, len);
					len -= 8;
				}
				else
				{
					__LZMA_UPDATE_1(probLen);
					probLen = prob + __LZMA_LenChoice2;
					__LZMA_IF_BIT_0(probLen)
					{
						__LZMA_UPDATE_0(probLen);
						probLen = prob + __LZMA_LenMid + (posState << __LZMA_kLenNumMidBits);
						len = 1;
						__LZMA_TREE_GET_BIT(probLen, len);
						__LZMA_TREE_GET_BIT(probLen, len);
						__LZMA_TREE_GET_BIT(probLen, len);
					}
					else
					{
						__LZMA_UPDATE_1(probLen);
						probLen = prob + __LZMA_LenHigh;
						__LZMA_TREE_DECODE(probLen, (1 << __LZMA_kLenNumHighBits), len);
						len += __LZMA_kLenNumLowSymbols + __LZMA_kLenNumMidSymbols;
					}
				}
			}
			if (state >= __LZMA_kNumStates)
			{
				uint32_t distance;
				prob = probs + __LZMA_PosSlot +
				((len < __LZMA_kNumLenToPosStates ? len : __LZMA_kNumLenToPosStates - 1) << __LZMA_kNumPosSlotBits);
				__LZMA_TREE_6_DECODE(prob, distance);
				if (distance >= __LZMA_kStartPosModelIndex)
				{
					unsigned posSlot = (unsigned)distance;
					unsigned numDirectBits = (unsigned)(((distance >> 1) - 1));
					distance = (2 | (distance & 1));
					if (posSlot < __LZMA_kEndPosModelIndex)
					{
						distance <<= numDirectBits;
						prob = probs + __LZMA_SpecPos + distance - posSlot - 1;
						{
							uint32_t mask = 1;
							unsigned i = 1;
							do
							{
								__LZMA_GET_BIT2(prob + i, i, ; , distance |= mask);
								mask <<= 1;
							}
							while (--numDirectBits != 0);
						}
					}
					else
					{
						numDirectBits -= __LZMA_kNumAlignBits;
						do {
							__LZMA_NORMALIZE
							range >>= 1;
							{
								uint32_t t;
								code -= range;
								t = (0 - ((uint32_t)code >> 31));
								distance = (distance << 1) + (t + 1);
								code += range & t;
							}
						} while (--numDirectBits != 0);
						prob = probs + __LZMA_Align;
						distance <<= __LZMA_kNumAlignBits;
						{
							unsigned i = 1;
							__LZMA_GET_BIT2(prob + i, i, ; , distance |= 1);
							__LZMA_GET_BIT2(prob + i, i, ; , distance |= 2);
							__LZMA_GET_BIT2(prob + i, i, ; , distance |= 4);
							__LZMA_GET_BIT2(prob + i, i, ; , distance |= 8);
						}
						if (distance == (uint32_t)0xFFFFFFFF)
						{
							len += __LZMA_kMatchSpecLenStart;
							state -= __LZMA_kNumStates;
							break;
						}
					}
				}

				rep3 = rep2;
				rep2 = rep1;
				rep1 = rep0;
				rep0 = distance + 1;
				if (checkDicSize == 0)
				{
					if (distance >= processedPos)
					{
						p->dicPos = dicPos;
						return __LZMA_SZ_ERROR_DATA;
					}
				}
				else if (distance >= checkDicSize)
				{
					p->dicPos = dicPos;
					return __LZMA_SZ_ERROR_DATA;
				}
				state = (state < __LZMA_kNumStates + __LZMA_kNumLitStates) ? __LZMA_kNumLitStates : __LZMA_kNumLitStates + 3;
			}
			len += __LZMA_kMatchMinLen;
			{
				size_t rem;
				unsigned curLen;
				size_t pos;

				if ((rem = limit - dicPos) == 0)
				{
					p->dicPos = dicPos;
					return __LZMA_SZ_ERROR_DATA;
				}
				curLen = ((rem < len) ? (unsigned)rem : len);
				pos = dicPos - rep0 + (dicPos < rep0 ? dicBufSize : 0);
				processedPos += curLen;
				len -= curLen;
				if (curLen <= dicBufSize - pos)
				{
					uint8_t *dest = dic + dicPos;
					ptrdiff_t src = (ptrdiff_t)pos - (ptrdiff_t)dicPos;
					const uint8_t *lim = dest + curLen;
					dicPos += curLen;
					do
						*(dest) = (uint8_t)*(dest + src);
					while (++dest != lim);
				}
				else
				{
					do {
						dic[dicPos++] = dic[pos];
						if (++pos == dicBufSize) pos = 0;
					} while (--curLen != 0);
				}
			}
		}
	}
	while (dicPos < limit && buf < bufLimit);
	__LZMA_NORMALIZE;
	p->buf = buf;
	p->range = range;
	p->code = code;
	p->remainLen = len;
	p->dicPos = dicPos;
	p->processedPos = processedPos;
	p->reps[0] = rep0;
	p->reps[1] = rep1;
	p->reps[2] = rep2;
	p->reps[3] = rep3;
	p->state = state;
	return __LZMA_SZ_OK;
}

static int __LZMA_LzmaDec_DecodeReal2(__LZMA_CLzmaDec *p, size_t limit, const uint8_t *bufLimit) {
	do {
		size_t limit2 = limit;
		if (p->checkDicSize == 0)
		{
			uint32_t rem = p->prop.dicSize - p->processedPos;
			if (limit - p->dicPos > rem)
				limit2 = p->dicPos + rem;
		}
		__LZMA_RINOK(__LZMA_LzmaDec_DecodeReal(p, limit2, bufLimit));
		if (p->checkDicSize == 0 && p->processedPos >= p->prop.dicSize) p->checkDicSize = p->prop.dicSize;
		__LZMA_LzmaDec_WriteRem(p, limit);
	}
	while (p->dicPos < limit && p->buf < bufLimit && p->remainLen < __LZMA_kMatchSpecLenStart);
	if (p->remainLen > __LZMA_kMatchSpecLenStart) p->remainLen = __LZMA_kMatchSpecLenStart;
	return 0;
}

static int __LZMA_LzmaDec_DecodeToDic(__LZMA_CLzmaDec *p, size_t dicLimit, const uint8_t *src, size_t *srcLen,
									  __LZMA_ELzmaFinishMode finishMode, __LZMA_ELzmaStatus *status) {
	size_t inSize = *srcLen;
	(*srcLen) = 0;
	__LZMA_LzmaDec_WriteRem(p, dicLimit);
	*status = __LZMA_STATUS_NOT_SPECIFIED;
	while (p->remainLen != __LZMA_kMatchSpecLenStart)
	{
		int checkEndMarkNow;
		if (p->needFlush)
		{
			for (; inSize > 0 && p->tempBufSize < __LZMA_RC_INIT_SIZE; (*srcLen)++, inSize--) p->tempBuf[p->tempBufSize++] = *src++;
			if (p->tempBufSize < __LZMA_RC_INIT_SIZE)
			{
				*status = __LZMA_STATUS_NEEDS_MORE_INPUT;
				return __LZMA_SZ_OK;
			}
			if (p->tempBuf[0] != 0) return __LZMA_SZ_ERROR_DATA;
			p->code = ((uint32_t)p->tempBuf[1] << 24)
			| ((uint32_t)p->tempBuf[2] << 16)
			| ((uint32_t)p->tempBuf[3] << 8)
			| ((uint32_t)p->tempBuf[4]);
			p->range = 0xFFFFFFFF;
			p->needFlush = 0;
			p->tempBufSize = 0;
		}
		checkEndMarkNow = 0;
		if (p->dicPos >= dicLimit)
		{
			if (p->remainLen == 0 && p->code == 0)
			{
				*status = __LZMA_STATUS_MAYBE_FINISHED_WITHOUT_MARK;
				return __LZMA_SZ_OK;
			}
			if (finishMode == __LZMA_FINISH_ANY)
			{
				*status = __LZMA_STATUS_NOT_FINISHED;
				return __LZMA_SZ_OK;
			}
			if (p->remainLen != 0)
			{
				*status = __LZMA_STATUS_NOT_FINISHED;
				return __LZMA_SZ_ERROR_DATA;
			}
			checkEndMarkNow = 1;
		}

		if (p->needInitState) __LZMA_LzmaDec_InitStateReal(p);
		if (p->tempBufSize == 0)
		{
			const uint8_t *bufLimit;
			if (inSize < __LZMA_REQUIRED_INPUT_MAX || checkEndMarkNow)
			{
				int dummyRes = __LZMA_LzmaDec_TryDummy(p, src, inSize);
				if (dummyRes == __LZMA_DUMMY_ERROR)
				{
					memcpy(p->tempBuf, src, inSize);
					p->tempBufSize = (unsigned)inSize;
					(*srcLen) += inSize;
					*status = __LZMA_STATUS_NEEDS_MORE_INPUT;
					return __LZMA_SZ_OK;
				}
				if (checkEndMarkNow && dummyRes != __LZMA_DUMMY_MATCH)
				{
					*status = __LZMA_STATUS_NOT_FINISHED;
					return __LZMA_SZ_ERROR_DATA;
				}
				bufLimit = src;
			}
			else bufLimit = src + inSize - __LZMA_REQUIRED_INPUT_MAX;
			p->buf = src;
			if (__LZMA_LzmaDec_DecodeReal2(p, dicLimit, bufLimit) != 0) return __LZMA_SZ_ERROR_DATA;
			size_t processed = (size_t)(p->buf - src);
			(*srcLen) += processed;
			src += processed;
			inSize -= processed;
		}
		else
		{
			unsigned rem = p->tempBufSize, lookAhead = 0;
			while (rem < __LZMA_REQUIRED_INPUT_MAX && lookAhead < inSize) p->tempBuf[rem++] = src[lookAhead++];
			p->tempBufSize = rem;
			if (rem < __LZMA_REQUIRED_INPUT_MAX || checkEndMarkNow)
			{
				int dummyRes = __LZMA_LzmaDec_TryDummy(p, p->tempBuf, rem);
				if (dummyRes == __LZMA_DUMMY_ERROR)
				{
					(*srcLen) += lookAhead;
					*status = __LZMA_STATUS_NEEDS_MORE_INPUT;
					return __LZMA_SZ_OK;
				}
				if (checkEndMarkNow && dummyRes != __LZMA_DUMMY_MATCH)
				{
					*status = __LZMA_STATUS_NOT_FINISHED;
					return __LZMA_SZ_ERROR_DATA;
				}
			}
			p->buf = p->tempBuf;
			if (__LZMA_LzmaDec_DecodeReal2(p, dicLimit, p->buf) != 0) return __LZMA_SZ_ERROR_DATA;
			{
				unsigned kkk = (unsigned)(p->buf - p->tempBuf);
				if (rem < kkk) return __LZMA_SZ_ERROR_FAIL;
				rem -= kkk;
				if (lookAhead < rem) return __LZMA_SZ_ERROR_FAIL;
				lookAhead -= rem;
			}
			(*srcLen) += lookAhead;
			src += lookAhead;
			inSize -= lookAhead;
			p->tempBufSize = 0;
		}
	}
	if (p->code == 0) *status = __LZMA_STATUS_FINISHED_WITH_MARK;
	return (p->code == 0) ? __LZMA_SZ_OK : __LZMA_SZ_ERROR_DATA;
}

static int __LZMA_LzmaDecode(uint8_t *dest, size_t *destLen, const uint8_t *src, size_t *srcLen,
							 const uint8_t *propData, unsigned propSize, __LZMA_ELzmaFinishMode finishMode,
							 __LZMA_ELzmaStatus *status, __LZMA_ISzAlloc *alloc) {
	__LZMA_CLzmaDec p;
	size_t outSize = *destLen, inSize = *srcLen;
	*destLen = *srcLen = 0;
	*status = __LZMA_STATUS_NOT_SPECIFIED;
	if (inSize < __LZMA_RC_INIT_SIZE) return __LZMA_SZ_ERROR_INPUT_EOF;
	__LZMA_LzmaDec_Construct(&p);
	__LZMA_RINOK(__LZMA_LzmaDec_AllocateProbs(&p, propData, propSize, alloc));
	p.dic = dest;
	p.dicBufSize = outSize;
	__LZMA_LzmaDec_Init(&p);
	*srcLen = inSize;
	int res = __LZMA_LzmaDec_DecodeToDic(&p, outSize, src, srcLen, finishMode, status);
	*destLen = p.dicPos;
	if (res == __LZMA_SZ_OK && *status == __LZMA_STATUS_NEEDS_MORE_INPUT) res = __LZMA_SZ_ERROR_INPUT_EOF;
	__LZMA_LzmaDec_FreeProbs(&p, alloc);
	return res;
}

static int __LZMA_LzmaUncompress(uint8_t *dest, size_t *destLen, const uint8_t *src, size_t *srcLen,
								 const uint8_t *props, size_t propsSize) {
	__LZMA_ISzAlloc g_Alloc = { __LZMA_SzAlloc, __LZMA_SzFree };
	__LZMA_ELzmaStatus status;
	return __LZMA_LzmaDecode(dest, destLen, src, srcLen, props, (unsigned)propsSize, __LZMA_FINISH_ANY, &status, &g_Alloc);
}


/**
 @brief Get lzma decompressed data.
 @warning First 4 bytes of data should be uint32 with decompressed size value.
 @param lzmaData Lzma compressed data. First 4 bytes should be uint32 with decompressed size value.
 @return Decompressed data or nil on error or data is not lzma compressed.
 */
NS_INLINE NSData * NSDataGetLzmaDecompressData(NSData * lzmaData)
{
	if (!lzmaData) return nil;
#if defined(DEBUG)
	assert([lzmaData isKindOfClass:[NSData class]]);
#endif
	const NSUInteger lzmaDataLen = [lzmaData length];
	if (lzmaDataLen < (sizeof(uint32_t) + __LZMA_PROPS_SIZE)) return nil;
	uint8_t * sizePtr = (uint8_t *)[lzmaData bytes];
	uint8_t * props = sizePtr + sizeof(uint32_t);
	uint8_t * inBuff = props + __LZMA_PROPS_SIZE;
	uint32_t * int32Ptr = (uint32_t *)sizePtr;
	uint8_t * unCompressedBuffer = (uint8_t *)malloc((*int32Ptr));
	if (!unCompressedBuffer) return nil;
	size_t dstLen = *int32Ptr;
	size_t srcLen = [lzmaData length] - __LZMA_PROPS_SIZE - sizeof(uint32_t);
	int res = __LZMA_LzmaUncompress((uint8_t *)unCompressedBuffer,
									&dstLen,
									inBuff,
									&srcLen,
									props,
									__LZMA_PROPS_SIZE);
	if (res == __LZMA_SZ_OK && (uint32_t)dstLen == (*int32Ptr))
	{
		NSData * d = [NSData dataWithBytesNoCopy:unCompressedBuffer length:dstLen freeWhenDone:YES];
		if (d) return d;
	}
	free(unCompressedBuffer);
	return nil;
}

#endif

