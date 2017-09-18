/*
 * tdd_embedded.c
 *
 * Created: 2017-09-18 08:43:35
 *  Author: alexander
 */ 


#include <avr/io.h>
#include "util/delay.h"
#include "io_map.h"
#include "led_driver.h"

#define DELAY_MS 100

int main(void)
{
    led_init();
    
    while(1)
    {
        led_on();
        _delay_ms(DELAY_MS);
        led_off();
        _delay_ms(DELAY_MS);
    }
}
