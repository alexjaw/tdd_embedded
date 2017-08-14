#include "unity.h"
#include "io_mapping.h"
#include "led_driver.h"

void setUp(void)
{
    led_driver_create(&virtualLeds);
}

void tearDown(void)
{
}

void test_led_driver_LedsOffAfterCreate(void)
{
    virtualLeds = 0xff;
    led_driver_create(&virtualLeds);
    TEST_ASSERT_EQUAL_HEX8(0, virtualLeds);
}

void test_led_driver_TurnOnLedOne(void)
{
	int ledBit = 0;
    led_driver_turn_on(ledBit);
    TEST_ASSERT_EQUAL_HEX8((1<<ledBit), virtualLeds);
}

void test_led_driver_TurnOnLedBitFour(void)
{
	int ledBit = 4;
    led_driver_turn_on(ledBit);
    TEST_ASSERT_EQUAL_HEX8((1<<(ledBit)), virtualLeds);
}

void test_led_driver_TurnOnMultipleLeds(void)
{
	led_driver_turn_on(0);
    led_driver_turn_on(3);
    TEST_ASSERT_EQUAL_HEX8(9, virtualLeds);
}

void test_led_driver_TurnOffAll(void)
{
	led_driver_turn_on(0);
	led_driver_turn_on(3);
	led_driver_turn_all_off();
	TEST_ASSERT_EQUAL_HEX8(0, virtualLeds);
}

void test_led_driver_TurnAllOn(void)
{
	led_driver_turn_on(0);
	led_driver_turn_on(3);
	led_driver_turn_all_on();
	TEST_ASSERT_EQUAL_HEX8(0xff, virtualLeds);
}

void test_led_driver_TurnOffLedOne(void)
{
	led_driver_turn_all_on();
	led_driver_turn_off(0);
	TEST_ASSERT_EQUAL_HEX8(0xfe, virtualLeds);
}

