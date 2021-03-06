#include "sdk_cfg.h"
#include "dac/dac_api.h"
#include "dac/eq_api.h"
#include "dac/eq.h"
#include "crc_api.h"
#include "common/flash_cfg.h"
#include "file_operate/logic_dev_list.h"
#if EQ_EN

#define USE_EQ_DBG_MALLOC 1

extern void * zebra_malloc(u32 size);
extern void zebra_free(void * P);
#define eq_malloc	zebra_malloc
#define	eq_free		zebra_free

#if USE_EQ_DBG_MALLOC
static eq_dbg_online_t *eq_dbg_online;

static eq_dbg_online_t __eq_dbg_online = {

0x06,0x00,0x00,0x00,0x0A,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xF4,0xFF,0xFF,0xFF,0x03,0x00,0x00,0x00,

0x0C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x06,0x00,0x00,0x00,0x00,0x00,0x00,0x00,

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x05,0x00,0x00,0x00,0x87,0xDB,0x1F,0x00,

0x6F,0x24,0xF0,0xFF,0x37,0x12,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0xFF,0xFF,0xFF,

0x71,0xC8,0x1F,0x00,0x0B,0x37,0xF0,0xFF,0x86,0x1B,0x00,0x00,0x00,0x00,0x00,0x00,

0xFF,0xFF,0xFF,0xFF,0x0A,0xDC,0x1F,0x00,0x5D,0x23,0xF0,0xFF,0xAE,0x11,0x00,0x00,

0x00,0x00,0x00,0x00,0xFF,0xFF,0xFF,0xFF,0xF1,0x97,0x1E,0x00,0x33,0x59,0xF1,0xFF,

0x99,0xAC,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0xFF,0xFF,0xFF,0x4E,0x53,0x1D,0x00,

0x0A,0x79,0xF2,0xFF,0x85,0x3C,0x01,0x00,0x00,0x00,0x00,0x00,0xFF,0xFF,0xFF,0xFF,

0xB8,0xE7,0x1A,0x00,0x94,0x6A,0xF4,0xFF,0x4A,0x35,0x02,0x00,0x00,0x00,0x00,0x00,

0xFF,0xFF,0xFF,0xFF,0x20,0x43,0x16,0x00,0xFC,0x97,0xF7,0xFF,0xFE,0xCB,0x03,0x00,

0x00,0x00,0x00,0x00,0xFF,0xFF,0xFF,0xFF,0x0A,0x08,0x0C,0x00,0x50,0x59,0xFD,0xFF,

0xA8,0xAC,0x06,0x00,0x00,0x00,0x00,0x00,0xFF,0xFF,0xFF,0xFF,0x01,0xBE,0xF0,0xFF,

0x66,0xCB,0xFD,0xFF,0xB3,0xE5,0x06,0x00,0x00,0x00,0x00,0x00,0xFF,0xFF,0xFF,0xFF,

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,

0x00,0x00,0x00,0x00,0x4C,0xB7,0x1F,0x00,0x8B,0x48,0xF0,0xFF,0x46,0x24,0x00,0x00,

0x00,0x00,0x00,0x00,0xFF,0xFF,0xFF,0xFF,0x98,0x90,0x1F,0x00,0x5C,0x6D,0xF0,0xFF,

0xAE,0x36,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0xFF,0xFF,0xFF,0x32,0xB7,0x1F,0x00,

0x6C,0x46,0xF0,0xFF,0x36,0x23,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0xFF,0xFF,0xFF,

0x5F,0x2F,0x1D,0x00,0xAA,0x97,0xF2,0xFF,0xD5,0x4B,0x01,0x00,0x00,0x00,0x00,0x00,

0xFF,0xFF,0xFF,0xFF,0xB1,0xA2,0x1A,0x00,0x5D,0x9E,0xF4,0xFF,0x2E,0x4F,0x02,0x00,

0x00,0x00,0x00,0x00,0xFF,0xFF,0xFF,0xFF,0x81,0xBE,0x15,0x00,0x48,0xEA,0xF7,0xFF,

0x24,0xF5,0x03,0x00,0x00,0x00,0x00,0x00,0xFF,0xFF,0xFF,0xFF,0xC2,0x94,0x0C,0x00,

0xB3,0x0D,0xFD,0xFF,0xDA,0x86,0x06,0x00,0x00,0x00,0x00,0x00,0xFF,0xFF,0xFF,0xFF,

0xBF,0xA2,0xFE,0xFF,0x08,0xDE,0x07,0x00,0x04,0xEF,0x0B,0x00,0x00,0x00,0x00,0x00,

0xFF,0xFF,0xFF,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x8A,0x6F,0x1F,0x00,

0xD4,0x8F,0xF0,0xFF,0xEA,0x47,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0xFF,0xFF,0xFF,

0x0B,0x20,0x1F,0x00,0xDF,0xD7,0xF0,0xFF,0xF0,0x6B,0x00,0x00,0x00,0x00,0x00,0x00,

0xFF,0xFF,0xFF,0xFF,0xE6,0x6A,0x1F,0x00,0xA8,0x8B,0xF0,0xFF,0xD4,0x45,0x00,0x00,

0x00,0x00,0x00,0x00,0xFF,0xFF,0xFF,0xFF,0x3B,0x5A,0x1A,0x00,0x05,0xD4,0xF4,0xFF,

0x02,0x6A,0x02,0x00,0x00,0x00,0x00,0x00,0xFF,0xFF,0xFF,0xFF,0x14,0x33,0x15,0x00,

0x64,0x3F,0xF8,0xFF,0xB2,0x1F,0x04,0x00,0x00,0x00,0x00,0x00,0xFF,0xFF,0xFF,0xFF,

0x26,0x9C,0x0B,0x00,0x6E,0x93,0xFD,0xFF,0xB7,0xC9,0x06,0x00,0x00,0x00,0x00,0x00,

0xFF,0xFF,0xFF,0xFF,0xEB,0xF4,0xFE,0xFF,0xE8,0x2A,0x07,0x00,0x74,0x95,0x0B,0x00,

0x00,0x00,0x00,0x00,0xFF,0xFF,0xFF,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,

0x00,0x00,0x00,0x00,0x7B,0xDE,0x1F,0x00,0x7C,0x21,0xF0,0xFF,0xBE,0x10,0x00,0x00,

0x00,0x00,0x00,0x00,0xFF,0xFF,0xFF,0xFF,0xF7,0xCC,0x1F,0x00,0x99,0x32,0xF0,0xFF,

0x4D,0x19,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0xFF,0xFF,0xFF,0xFF,0xDE,0x1F,0x00,

0x80,0x20,0xF0,0xFF,0x40,0x10,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0xFF,0xFF,0xFF,

0x34,0xB5,0x1E,0x00,0x36,0x3E,0xF1,0xFF,0x1B,0x9F,0x00,0x00,0x00,0x00,0x00,0x00,

0xFF,0xFF,0xFF,0xFF,0x08,0x8B,0x1D,0x00,0x15,0x49,0xF2,0xFF,0x8A,0x24,0x01,0x00,

0x00,0x00,0x00,0x00,0xFF,0xFF,0xFF,0xFF,0x4F,0x52,0x1B,0x00,0x49,0x19,0xF4,0xFF,

0xA5,0x0C,0x02,0x00,0x00,0x00,0x00,0x00,0xFF,0xFF,0xFF,0xFF,0xC4,0x0F,0x17,0x00,

0x30,0x16,0xF7,0xFF,0x18,0x8B,0x03,0x00,0x00,0x00,0x00,0x00,0xFF,0xFF,0xFF,0xFF,

0x75,0x97,0x0D,0x00,0xED,0x82,0xFC,0xFF,0x77,0x41,0x06,0x00,0x00,0x00,0x00,0x00,

0xFF,0xFF,0xFF,0xFF,0xAF,0x83,0xF2,0xFF,0xB0,0xED,0xFC,0xFF,0xD8,0x76,0x06,0x00,

0x00,0x00,0x00,0x00,0xFF,0xFF,0xFF,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x2B,0xBD,0x1F,0x00,

0xB3,0x42,0xF0,0xFF,0x59,0x21,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0xFF,0xFF,0xFF,

0xB0,0x99,0x1F,0x00,0x95,0x64,0xF0,0xFF,0x4A,0x32,0x00,0x00,0x00,0x00,0x00,0x00,

0xFF,0xFF,0xFF,0xFF,0x3E,0xBD,0x1F,0x00,0xBF,0x40,0xF0,0xFF,0x5F,0x20,0x00,0x00,

0x00,0x00,0x00,0x00,0xFF,0xFF,0xFF,0xFF,0x08,0x6A,0x1D,0x00,0x8D,0x65,0xF2,0xFF,

0xC7,0x32,0x01,0x00,0x00,0x00,0x00,0x00,0xFF,0xFF,0xFF,0xFF,0xF9,0x12,0x1B,0x00,

0xCA,0x49,0xF4,0xFF,0xE5,0x24,0x02,0x00,0x00,0x00,0x00,0x00,0xFF,0xFF,0xFF,0xFF,

0xFE,0x95,0x16,0x00,0xD9,0x63,0xF7,0xFF,0xED,0xB1,0x03,0x00,0x00,0x00,0x00,0x00,

0xFF,0xFF,0xFF,0xFF,0x7B,0x1B,0x0E,0x00,0x0F,0x3C,0xFC,0xFF,0x08,0x1E,0x06,0x00,

0x00,0x00,0x00,0x00,0xFF,0xFF,0xFF,0xFF,0xF6,0xB9,0xFF,0xFF,0x4A,0xF3,0x05,0x00,

0xA5,0xF9,0x0A,0x00,0x00,0x00,0x00,0x00,0xFF,0xFF,0xFF,0xFF,0x00,0x00,0x00,0x00,

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,

0x00,0x00,0x00,0x00,0x23,0x7B,0x1F,0x00,0x54,0x84,0xF0,0xFF,0x2A,0x42,0x00,0x00,

0x00,0x00,0x00,0x00,0xFF,0xFF,0xFF,0xFF,0x69,0x32,0x1F,0x00,0xC0,0xC6,0xF0,0xFF,

0x60,0x63,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0xFF,0xFF,0xFF,0x88,0x77,0x1F,0x00,

0x7C,0x80,0xF0,0xFF,0x3E,0x40,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0xFF,0xFF,0xFF,

0x7E,0xD0,0x1A,0x00,0x14,0x7C,0xF4,0xFF,0x0A,0x3E,0x02,0x00,0x00,0x00,0x00,0x00,

0xFF,0xFF,0xFF,0xFF,0xEC,0x15,0x16,0x00,0x30,0xB4,0xF7,0xFF,0x18,0xDA,0x03,0x00,

0x00,0x00,0x00,0x00,0xFF,0xFF,0xFF,0xFF,0x02,0x32,0x0D,0x00,0x57,0xB9,0xFC,0xFF,

0xAC,0x5C,0x06,0x00,0x00,0x00,0x00,0x00,0xFF,0xFF,0xFF,0xFF,0x5A,0x33,0x00,0x00,

0xA3,0x5B,0x05,0x00,0xD2,0xAD,0x0A,0x00,0x00,0x00,0x00,0x00,0xFF,0xFF,0xFF,0xFF,

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xCD,0xCD,0x1F,0x00,

0x20,0x32,0xF0,0xFF,0x10,0x19,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0xFF,0xFF,0xFF,

0x5C,0xB3,0x1F,0x00,0xAA,0x4B,0xF0,0xFF,0xD5,0x25,0x00,0x00,0x00,0x00,0x00,0x00,

0xFF,0xFF,0xFF,0xFF,0x36,0xCE,0x1F,0x00,0xA8,0x30,0xF0,0xFF,0x54,0x18,0x00,0x00,

0x00,0x00,0x00,0x00,0xFF,0xFF,0xFF,0xFF,0xB6,0x0F,0x1E,0x00,0x86,0xD4,0xF1,0xFF,

0x43,0xEA,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0xFF,0xFF,0xFF,0x90,0x4F,0x1C,0x00,

0x3D,0x51,0xF3,0xFF,0x9F,0xA8,0x01,0x00,0x00,0x00,0x00,0x00,0xFF,0xFF,0xFF,0xFF,

0xE9,0xF5,0x18,0x00,0x26,0xD2,0xF5,0xFF,0x13,0xE9,0x02,0x00,0x00,0x00,0x00,0x00,

0xFF,0xFF,0xFF,0xFF,0xAA,0x8B,0x12,0x00,0xBC,0xCC,0xF9,0xFF,0x5E,0xE6,0x04,0x00,

0x00,0x00,0x00,0x00,0xFF,0xFF,0xFF,0xFF,0x63,0x68,0x05,0x00,0x03,0x22,0x01,0x00,

0x02,0x91,0x08,0x00,0x00,0x00,0x00,0x00,0xFF,0xFF,0xFF,0xFF,0x00,0x00,0x00,0x00,

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,

0x00,0x00,0x00,0x00,0x0E,0x9C,0x1F,0x00,0xA5,0x63,0xF0,0xFF,0xD2,0x31,0x00,0x00,

0x00,0x00,0x00,0x00,0xFF,0xFF,0xFF,0xFF,0x2C,0x66,0x1F,0x00,0xF6,0x95,0xF0,0xFF,

0xFB,0x4A,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0xFF,0xFF,0xFF,0xC0,0x9A,0x1F,0x00,

0xBD,0x60,0xF0,0xFF,0x5F,0x30,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0xFF,0xFF,0xFF,

0xE5,0x1D,0x1C,0x00,0x45,0x79,0xF3,0xFF,0xA3,0xBC,0x01,0x00,0x00,0x00,0x00,0x00,

0xFF,0xFF,0xFF,0xFF,0x3C,0x96,0x18,0x00,0xD8,0x13,0xF6,0xFF,0xEC,0x09,0x03,0x00,

0x00,0x00,0x00,0x00,0xFF,0xFF,0xFF,0xFF,0x21,0xD6,0x11,0x00,0xF5,0x32,0xFA,0xFF,

0x7B,0x19,0x05,0x00,0x00,0x00,0x00,0x00,0xFF,0xFF,0xFF,0xFF,0x33,0x0A,0x06,0x00,

0x8F,0xBC,0x00,0x00,0x47,0x5E,0x08,0x00,0x00,0x00,0x00,0x00,0xFF,0xFF,0xFF,0xFF,

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xE2,0x39,0x1F,0x00,

0xEC,0xC4,0xF0,0xFF,0x76,0x62,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0xFF,0xFF,0xFF,

0x2D,0xCA,0x1E,0x00,0xA1,0x26,0xF1,0xFF,0x50,0x93,0x00,0x00,0x00,0x00,0x00,0x00,

0xFF,0xFF,0xFF,0xFF,0xEE,0x2E,0x1F,0x00,0x3F,0xBF,0xF0,0xFF,0xA0,0x5F,0x00,0x00,

0x00,0x00,0x00,0x00,0xFF,0xFF,0xFF,0xFF,0xCE,0x31,0x18,0x00,0xBE,0x57,0xF6,0xFF,

0xDF,0x2B,0x03,0x00,0x00,0x00,0x00,0x00,0xFF,0xFF,0xFF,0xFF,0xF0,0x17,0x11,0x00,

0xB1,0x9C,0xFA,0xFF,0x58,0x4E,0x05,0x00,0x00,0x00,0x00,0x00,0xFF,0xFF,0xFF,0xFF,

0x99,0xEE,0x04,0x00,0xA6,0x70,0x01,0x00,0x53,0xB8,0x08,0x00,0x00,0x00,0x00,0x00,

0xFF,0xFF,0xFF,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,

0x00,0x00,0x00,0x00,0xB0,0x8E,0x00,0x00,

};
#else
static eq_dbg_online_t __eq_dbg_online;

