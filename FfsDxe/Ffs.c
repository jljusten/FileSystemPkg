/** @file

    ...

**/

#include <PiDxe.h>
#include <Protocol/SimpleFileSystem.h>
#include <Protocol/FirmwareVolume2.h>
#include <Library/BaseLib.h>
#include <Library/DebugLib.h>
#include <Library/UefiBootServicesTableLib.h>
#include <Library/UefiDriverEntryPoint.h>
#include <Library/UefiLib.h>
#include <Library/MemoryAllocationLib.h>

//
// Private data structures
//

#define FILE_SYSTEM_PRIVATE_DATA_SIGNATURE SIGNATURE_32 ('f', 'f', 's', 't')

typedef struct {
  UINT32                          Signature;
  EFI_SIMPLE_FILE_SYSTEM_PROTOCOL SimpleFileSystem;
  EFI_FIRMWARE_VOLUME2_PROTOCOL   *FirmwareVolume2;
} FILE_SYSTEM_PRIVATE_DATA;

#define FILE_SYSTEM_PRIVATE_DATA_FROM_THIS(a) CR (a, FILE_SYSTEM_PRIVATE_DATA, SimpleFileSystem, FILE_SYSTEM_PRIVATE_DATA_SIGNATURE)

//
// SimpleFileSystem and File protocol functions
//

EFI_STATUS
EFIAPI
FfsOpenVolume (
  IN EFI_SIMPLE_FILE_SYSTEM_PROTOCOL  *This,
  OUT EFI_FILE_PROTOCOL               **Root
  )
{
  return EFI_ERROR;
}

EFI_STATUS
EFIAPI
FfsOpen (
  IN  EFI_FILE_PROTOCOL *This,
  OUT EFI_FILE_PROTOCOL **NewHandle,
  IN  CHAR16            *FileName,
  IN  UINT64            OpenMode,
  IN  UINT64            Attributes
  )
{
  return EFI_ERROR;
}

EFI_STATUS
EFIAPI
FfsClose (IN EFI_FILE_PROTOCOL *This)
{
  return EFI_ERROR;
}

EFI_STATUS
EFIAPI
FfsDelete (IN EFI_FILE_PROTOCOL *This)
{
  return EFI_ERROR;
}

EFI_STATUS
EFIAPI
FfsRead (
  IN EFI_FILE_PROTOCOL *This,
  IN OUT UINTN *BufferSize,
  OUT VOID *Buffer
  )
{
  return EFI_ERROR;
}

EFI_STATUS
EFIAPI
FfsWrite (
  IN EFI_FILE_PROTOCOL *This,
  IN OUT UINTN *BufferSize,
  IN VOID *Buffer
  )
{
  return EFI_ERROR;
}

EFI_STATUS
EFIAPI
FfsGetPosition (
  IN EFI_FILE_PROTOCOL *This,
  OUT UINT64 *Position
  )
{
  return EFI_ERROR;
}

EFI_STATUS
EFIAPI
FfsSetPosition (
  IN EFI_FILE_PROTOCOL *This,
  IN UINT64 Position
  )
{
  return EFI_ERROR;
}

EFI_STATUS
EFIAPI
FfsGetInfo (
  IN EFI_FILE_PROTOCOL *This,
  IN EFI_GUID *InformationType,
  IN OUT UINTN *BufferSize,
  OUT VOID *Buffer
  )
{
  return EFI_ERROR;
}

EFI_STATUS
EFIAPI
FfsSetInfo (
  IN EFI_FILE_PROTOCOL *This,
  IN EFI_GUID *InformationType,
  IN UINTN BufferSize,
  IN VOID *Buffer
  )
{
  return EFI_ERROR;
}

EFI_STATUS
EFIAPI
FfsFlush (IN EFI_FILE_PROTOCOL *This)
{
  return EFI_ERROR;
}

//
// Protocol template
//

EFI_EVENT mFfsRegistration;

// ...

//
// Global functions
//

VOID
EFIAPI
FfsNotificationEvent (
  IN EFI_EVENT Event,
  IN VOID      *Context
  )
/**

  Callback function, notified when new FV2 volumes are mounted in the system.

  @param Event
  @param Context

**/
{
  DEBUG ((EFI_D_INFO, "New FV Volume detected!\n"));
  return;
}

EFI_STATUS
EFIAPI
InitializeFfsFileSystem (
  IN EFI_HANDLE       ImageHandle,
  IN EFI_SYSTEM_TABLE *SystemTable
  )
/**

  Entry point for the driver.

  @param ImageHandle
  @param SystemTable

**/
{
  EfiCreateProtocolNotifyEvent (
    &gEfiFirmwareVolume2ProtocolGuid,
    TPL_CALLBACK,
    FfsNotificationEvent,
    NULL,
    &mFfsRegistration
    );

  return EFI_SUCCESS;
}
