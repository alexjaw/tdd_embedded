#include "unity.h"
#define EXTERN
#include "testable_registers.h"
#include "io_map.h"
#include "led_driver.h"

void setUp(void)
{
    led_init();
}

void tearDown(void)
{
}

void test_led_init(void)
{
    LED_OUT = 0xff;
    led_init();
    TEST_ASSERT_EQUAL_HEX8(0x00, LED_OUT);
}

void test_led_on(void)
{
    led_on();
    TEST_ASSERT_EQUAL_HEX8(LEDMASK, LED_OUT);
}

void test_led_off(void)
{
    led_off();
    TEST_ASSERT_EQUAL_HEX8(0x00, LED_OUT);
}

