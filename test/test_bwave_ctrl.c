#include "unity.h"
#include "io_mapping.h"
#include "bwave_ctrl.h"
#include "led_driver.h"

void setUp(void)
{
	bwave_ctrl_create();
}

void tearDown(void)
{
}

void test_bwave_ctrl_LedsStandbyAfterCreate(void)
{
    TEST_ASSERT_EQUAL_HEX8((1<<STANDBYLED_BIT), virtualLeds);
}

void test_bwave_ctrl_LedsOnAfterTurnOn(void)
{
	bwave_ctrl_turn_off();
	bwave_ctrl_turn_on();
	TEST_ASSERT_EQUAL_HEX8((1<<POWERLED_BIT), virtualLeds);
}

void test_bwave_ctrl_LedsStandbyAfterTurnOff(void)
{
	bwave_ctrl_turn_on();
	bwave_ctrl_turn_off();
	TEST_ASSERT_EQUAL_HEX8((1<<STANDBYLED_BIT), virtualLeds);
}
