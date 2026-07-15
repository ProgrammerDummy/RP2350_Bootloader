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

        // standard clock speed of RP2350 is 150 MHz, with 4 cycles per loop, should be around 270 ms with 10000000 loops
        // but it looks like around 1 per second on the board so im not sure 
        for (int i = 0; i < 10000000; i++) {
            __NOP();
        }
    }
    return 0;
}
