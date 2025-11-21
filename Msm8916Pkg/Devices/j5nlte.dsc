[Defines]
  PLATFORM_NAME                  = Msm8916Pkg
  PLATFORM_GUID                  = 28f1a3bf-193a-47e3-a7b9-5a435eaab2ee
  PLATFORM_VERSION               = 0.1
  DSC_SPECIFICATION              = 0x00010019
  OUTPUT_DIRECTORY               = Build/$(PLATFORM_NAME)
  SUPPORTED_ARCHITECTURES        = AARCH64
  BUILD_TARGETS                  = DEBUG|RELEASE
  SKUID_IDENTIFIER               = DEFAULT
  FLASH_DEFINITION               = Msm8916Pkg/Devices/j5nlte.fdf

!include Msm8916Pkg/Msm8916Pkg.dsc

[BuildOptions.common]
  GCC:*_*_AARCH64_CC_FLAGS = 

[PcdsFixedAtBuild.common]
  # Simple FrameBuffer
  gMsm8916PkgTokenSpaceGuid.PcdMipiFrameBufferWidth|1080
  gMsm8916PkgTokenSpaceGuid.PcdMipiFrameBufferHeight|2280
  gMsm8916PkgTokenSpaceGuid.PcdMipiFrameBufferAddress|0x9d400000

  # SmBios Information
  gMsm8916PkgTokenSpaceGuid.PcdDeviceVendor|"Samsung"
  gMsm8916PkgTokenSpaceGuid.PcdDeviceProduct|"Galaxy J5 2015"
  gMsm8916PkgTokenSpaceGuid.PcdDeviceCodeName|"j5nlte"
