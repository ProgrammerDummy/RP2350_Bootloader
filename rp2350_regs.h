// rp2350_regs.h

// atomic register access defines (rp2350 datasheet section 2.1.3)
// Note that SIO register cannot use these.
#define REG(x) (*((volatile unsigned int *)(x)))
#define REG_ATOMIC_XOR_OFFSET (0x1000)
#define REG_ATOMIC_SET_OFFSET (0x2000)
#define REG_ATOMIC_CLR_OFFSET (0x3000)


// subsystem resets defines (rp2350 datasheet section 7.5)
#define RESETS_BASE (0x40020000)

#define RESET_PADS_BANK0_BITS (1u << 9)
#define RESETS_RESET_IO_BANK0_BITS (1u << 6)

#define RESETS_RESET_DONE_OFFSET (0x8)


// gpio defines
#define IO_BANK0_BASE (0x40028000)
#define IO_BANK0_GPIO25_CTRL_OFFSET (0x0cc)
#define GPIO_FUNC_SIO (0x05)

#define PADS_BANK0_BASE (0x40038000)
#define PADS_BANK0_GPIO25_OFFSET (0x68)
#define PADS_BANK0_GPIO25_ISO_BITS (1u << 8)
#define PADS_BANK0_GPIO25_IE_BITS (1 << 6)
#define PADS_BANK0_GPIO25_DRIVE_8MA_BITS (1 << 5)

#define SIO_BASE (0xd0000000)
#define SIO_GPIO_OE_SET_OFFSET (0x038)
#define SIO_GPIO_OUT_XOR_OFFSET (0x028)