#define eq_dbg_online  (&__eq_dbg_online)
#endif // USE_EQ_DBG_MALLOC

static u8 eq_switch_state = 0;
static u8 eq_switch_type = 0xff;

int user_eq_seg_gain[6][10] =
{
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, ///<Normal
	{ 0, 8, 8, 4, 0, 0, 0, 0, 2, 2}, ///<Rock
	{-2, 0, 2, 4,-2,-2, 0, 0, 4, 4}, ///<Pop
	{ 4, 2, 0,-3,-6,-6,-3, 0, 3, 5}, ///<Classic
	{ 0, 0, 0, 4, 4, 4, 0, 2, 3, 4}, ///<Jazz
	{-2, 0, 0, 2, 2, 0, 0, 0, 4, 4}, ///<Country
};

int user_eq_global_gain[6] =
{
	0,-6,-3,-6,-6,-3
};


void eq_init(void)
{

	soft_eq_init(USE_SOFTWARE_EQ);

    eq_init_api(3);

#if EQ_UART_BDG
    EQ_uart_init();
#endif // EQ_UART_BDG

}
void eq_set(void)
{
static count = 0;
	memset(eq_dbg_online, count++, sizeof(eq_dbg_online_t));
	//memcpy(eq_dbg_online, &__eq_dbg_online, sizeof(eq_dbg_online_t));
	printf("eq type, %d, eq count, %d\r\n", eq_dbg_online->eq_type, eq_dbg_online->eq_cnt);
	eq_config_api( eq_dbg_online->eq_filt_0 ,
							eq_dbg_online->eq_filt_1 ,
							eq_dbg_online->eq_filt_2 ,
							eq_dbg_online->eq_filt_3 ,
							eq_dbg_online->eq_filt_4 ,
							eq_dbg_online->eq_filt_5 ,
							eq_dbg_online->eq_filt_6 ,
							eq_dbg_online->eq_filt_7 ,
							eq_dbg_online->eq_filt_8 ,
							(int (*)[10])eq_dbg_online->eq_freq_gain ,
							eq_dbg_online->eq_gain ,
							 !USE_SOFTWARE_EQ);
	 soft_eq_set_segment_num(eq_dbg_online->eq_cnt);
	 eq_mode_sw(eq_dbg_online->eq_type );

}
#if USE_SOFTWARE_EQ
#define EQ_CFG_FILE            "cfg_eq.bin"
#else
#define EQ_CFG_FILE            "eq_cfg.bin"
#endif
void eq_enable(void)
{
    tbool ret;
	
	if(1 == eq_switch_state)
	{
		return;
	}
	eq_switch_state = 1;

#if USE_EQ_DBG_MALLOC
    eq_dbg_online = (eq_dbg_online_t *)eq_malloc(sizeof(eq_dbg_online_t));
    if(eq_dbg_online == NULL)
    {
        puts("eq_dbg malloc error\n");
    }
    memset(eq_dbg_online , 0x0 , sizeof(eq_dbg_online_t));
#endif // USE_EQ_DBG_MALLOC

    ret = read_cfg_file((u8*)eq_dbg_online,(u8 *)EQ_CFG_FILE,sizeof(eq_dbg_online_t));

    //read eq config file ok then update the config
    if(ret==0)
    {
        puts("default EQ config\n");
        //memcpy(eq_dbg_online->eq_gain , user_eq_global_gain , sizeof(user_eq_global_gain));
        //memcpy(eq_dbg_online->eq_freq_gain , user_eq_seg_gain , sizeof(user_eq_seg_gain));
		memcpy(eq_dbg_online, &__eq_dbg_online, sizeof(eq_dbg_online_t));
		printf("eq type, %d\r\n", eq_dbg_online->eq_type);
        eq_config_api( eq_dbg_online->eq_filt_0 ,
                                eq_dbg_online->eq_filt_1 ,
                                eq_dbg_online->eq_filt_2 ,
                                eq_dbg_online->eq_filt_3 ,
                                eq_dbg_online->eq_filt_4 ,
                                eq_dbg_online->eq_filt_5 ,
                                eq_dbg_online->eq_filt_6 ,
                                eq_dbg_online->eq_filt_7 ,
                                eq_dbg_online->eq_filt_8 ,
                                (int (*)[10])eq_dbg_online->eq_freq_gain ,
                                eq_dbg_online->eq_gain ,
                              	 !USE_SOFTWARE_EQ);
		 soft_eq_set_segment_num(eq_dbg_online->eq_cnt);
         eq_mode_sw(eq_dbg_online->eq_type );
    }
	else
	{
        printf("EQ config file,eq_type:%d\n",eq_dbg_online->eq_type);
        eq_config_api( eq_dbg_online->eq_filt_0 ,
                       eq_dbg_online->eq_filt_1 ,
                       eq_dbg_online->eq_filt_2 ,
                       eq_dbg_online->eq_filt_3 ,
                       eq_dbg_online->eq_filt_4 ,
                       eq_dbg_online->eq_filt_5 ,
                       eq_dbg_online->eq_filt_6 ,
                       eq_dbg_online->eq_filt_7 ,
                       eq_dbg_online->eq_filt_8 ,
                       (int (*)[10])eq_dbg_online->eq_freq_gain ,
                       eq_dbg_online->eq_gain ,
                       !USE_SOFTWARE_EQ);
		 soft_eq_set_segment_num(eq_dbg_online->eq_cnt);
        eq_mode_sw(eq_dbg_online->eq_type );
    }


}

