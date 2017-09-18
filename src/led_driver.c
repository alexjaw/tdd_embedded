#include "led_driver.h"
#include <stdint.h>
#ifndef TEST
    #include <avr/io.h>
#else
    #include "testable_registers.h"
#endif
#include "io_map.h"

void led_init(void)
{
    LED_DIR     |= LEDMASK;
    LEDPIN_CTRL |= PORT_INVEN_bm;
    LED_OUT      = 0x00;
}

void led_on(void)
{
    LED_OUT |= LEDMASK;
}

void led_off(void)
{
    LED_OUT &= ~LEDMASK;
}

