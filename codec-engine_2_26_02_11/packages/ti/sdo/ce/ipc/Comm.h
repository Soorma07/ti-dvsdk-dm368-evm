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
 *  ======== Comm.h ========
 */
#ifndef ti_sdo_ce_ipc_Comm_
#define ti_sdo_ce_ipc_Comm_

#ifdef __cplusplus
extern "C" {
#endif

#define Comm_GTNAME "OC" /* TODO: Should this be changed? */

/*
 *  ======== Comm_MSGSIZE ========
 *  Maximum size of communication buffers, defined by the configuration
 *  parameter in Global.xdc.
 */
extern UInt32 Comm_MSGSIZE;

/*
 *  ======== Comm_Queue ========
 */
typedef UInt32 Comm_Queue;

/*
 *  ======== Comm_Handle ========
 */
typedef struct Comm_Obj *Comm_Handle;

/*
 *  ======== Comm_QType ========
 */
typedef enum {
    Comm_PEND,
    Comm_CALL
} Comm_QType;

/*
 *  ======== Comm_CallFxn ========
 */
typedef Void (*Comm_CallFxn)(Ptr callHandle);

/*
 *  ======== Comm_Attrs ========
 */
typedef struct Comm_Attrs {
    Comm_QType      type;
    Ptr             callHandle;
    Comm_CallFxn    callFxn;
} Comm_Attrs;

extern Comm_Attrs Comm_ATTRS;   /* default attrs */

/*
 *  ======== Comm_MsgHeader ========
 * Comm header must be defined, but its fields are irrelevant for the user
 * Note: this header must be larger than all underlying msgq implementations
 * (which require a header to maintain message control/transport information)
 */
typedef struct Comm_MsgHeader {
    UInt32 reserved[2]; /* reserved[0] doubles as "next" in the linked list */
    UInt16 reserved1;   /* UInt16 srcProcId; */
    UInt16 reserved2;   /* UInt16 poolId; */
    UInt16 size;
    UInt32 reserved3;   /* UInt32 dstId; */
    UInt32 reserved4;   /* UInt32 srcId; */
    UInt16 msgId;
} Comm_MsgHeader, *Comm_Msg;

/*
 *  ======== Comm_INVALIDMSGQ ========
 */
#define Comm_INVALIDMSGQ    0xFFFF

/*
 *  ======== error status codes ========
 */
#define Comm_EOK            0
#define Comm_EFAIL          1
#define Comm_ETIMEOUT       2

/*
 *  ======== timeout values ========
 */
#define Comm_FOREVER        ((UInt)-1)
#define Comm_POLL           ((UInt)0)

/*
 *  ======== Comm_locate ========
 *  Locate an existing communication queue
 */
extern Int Comm_locate(String queueName, Comm_Queue *queue);

/*
 *  ======== Comm_alloc ========
 *  Allocate a message that can be sent to a communication queue
 */
extern Int Comm_alloc(UInt16 poolId, Comm_Msg *msg, UInt16 size);

/*
 *  ======== Comm_free ========
 *  Free a previously allocated (Comm_alloc) message
 */
extern Int Comm_free(Comm_Msg msg);

/*
 *  ======== Comm_put ========
 *  Send message to specified communication queue
 */
extern Int Comm_put(Comm_Queue queue, Comm_Msg msg);

/*
 *  ======== Comm_get ========
 *  Recieve a message from the specified queue
 */
extern Int Comm_get(Comm_Queue queue, Comm_Msg *msg, UInt timeout);

/*
 *  ======== Comm_getMsgSize ========
 *  Get size of the specified message
 */
extern Int Comm_getMsgSize(Comm_Msg msg);

/*
 *  ======== Comm_getSrcQueue ========
 *  Get id of sender queue from message
 */
extern Int Comm_getSrcQueue(Comm_Msg msg, Comm_Queue *queue);

/*
 *  ======== Comm_setSrcQueue ========
 *  Put id of sender queue into message
 */
extern Void Comm_setSrcQueue(Comm_Msg msg, Comm_Queue queue);

/*
 *  ======== Comm_create ========
 *  Create a new communication queue
 */
extern Comm_Handle Comm_create(String queueName, Comm_Queue *queue,
    Comm_Attrs *attrs);

/*
 *  ======== Comm_delete ========
 *  its evil twin, the delete() function
 */
extern Void Comm_delete(Comm_Handle msgq);

/*
 *  ======== Comm_init ========
 */
extern Bool Comm_init(Void);

/*
 *  ======== Comm_exit ========
 */
extern Void Comm_exit(Void);

/*
 *  ======== Comm_release ========
 */
extern Int Comm_release(Comm_Queue queue);

#ifdef __cplusplus
}
#endif

#endif
/*
 *  @(#) ti.sdo.ce.ipc; 2, 0, 1,183; 12-2-2010 21:24:05; /db/atree/library/trees/ce/ce-r11x/src/ xlibrary

 */

