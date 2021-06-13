// SPDX-License-Identifier: GPL-3.0-or-later

#ifndef UART_PP6P2STWBZYM3AAT
#define UART_PP6P2STWBZYM3AAT

#include <stdio.h>
#define BAUD 115200
#include <util/setbaud.h>

void uart0_init(void);

int uart0_putchar(char c, FILE *stream);
int uart0_getchar(FILE *stream);

#endif /* UART_PP6P2STWBZYM3AAT */
