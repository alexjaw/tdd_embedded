#include "led_driver.h"

static uint8_t * ledsAddress;
enum {ALL_LEDS_ON = ~0, ALL_LEDS_OFF = ~ALL_LEDS_ON};

void led_driver_create(uint8_t * address)
{
	ledsAddress = address;
	*ledsAddress = 0b00000000;
}

void led_driver_destroy()
{}

void led_driver_turn_on(uint8_t led)
{
	*ledsAddress |= (1 << led);
}

void led_driver_turn_off(uint8_t led)
{
	*ledsAddress &= ~(1 << led);
}

void led_driver_turn_all_off()
{
	*ledsAddress = ALL_LEDS_OFF;
}

void led_driver_turn_all_on()
{
    *ledsAddress = ALL_LEDS_ON;
}
