#include <stdio.h>
#include <RP2350.h>

const int LED_PIN = 25;

int main() {
    // set GPIO25 to SIO_25 (pg. 651, rp2350 datasheet)
    IO_BANK0->GPIO25_CTRL = 0x05;

    // GPIO_25 pulldown enable, 12 MA drive strength, input enable (pg. 800, rp2350 datasheet)
    PADS_BANK0->GPIO25 = 0x34; // 0b00110100

    // set output enable for GPIO25 (pg. 64, rp2350 datasheet)
    SIO->GPIO_OE = (1u << LED_PIN);
    for (;;) {
        // perform an xor on the state of GPIO25
        SIO->GPIO_OUT_XOR = (1u << LED_PIN);

	// implement short delay. I'm not sure how long this delay is, but it looks around 100 ms from testing
        for (int i = 0; i < 10000000; i++) {
            __NOP();
        }
    }
    return 0;
}
