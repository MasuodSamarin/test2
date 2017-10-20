#ifndef _LED_H_
#define _LED_H_

#include "includes.h"
#include "sys_detect.h"
#include "sdk_cfg.h"

#if HSC_BT08
#define LED_BIT           BIT(4) ///PC4
#define LED_INIT_EN()     {JL_PORTC->PU &= ~LED_BIT;JL_PORTC->PD &= ~LED_BIT;JL_PORTC->DIR &= ~LED_BIT;}
#define LED_INIT_DIS()    {JL_PORTC->PU &= ~LED_BIT;JL_PORTC->PD &= ~LED_BIT;JL_PORTC->DIR |= LED_BIT;}
#define B_LED_ON()        JL_PORTC->OUT |= LED_BIT;
#define B_LED_OFF()       JL_PORTC->OUT &= ~LED_BIT;
#define R_LED_ON(...)
#define R_LED_OFF(...)
#else
#define LED_BIT           BIT(6) ///PB11
#define LED_INIT_EN()     {JL_PORTB->PU &= ~LED_BIT;JL_PORTB->PD &= ~LED_BIT;JL_PORTB->DIR &= ~LED_BIT;}
#define LED_INIT_DIS()    {JL_PORTB->PU &= ~LED_BIT;JL_PORTB->PD &= ~LED_BIT;JL_PORTB->DIR |= LED_BIT;}
#define B_LED_ON()        JL_PORTB->OUT |= LED_BIT;
#define B_LED_OFF()       JL_PORTB->OUT &= ~LED_BIT;
#define R_LED_ON(...)
#define R_LED_OFF(...)
#endif

extern u32 g_led_fre;

void led_init(void);
void led_close(void);
void led_open(void);
void led_fre_set(u32 fre,u8 led_flash);
void led_scan(void *param);

#endif/*_LED_H_*/