void eq_disable(void)
{
    
	if(0 == eq_switch_state)
	{
		return;
	}
	puts("eq_disable\n");
	eq_dis_api();

#if USE_EQ_DBG_MALLOC
    if(eq_dbg_online != NULL)
    {
        puts("eq_dbg_online free\n");
        eq_free(eq_dbg_online);
        eq_dbg_online = NULL;
    }
#endif // USE_EQ_DBG_MALLOC
	
	eq_switch_state = 0;
}

void eq_run(short *in,short *out,int npoint)
{
	eq_run_api(in,out,npoint);
}

void eq_mode_sw(int mode)
{
	if(0 == eq_switch_state)
	{
		return;		
	}
	return;
	puts("eq_mode_sw\n");
	eq_mode_api(mode);
}

void eq_samplerate_sw(u16 sr)
{
	eq_samplerate_api(sr);
}


/*----------------------------------------------------------------------------*/
/**@brief  update eq info online
   @param  ef_info_addr
   @param  size
   @param  cnt
   @return 1:receive data ok; 0:receive data err
   @note
*/
/*----------------------------------------------------------------------------*/
u8 update_ef_info(void *ef_info_addr,u16 size,u8 cnt)
{
    eq_printf("update_ef_info,size=%d,cnt=%d\n",size,cnt);

    if(eq_dbg_online == NULL)
        return 0;

    if(!cnt)
       my_memcpy((u8*)eq_dbg_online,ef_info_addr,size);
    else
       my_memcpy(((u8*)eq_dbg_online)+(512-4)*cnt,ef_info_addr,size);

    if(cnt == 4)
    {
        if(eq_dbg_online->crc16 == CRC16(eq_dbg_online,sizeof(eq_dbg_online_t)-4))
        {
            puts("eq_info_crc_OK\n");
            eq_config_api( eq_dbg_online->eq_filt_0 ,
                           eq_dbg_online->eq_filt_1 ,
                           eq_dbg_online->eq_filt_2 ,
                           eq_dbg_online->eq_filt_3 ,
                           eq_dbg_online->eq_filt_4 ,
                           eq_dbg_online->eq_filt_5 ,
                           eq_dbg_online->eq_filt_6 ,
                           eq_dbg_online->eq_filt_7 ,
                           eq_dbg_online->eq_filt_8 ,
                           (int (*)[10])eq_dbg_online->eq_freq_gain ,
                           eq_dbg_online->eq_gain ,
                           0);
		 	soft_eq_set_segment_num(eq_dbg_online->eq_cnt);
            eq_mode_sw(eq_dbg_online->eq_type);
            return 1;
        }
        else
        {
            puts("\neq_info_crc_ERR!!!!\n\n");
            return 0;
        }
    }
    return 0;
}

