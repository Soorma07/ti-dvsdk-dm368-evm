Buffer.h File Reference
=======================

::

 #include <xdc/std.h>
 #include <ti/sdo/ce/osal/Memory.h>
 #include <ti/sdo/dmai/Dmai.h>
 #include <ti/sdo/dmai/BufTab.h>

Data Structures
---------------

::

 struct  Buffer_Attrs

Attributes used when creating a Buffer instance.


Typedefs
--------

::

 typedef struct _Buffer_Object * Buffer_Handle

Handle through which to reference a Buffer instance.

Enumerations
------------

::

 enum  Buffer_Type_ {
   Buffer_Type_BASIC_ = 0,
   Buffer_Type_GRAPHICS_ = 1,
   Buffer_Type_COUNT_
 }

Types of Buffers.

Functions
---------

::

 Buffer_Handle Buffer_create (Int32 size, Buffer_Attrs *attrs)

Creates and allocates a contiguous Buffer.

::

 Buffer_Handle Buffer_clone (Buffer_Handle hBuf)

Creates and clone of an existing Buffer. Only the attributes used while
creating the cloned Buffer will be used.

::

 Void Buffer_print (Buffer_Handle hBuf)

Prints information about a buffer.

::

 Int Buffer_delete (Buffer_Handle hBuf)

Deletes and frees a contiguous Buffer.

::

 Void Buffer_getAttrs (Buffer_Handle hBuf, Buffer_Attrs *attrs)

Get the Buffer_Attrs corresponding to existing buffer.

::

 Void Buffer_setUseMask (Buffer_Handle hBuf, UInt16 useMask)

Set the current use mask.

::

 Void Buffer_freeUseMask (Buffer_Handle hBuf, UInt16 useMask)

Free bits in the current use mask. When the resulting use mask is 0, the
Buffer is considered free.

::

 Void Buffer_resetUseMask (Buffer_Handle hBuf)

Set the current use mask to the original use mask, essentially marking the
Buffer as busy.

::

 UInt16 Buffer_getUseMask (Buffer_Handle hBuf)

Get the current use mask of a Buffer.

::

 Int Buffer_getId (Buffer_Handle hBuf)

Get the id of a Buffer. The id identifies a Buffer in a BufTab.

::

 Int8 * Buffer_getUserPtr (Buffer_Handle hBuf)

Get the user pointer of the Buffer. This pointer can be used to access the
Buffer using the CPU.

::

 Int32 Buffer_getPhysicalPtr (Buffer_Handle hBuf)

Get the physical pointer of the Buffer. This pointer can be used by device
drivers and DMA to access the Buffer.

::

 Int32 Buffer_getSize (Buffer_Handle hBuf)

Get the size of a Buffer.

::

 Buffer_Type Buffer_getType (Buffer_Handle hBuf)

Get the type of a Buffer.

::

 Int32 Buffer_getNumBytesUsed (Buffer_Handle hBuf)

When a DMAI module has processed data and written it to a Buffer, it
records the actual number of bytes used (which may or may not be the same as
the size).

::

 Void Buffer_setNumBytesUsed (Buffer_Handle hBuf, Int32 numBytes)

Set the number of bytes used in a Buffer. If you process data outside of
DMAI, call this function to tell the DMAI modules how many bytes it should
process in the Buffer.

::

 Int Buffer_setUserPtr (Buffer_Handle hBuf, Int8 *ptr)

Set the User pointer for a Buffer reference.

::

 Int Buffer_setSize (Buffer_Handle hBuf, Int32 size)

Set the size of a Buffer reference.

::

 Int Buffer_setVirtualSize (Buffer_Handle hBuf, Int32 size)

Set the virtual size of a Buffer.

::

 Bool Buffer_isReference (Buffer_Handle hBuf)

Investigate whether a Buffer instance is a reference or not.

::

 BufTab_Handle Buffer_getBufTab (Buffer_Handle hBuf)

Get the BufTab instance which a Buffer belongs to, if any.

::

 Int Buffer_copy (Buffer_Handle hSrcBuf, Buffer_Handle hDstBuf)

Copies Buffer object from source to destination.

Variables
---------

::

 const Memory_AllocParams Buffer_Memory_Params_DEFAULT

The default parameters for the Memory module while creating a Buffer.

::

 const Buffer_Attrs Buffer_Attrs_DEFAULT

The default parameters when creating a Buffer.
