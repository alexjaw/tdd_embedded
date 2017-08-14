#ifndef _LED_DRIVER_H
#define _LED_DRIVER_H
#ifndef __STDINT_H_
#include <stdint.h>
#endif

void led_driver_create(uint8_t *);
void led_driver_destroy();
void led_driver_turn_on(uint8_t ledBit);
void led_driver_turn_off(uint8_t ledBit);
void led_driver_turn_all_off(void);
void led_driver_turn_all_on(void);

#endif // _LED_DRIVER_H