/*----------------------------------------------------------------------------*/
/**@brief  配置文件读取函数
   @param  buff 存放配置文件的buff
           cfg_file_num 配置文件号
           cfg_len 配置文件的总长度
   @return ture配置文件读取成功  false配置文件读取失败
   @note   bool read_cfg_file(u8 *buff,u8 cfg_file_num,u16 cfg_len)
*/
/*----------------------------------------------------------------------------*/

extern lg_dev_list * lg_dev_find(u32 drv);
extern tbool syd_drive_open(void **p_fs_hdl,void *p_hdev,u32 drive_base);
extern tbool syd_drive_close(void **p_fs_hdl);
extern bool syd_get_file_byindex(void *p_fs_hdl, void **p_f_hdl, u32 file_number, char *lfn);
extern bool syd_file_close(void *p_fs_hdl, void **p_f_hdl);
extern u16 syd_read(void *p_f_hdl ,u8 _xdata *buff , u16 len);
extern bool syd_get_file_bypath(void *p_fs_hdl,void **p_f_hdl,u8 *path,char*lfn);

bool read_cfg_file(u8 *buff,u8* cfg_file_name,u16 cfg_len)
{
    lg_dev_list * pnode;
    void *fs_hdl = NULL;  //文件系统句柄
    void *file_hdl = NULL;//文件句柄
    eq_dbg_online_t *tmp_eq_dbg_buff;

    pnode = lg_dev_find('A');

    if(!syd_drive_open(&fs_hdl,pnode->cur_dev.lg_hdl->phydev_item,0))//打开文件系统
    {
        eq_puts("syd_drive_open err!\n");
        return FALSE;
    }

    if(!syd_get_file_bypath(fs_hdl ,&file_hdl, cfg_file_name,0))
    {
        eq_puts("syd_get_file_byindex err!\n");
        //以下两部顺序不能变
        syd_file_close(fs_hdl,&file_hdl);//失败的情况下关闭文件
        syd_drive_close(&fs_hdl);//失败的情况下关闭文件系统
        return FALSE;
    }

    syd_read(file_hdl,buff,cfg_len);//读取文件
    tmp_eq_dbg_buff = (eq_dbg_online_t*)buff;
    if(tmp_eq_dbg_buff->crc16 == CRC16((u8*)buff,cfg_len-4))
    {
        eq_puts("eq_cfg_file_crc_succ\n");
        //以下两部顺序不能变
        syd_file_close(fs_hdl,&file_hdl);//完成操作后，关闭文件
        syd_drive_close(&fs_hdl);  //完成操作后，关闭文件系统
        return true;
    }
    else
    {
        eq_puts("eq_cfg_file_crc_err\n");
        //以下两部顺序不能变
        syd_file_close(fs_hdl,&file_hdl);//完成操作后，关闭文件
        syd_drive_close(&fs_hdl);  //完成操作后，关闭文件系统
        return false;
    }
}

