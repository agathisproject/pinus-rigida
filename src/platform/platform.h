// SPDX-License-Identifier: GPL-3.0-or-later

#ifndef PLATFORM_QD63TEHTMHG5D99M
#define	PLATFORM_QD63TEHTMHG5D99M
/** @file */

#include <stdio.h>

#include "../hw/gpio.h"
#include "../hw/i2c.h"

#define PIN_LED_R PIN_NONE
#define PIN_LED_G PIN_13
#define PIN_LED_B PIN_NONE
#define PIN_D_ADDR0 PIN_4
#define PIN_D_ADDR1 PIN_5
#define PIN_D_ADDR2 PIN_6
#define PIN_U_ADDR0 PIN_7
#define PIN_U_ADDR1 PIN_8
#define PIN_U_ADDR2 PIN_9

void cpu_init(void);
void gpio_init(void);
void i2c_init(void);

#endif /* PLATFORM_QD63TEHTMHG5D99M */
