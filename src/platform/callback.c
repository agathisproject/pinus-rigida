// SPDX-License-Identifier: GPL-3.0-or-later

#include "callback.h"

#include "../agathis/base.h"

static uint8_t cmd_rcv = 0;
static uint8_t cmd_buff[8] = {0, 0, 0, 0, 0, 0, 0, 0};
static uint32_t scratch = 0;

void tx_i2c(I2CXfer_t *i2c_xfer) {
    if (i2c_xfer->status == I2C_XFER_SL_TX) {
        return;
    }
    printf("[I2C] xfer: %d %d %d\n", i2c_xfer->type, i2c_xfer->status,
           i2c_xfer->nb);
}

void rx_i2c(I2CXfer_t *i2c_xfer) {
    uint8_t cmd = i2c_getRXByte(0, 0);

    //printf("[I2C] xfer: %d %d %d\n", i2c_xfer->type, i2c_xfer->status, i2c_xfer->nb);
    if (i2c_xfer->nb == 1) {
        switch (cmd) {
            case AG_CMD_SUMMARY:
                i2c_setTXByte(0, 0, AG_CMD_SUMMARY_NB);
                i2c_setTXByte(0, 1, AG_PROTO_VER);
                i2c_setTXByte(0, 2, MOD_STATE.flags);
                i2c_setTXByte(0, 3, MOD_STATE.last_err);
                i2c_setTXByte(0, 4, 0x00);
                break;
            case AG_CMD_TYPE:
                i2c_setTXByte(0, 0, AG_CMD_TYPE_NB);
                i2c_setTXByte(0, 1, (uint8_t) (MOD_STATE.type & 0xFF));
                i2c_setTXByte(0, 2, (uint8_t) ((MOD_STATE.type >> 8) & 0xFF));
                break;
            case AG_CMD_CAP:
                i2c_setTXByte(0, 0, AG_CMD_CAP_NB);
                i2c_setTXByte(0, 1, MOD_STATE.caps);
                i2c_setTXByte(0, 2, 0x00);
                break;
            case AG_CMD_MFR:
                i2c_setTXByte(0, 0, AG_CMD_MFR_NB);
                i2c_setTXByte(0, 1, (uint8_t) (scratch & 0xFF));
                i2c_setTXByte(0, 2, (uint8_t) ((scratch >> 8) & 0xFF));
                i2c_setTXByte(0, 3, (uint8_t) ((scratch >> 16) & 0xFF));
                i2c_setTXByte(0, 4, (uint8_t) ((scratch >> 24) & 0xFF));
                break;
            default:
                break;
        }
    } else {
        if (i2c_xfer->nb == (uint16_t) (i2c_getRXByte(0, 1) + 2)) {
            i2c_getRXData(0, i2c_xfer->nb, cmd_buff);
            cmd_rcv = 1;
            switch (cmd_buff[0]) {
                case AG_CMD_SUMMARY:
                    if (cmd_buff[3] & AG_FLAG_RESET) {
                        ag_reset();
                    }
                    break;
                case AG_CMD_CAP:
                    break;
                case AG_CMD_MFR:
                    scratch <<= 8;
                    scratch |= cmd_buff[5];
                    scratch <<= 8;
                    scratch |= cmd_buff[4];
                    scratch <<= 8;
                    scratch |= cmd_buff[3];
                    scratch <<= 8;
                    scratch |= cmd_buff[2];
                    break;
                default:
                    break;
            }
        }
    }
}

uint8_t isRcv(void) {
    return cmd_rcv;
}

void clrRcv(void) {
    cmd_rcv = 0;
}
