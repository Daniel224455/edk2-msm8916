DefinitionBlock("DSDT.AML", "DSDT", 0x02, "QCOMM ", "MSM8916 ", 3)
{
	/* CPU */
	Scope(\_SB_)
	{
		/* 8 CPU Cores */
		Device(CPU0) 
		{
			Name(_HID, "ACPI0007")
			Name(_UID, 0)
		}
		Device(CPU1) 
		{
			Name(_HID, "ACPI0007")
			Name(_UID, 1)
		}
		Device(CPU2) 
		{
			Name(_HID, "ACPI0007")
			Name(_UID, 2)
		}
		Device(CPU3) 
		{
			Name(_HID, "ACPI0007")
			Name(_UID, 3)
		}
	}

	/* EMMC */
	Device (SDC1)
	{
		Name (_HID, "QCOM2466")
		Name (_CID, "ACPI\QCOM2466")
		Name (_UID, Zero)  // _UID: Unique ID
		Name (_CCA, Zero)  // _CCA: Cache Coherency Attribute

		Method (_CRS, 0, NotSerialized)  // _CRS: Current Resource Settings
		{
			Name (RBUF, ResourceTemplate ()
			{
				Memory32Fixed (ReadWrite,
				0x07824900,	 // Address Base
				0x00000200,	 // Address Length
				)
				Interrupt (ResourceConsumer, Level, ActiveHigh, Exclusive, ,, )
				{
					155,
				}
			})
			Return (RBUF) /* \_SB_.SDC1._CRS.RBUF */
		}

		Device (EMMC)
		{
			Method (_ADR, 0, NotSerialized)  // _ADR: Address
			{
				Return (0x08)
			}

			Method (_RMV, 0, NotSerialized)  // _RMV: Removal Status
			{
				Return (Zero)
			}
		}

		Method (_DIS, 0, NotSerialized)  // _DIS: Disable Device
		{
		}

		Method (_STA, 0, NotSerialized)  // _STA: Status
		{
			Return (0x0F)
		}
	}

	Device (SDC2)
	{
		Name (_HID, "QCOM2466")
		Name (_CID, "ACPI\QCOM2466")
		Name (_UID, 1)  // _UID: Unique ID
		Name (_CCA, Zero)  // _CCA: Cache Coherency Attribute

		Method (_CRS, 0, NotSerialized)  // _CRS: Current Resource Settings
		{
			Name (RBUF, ResourceTemplate ()
			{
				Memory32Fixed (ReadWrite,
					0x07864900,	 // Address Base
					0x00000200,	 // Address Length
				)
				Interrupt (ResourceConsumer, Level, ActiveHigh, Exclusive, ,, )
				{
					157,
				}
			})
			Return (RBUF) /* \_SB_.SDC1._CRS.RBUF */
		}

		Method (_DIS, 0, NotSerialized)  // _DIS: Disable Device
		{
		}

		Method (_STA, 0, NotSerialized)  // _STA: Status
		{
			Return (0x0F)
		}
	}
}
