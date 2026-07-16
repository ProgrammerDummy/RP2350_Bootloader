#include "rp2350_regs.h"

const int LED_PIN = 25;

int main() {
    // deassert IO_BANK0 and PADS_BANK0 reset bits and wait for them to clear
    REG(RESETS_BASE + REG_ATOMIC_CLR_OFFSET) = RESETS_RESET_IO_BANK0_BITS | RESET_PADS_BANK0_BITS;
    while((~REG(RESETS_BASE + RESETS_RESET_DONE_OFFSET)) & (RESETS_RESET_IO_BANK0_BITS | RESET_PADS_BANK0_BITS));

    // set GPIO25 to SIO_25 (pg. 651, rp2350 datasheet)
    REG(IO_BANK0_BASE + IO_BANK0_GPIO25_CTRL_OFFSET) = GPIO_FUNC_SIO;

    // GPIO_25 clear pad isolation bit (pg. 800, rp2350 datasheet)
    // Additional note: You could enable IE bit but we don't need to because we aren't reading from GPIO25
    REG(PADS_BANK0_BASE + PADS_BANK0_GPIO25_OFFSET + REG_ATOMIC_CLR_OFFSET) = PADS_BANK0_GPIO25_ISO_BITS;

    // set SIO output enable for GPIO25 pg. 64, rp2350 datasheet)
    REG(SIO_BASE + SIO_GPIO_OE_SET_OFFSET) = (1u << LED_PIN);
    for (;;) {
        // perform xor on state of GPIO25
        REG(SIO_BASE + SIO_GPIO_OUT_XOR_OFFSET) = (1u << LED_PIN);
        for (volatile int i = 0; i < 10000000; i++) {
        }
    }
    return 0;
}

