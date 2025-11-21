#ifndef _DEVICE_MEMORY_MAP_H_
#define _DEVICE_MEMORY_MAP_H_

#include <Library/ArmLib.h>

#define MAX_ARM_MEMORY_REGION_DESCRIPTOR_COUNT 128

/* Below flag is used for system memory */
#define SYSTEM_MEMORY_RESOURCE_ATTR_CAPABILITIES                               \
  EFI_RESOURCE_ATTRIBUTE_PRESENT | EFI_RESOURCE_ATTRIBUTE_INITIALIZED |        \
      EFI_RESOURCE_ATTRIBUTE_TESTED | EFI_RESOURCE_ATTRIBUTE_UNCACHEABLE |     \
      EFI_RESOURCE_ATTRIBUTE_WRITE_COMBINEABLE |                               \
      EFI_RESOURCE_ATTRIBUTE_WRITE_THROUGH_CACHEABLE |                         \
      EFI_RESOURCE_ATTRIBUTE_WRITE_BACK_CACHEABLE |                            \
      EFI_RESOURCE_ATTRIBUTE_EXECUTION_PROTECTABLE

typedef enum { NoHob, AddMem, AddDev, HobOnlyNoCacheSetting, MaxMem } DeviceMemoryAddHob;

#define MEMORY_REGION_NAME_MAX_LENGTH 32

typedef struct {
  CHAR8                        Name[MEMORY_REGION_NAME_MAX_LENGTH];
  EFI_PHYSICAL_ADDRESS         Address;
  UINT64                       Length;
  DeviceMemoryAddHob           HobOption;
  EFI_RESOURCE_TYPE            ResourceType;
  EFI_RESOURCE_ATTRIBUTE_TYPE  ResourceAttribute;
  EFI_MEMORY_TYPE              MemoryType;
  ARM_MEMORY_REGION_ATTRIBUTES ArmAttributes;
} ARM_MEMORY_REGION_DESCRIPTOR_EX, *PARM_MEMORY_REGION_DESCRIPTOR_EX;

#define MEM_RES EFI_RESOURCE_MEMORY_RESERVED
#define MMAP_IO EFI_RESOURCE_MEMORY_MAPPED_IO
#define SYS_MEM EFI_RESOURCE_SYSTEM_MEMORY

#define SYS_MEM_CAP SYSTEM_MEMORY_RESOURCE_ATTR_CAPABILITIES
#define INITIALIZED EFI_RESOURCE_ATTRIBUTE_INITIALIZED
#define WRITE_COMBINEABLE EFI_RESOURCE_ATTRIBUTE_WRITE_COMBINEABLE
#define UNCACHEABLE EFI_RESOURCE_ATTRIBUTE_UNCACHEABLE

#define Reserv EfiReservedMemoryType
#define Conv EfiConventionalMemory
#define BsData EfiBootServicesData
#define BsCode EfiBootServicesCode
#define RtData EfiRuntimeServicesData
#define RtCode EfiRuntimeServicesCode
#define MmIO EfiMemoryMappedIO

#define NS_DEVICE ARM_MEMORY_REGION_ATTRIBUTE_NONSECURE_DEVICE
#define DEVICE ARM_MEMORY_REGION_ATTRIBUTE_DEVICE
#define WRITE_THROUGH ARM_MEMORY_REGION_ATTRIBUTE_WRITE_THROUGH
#define WRITE_THROUGH_XN ARM_MEMORY_REGION_ATTRIBUTE_WRITE_THROUGH
#define WRITE_BACK ARM_MEMORY_REGION_ATTRIBUTE_WRITE_BACK
#define WRITE_BACK_XN ARM_MEMORY_REGION_ATTRIBUTE_WRITE_BACK
#define UNCACHED_UNBUFFERED ARM_MEMORY_REGION_ATTRIBUTE_UNCACHED_UNBUFFERED
#define UNCACHED_UNBUFFERED_XN ARM_MEMORY_REGION_ATTRIBUTE_UNCACHED_UNBUFFERED

static ARM_MEMORY_REGION_DESCRIPTOR_EX gDeviceMemoryDescriptorEx[] = {
    /* Name               Address     Length      HobOption        ResourceAttribute    ArmAttributes
                                                          ResourceType          MemoryType */

    /* DDR Regions */
    {"CPU Vectors",       0x80000000, 0x00001000, AddMem, SYS_MEM, SYS_MEM_CAP, BsData, WRITE_BACK},
    {"RAM Partition",     0x80001000, 0x0007F000, AddMem, SYS_MEM, SYS_MEM_CAP, Conv,   WRITE_BACK_XN},
    {"UEFI FD",           0x80080000, 0x00200000, AddMem, SYS_MEM, SYS_MEM_CAP, BsData, WRITE_BACK},
    {"RAM Partition",     0x80280000, 0x02F80000, AddMem, SYS_MEM, SYS_MEM_CAP, Conv,   WRITE_BACK_XN},
    {"Display Reserved",  0x83200000, 0x00C00000, AddMem, MEM_RES, SYS_MEM_CAP, Reserv, WRITE_THROUGH_XN}, //unsure
    {"RAM Partition",     0x83E00000, 0x01900000, AddMem, SYS_MEM, SYS_MEM_CAP, Conv,   WRITE_BACK_XN},
    {"Hypervisor",        0x85700000, 0x00600000, AddMem, SYS_MEM, SYS_MEM_CAP, Reserv, NS_DEVICE},
    {"RAM Partition",     0x85D00000, 0x0A300000, AddMem, SYS_MEM, SYS_MEM_CAP, Conv,   WRITE_BACK_XN},
    {"DXE Heap",          0x90000000, 0x03C00000, AddMem, SYS_MEM, SYS_MEM_CAP, Conv,   WRITE_BACK_XN},
    {"UEFI Stack",        0x93C00000, 0x00040000, AddMem, SYS_MEM, SYS_MEM_CAP, BsData, WRITE_BACK_XN},
    {"RAM Partition",     0x93C40000, 0x4C3C0000, AddMem, SYS_MEM, SYS_MEM_CAP, Conv,   WRITE_BACK_XN},

    /* Register */
    {"Periphs",           0x00000000, 0x60000000, NoHob, MMAP_IO, UNCACHEABLE, MmIO, NS_DEVICE},
    {"GIC Distributor",    0x0b000000, 0x00001000, AddDev, MMAP_IO, UNCACHEABLE, MmIO,   DEVICE},
    {"GIC Redistributors",    0x0b002000, 0x00001000, AddDev, MMAP_IO, UNCACHEABLE, MmIO,   DEVICE},

    /* Terminator for MMU */
    {"Terminator", 0, 0, 0, 0, 0, 0, 0}};

#endif