u8 get_eq_switch_state(void)
{
	return eq_switch_state;
}

u8 get_eq_default_mode(void)
{
	if(eq_dbg_online == NULL)
	{
		return 0;
	}
	else
	{
		return (u8)eq_dbg_online->eq_type; 
	}
}


void update_eq_table_data(s8 *eq_table,u16 offset,u16 eq_size,s8 *eq_global_gain)
{
   u16 cnt;
   int *eq_gain_p; 

	if(eq_dbg_online == NULL)
	{
		puts("eq not runing!!!\n");
		return;
	}

   if(eq_table != NULL)
   {	   
   		eq_gain_p = (int*)eq_dbg_online->eq_freq_gain;
   		eq_gain_p += offset;
   		for(cnt = 0; cnt < eq_size;cnt++)
   		{
   			eq_gain_p[cnt] = (int)eq_table[cnt];
   		}
   		memcpy(user_eq_seg_gain,eq_dbg_online->eq_freq_gain,sizeof(user_eq_seg_gain));
   }

   if(eq_global_gain != NULL)
   {	   
   		eq_gain_p  = eq_dbg_online->eq_gain;
   		for(cnt = 0; cnt < 6;cnt++)
   		{
   			eq_gain_p[cnt] = (int)eq_global_gain[cnt];
   		}
        memcpy(user_eq_global_gain, eq_dbg_online->eq_gain, sizeof(user_eq_global_gain));
   }
   
   /* puts("---update_eq---:"); */
   /* put_buf(eq_table,eq_size); */
   /* put_buf(eq_global_gain,6); */

}


void set_sys_eq(u8 type)
{
	if((0 == eq_switch_state)||(eq_switch_type == type))
	{
		return;
	}

	puts("set_sys_eq\n");

	if(type)
	{
		eq_mode_sw(eq_dbg_online->eq_type );
	}
	else
	{
		eq_mode_sw(0);
	}
	eq_switch_type = type;
}


#endif
