//
//  LzmaSDKObjCCommon.c
//  ios
//
//  Created by Resident evil on 9/6/15.
//  Copyright (c) 2015 Resident evil. All rights reserved.
//

#include "LzmaSDKObjCCommon.h"

#if defined(LZMASDKOBJC)

static uint32_t _LzmaSDKObjCGetRWDecoderBufferSize = LZMASDKOBJC_DEFAULT_BUFFER_SIZE;
void LzmaSDKObjCSetRWDecoderBufferSize(uint32_t blockSize) { _LzmaSDKObjCGetRWDecoderBufferSize = blockSize; }
uint32_t LzmaSDKObjCGetRWDecoderBufferSize() { return _LzmaSDKObjCGetRWDecoderBufferSize; }

#endif
