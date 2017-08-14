#include "bwave_ctrl.h"

void bwave_ctrl_create()
{
	led_driver_create(&virtualLeds);
	led_driver_turn_all_off();
	led_driver_turn_on(STANDBYLED_BIT);
}

void bwave_ctrl_turn_on()
{
	led_driver_turn_all_off();
	led_driver_turn_on(POWERLED_BIT);
}

void bwave_ctrl_turn_off()
{
	led_driver_turn_all_off();
	led_driver_turn_on(STANDBYLED_BIT);
}
