//
//  LzmaSDKObjCCommon.h
//  ios
//
//  Created by Resident evil on 9/6/15.
//  Copyright (c) 2015 Resident evil. All rights reserved.
//

#ifndef __LZMASDKOBJCCOMMON_H__
#define __LZMASDKOBJCCOMMON_H__

#include <stdint.h>
#include <inttypes.h>

#include "LzmaSDKObjCTypes.h"

#if defined(LZMASDKOBJC)

/**
 @brief 12 = 4Kb min
 */
#define LZMASDKOBJC_DEFAULT_BUFFER_SIZE ((uint32_t)1 << 13)

/**
 @brief Set sream read/write block buffer size.
 @detailed Affect to the exteracted block size sended to output.
 Ammount of data size to write to the output file/stream.
 */
LZMASDKOBJC_EXTERN void LzmaSDKObjCSetRWStreamBlockSize(uint32_t blockSize);
LZMASDKOBJC_EXTERN uint32_t LzmaSDKObjCGetRWStreamBlockSize();



LZMASDKOBJC_EXTERN void LzmaSDKObjCSetRWDecoderBufferSize(uint32_t blockSize);
LZMASDKOBJC_EXTERN uint32_t LzmaSDKObjCGetRWDecoderBufferSize();


#endif

#endif
