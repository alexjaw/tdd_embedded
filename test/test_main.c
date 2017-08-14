#include "unity.h"
#include "main.h"
#include "bwave_ctrl.h"
#include "led_driver.h"
#include "system.h"

void setUp(void)
{
	init();
}

void tearDown(void)
{
}

void test_main_init(void)
{
	TEST_ASSERT_EQUAL_HEX8(1<<(STANDBYLED-1), virtualLeds);
}
