// SPDX-License-Identifier: GPL-3.0-or-later

#include "platform.h"

#include <avr/wdt.h>

#include "callback.h"
#include "../agathis/base.h"

void cpu_init(void) {
    wdt_disable();
    uint8_t tmp = MCUSR;
    printf("%s reset reason: %#x\n", PREFIX_MC, tmp);
}

void gpio_init(void) {
    gpio_cfg(PIN_LED_R, PIN_TYPE_OUT);
    gpio_cfg(PIN_LED_G, PIN_TYPE_OUT);
    gpio_cfg(PIN_LED_B, PIN_TYPE_OUT);

    gpio_cfg(PIN_D_ADDR0, PIN_TYPE_IN);
    gpio_cfg(PIN_D_ADDR1, PIN_TYPE_IN);
    gpio_cfg(PIN_D_ADDR2, PIN_TYPE_IN);

    gpio_cfg(PIN_U_ADDR0, PIN_TYPE_OUT);
    gpio_cfg(PIN_U_ADDR1, PIN_TYPE_OUT);
    gpio_cfg(PIN_U_ADDR2, PIN_TYPE_OUT);
    //printf("[GPIO] done\n");
}

void i2c_init(void) {
    i2c_initSlave(0, 100, MOD_STATE.addr_i2c);
    i2c_setTXCallback(0, &tx_i2c);
    i2c_setRXCallback(0, &rx_i2c);
    i2c_showCtrl(0);
}
