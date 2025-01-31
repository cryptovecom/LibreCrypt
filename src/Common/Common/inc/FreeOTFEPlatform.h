// Description: 
// By Sarah Dean
// Email: sdean12@sdean12.org
// WWW:   http://www.FreeOTFE.org/
//
// -----------------------------------------------------------------------------
//

#ifndef _FreeOTFEPlatform_H
#define _FreeOTFEPlatform_H   1

/* 4 projects, threee of them in use
WINCE	FOTFE_PDA		C++ gui for pdas
_WINDLL	FOTFE_PC_DLL	dlls for explorer
		FOTFE_CMD_LINE	cmd line projects for testing
		FOTFE_PC_DRIVER kernel drivers
*/
#ifdef WINCE
  #define FOTFE_PDA          1
#else
  #ifdef _WINDLL
    #define FOTFE_PC_DLL     1
  #else
#ifndef FOTFE_CMD_LINE
    #define FOTFE_PC_DRIVER  1
#endif
  #endif
#endif

#ifdef FOTFE_PDA
//this is now used for windows 32 ui
#undef FOTFE_PC_DRIVER  
#endif

#if (defined(FOTFE_PDA) || defined(FOTFE_PC_DLL) || defined(FOTFE_CMD_LINE)) 
// FreeOTFE4PDA and FreeOTFE DLLs
#include <stdlib.h>  // Required for malloc, free
#define FREEOTFE_MEMALLOC(x)              malloc(x)
#define FREEOTFE_MEMCALLOC(x, y)          calloc(x, y)
#define FREEOTFE_FREE(x)                  free(x)
#define FREEOTFE_MEMZERO(x, size)         memset(x, 0, size)
#define FREEOTFE_MEMCPY(dest, src, size)  memcpy(dest, src, size)
#define FREEOTFE_SWPRINTF                 Platform_swprintf
#endif
#ifdef FOTFE_PC_DRIVER
// FreeOTFE kernel drivers
// Visual Studio has ExAllocatePool(...) marked as deprecated
//#define FREEOTFE_MEMALLOC(x)              ExAllocatePool(NonPagedPool, x)
#define FREEOTFE_MEMALLOC(x)              ExAllocatePoolWithTag(NonPagedPool, x, 'FOTF')
#define FREEOTFE_MEMCALLOC(x, y)          FREEOTFE_MEMALLOC((x * y))
#define FREEOTFE_FREE(x)                  ExFreePool(x)
#define FREEOTFE_MEMZERO(x, size)         RtlZeroMemory(x, size)
#define FREEOTFE_MEMCPY(dest, src, size)  RtlCopyMemory(dest, src, size)
#define FREEOTFE_SWPRINTF                 Platform_swprintf
#endif

#define FREEOTFEBYTE  unsigned char
#define FREEOTFEBOOL  BOOLEAN

#ifdef FOTFE_CMD_LINE
 // #include <ntstatus.h>
#endif

#ifdef FOTFE_PC_DLL
#include <windows.h>
#include <windef.h>
#include <winnt.h>
#include <stdarg.h>
#include <winbase.h>

// Status codes for PC DLL only - use std definitions in the windows ".h"
// files for kernel drive/WINCE
#define STATUS_SUCCESS                   ((NTSTATUS)0x00000000L) // ntsubauth
#define STATUS_UNSUCCESSFUL              ((NTSTATUS)0xC0000001L)
#endif
#if FOTFE_PDA
// #define STATUS_INVALID_PARAMETER         ((NTSTATUS)0xC000000DL)
#endif
#ifdef FOTFE_PC_DLL
#define STATUS_BUFFER_TOO_SMALL          ((NTSTATUS)0xC0000023L)
#define STATUS_INTERNAL_ERROR            ((NTSTATUS)0xC00000E5L)
#define STATUS_INVALID_BUFFER_SIZE       ((NTSTATUS)0xC0000206L)
#define STATUS_NOT_FOUND                 ((NTSTATUS)0xC0000225L)
#endif

#if defined(FOTFE_PC_DLL) || defined(FOTFE_CMD_LINE)
#define NT_SUCCESS(Status) ((NTSTATUS)(Status) >= 0)
//copied from ntstatus.h
#define STATUS_SUCCESS                          ((NTSTATUS)0x00000000L) // ntsubauth
#define STATUS_UNSUCCESSFUL              ((NTSTATUS)0xC0000001L)
#endif


#endif

