/* 
 * Copyright (c) 2010, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * 
 */
/*
 *  ======== bios_rts.h ========
 *
 * This file contains Non-BIOS version of MEM, SYS, HWI, and DBC implementation
 */


#ifndef _BIOS_RTS_
#define _BIOS_RTS_


#include <stdlib.h>

#if DBC_ASSERTS

extern void SYS_abort(char *s, ...);

#define DBC_assert(c) if (!(c)) { \
        SYS_abort("Assertion Failed: file=%s, line=%d.\n", __FILE__, \
        __LINE__); }

#define DBC_require     DBC_assert
#define DBC_ensure      DBC_assert

#else

#define DBC_assert(c)
#define DBC_require(c)
#define DBC_ensure(c)

#endif  /* DBC_ASSERTS */

#define MEM_calloc(segid, size, align) MEM_valloc(segid, size, align, 0)

extern Void * MEM_alloc(Int segid, size_t size, size_t align);
extern Void * MEM_valloc(Int segid, size_t size, size_t align, Char val);
extern Bool MEM_free(Int segid, Void * buf, size_t size);

extern Void TSK_enable(Void);
extern Void TSK_disable(Void);

#endif /* _BIOS_RTS_ */

/*
 *  @(#) ti.sdo.fc.dman3.examples.fastcopy; 1, 0, 0,235; 12-1-2010 17:24:28; /db/atree/library/trees/fc/fc-p01x/src/ xlibrary

 */

