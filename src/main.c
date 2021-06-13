// SPDX-License-Identifier: GPL-3.0-or-later

#include <stdio.h>

//define F_CPU 16000000L

#include <avr/interrupt.h>
#include <util/delay.h>

#include "hw/uart.h"
#include "platform/platform.h"
#include "agathis/base.h"

static FILE uart0_str = FDEV_SETUP_STREAM(uart0_putchar, uart0_getchar,
                        _FDEV_SETUP_RW);

void init(void) {
    uart0_init();
    stdin = stdout = &uart0_str;
    cpu_init();

    gpio_init();
    ag_init();
    i2c_init();

    sei();
}

int main(void) {
    init();

    while (1) {
        _delay_ms(1000);
        printf("test\n");
    }
    return 0;
}
