#include "rp2350_regs.h"

const int LED_PIN = 25;

int main() {
    for (;;) {
	    REG(RESETS_BASE) = 01;
    }
    return 0;
}
