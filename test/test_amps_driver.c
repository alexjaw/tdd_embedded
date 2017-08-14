/* Tests for the amps driver
 * - Test that init is setting amp in the correct condition
 * - IsOverCurrentError
 * - IsThermalError
 * - IsEnableOn
 * - Standby on
 * - Standby off
 * - IsStandbyOn is not possible since its only an input?
 * - Enable on
 * - Enable off
 *
 * */
#include "unity.h"
#include "io_mapping.h"
#include "amps_driver.h"

void setUp(void)
{
	amp_driver_create(&virtualAmp1Stdby, &virtualAmp2Stdby, &virtualAmpsEnable);
}

void tearDown(void)
{
}

void test_amp_driver_CorrectInit(void)
{
	virtualAmp1Stdby = 0xff;
	virtualAmp2Stdby = 0xff;
	virtualAmpsEnable = 0xff;
	amp_driver_create(&virtualAmp1Stdby, &virtualAmp2Stdby, &virtualAmpsEnable);
	TEST_ASSERT_EQUAL_HEX8((1<<STANDBYAMP1_BIT), virtualAmp1Stdby);
	TEST_ASSERT_EQUAL_HEX8((1<<STANDBYAMP2_BIT), virtualAmp2Stdby);
	TEST_ASSERT_EQUAL_HEX8(0x0, virtualAmpsEnable);
}

void test_amp_driver_TurnOnAll(void)
{
	amp_driver_turn_all_on();
	TEST_ASSERT_EQUAL_HEX8(0x0, virtualAmp1Stdby);
	TEST_ASSERT_EQUAL_HEX8(0x0, virtualAmp2Stdby);
	TEST_ASSERT_EQUAL_HEX8((1<<ENABLEAMPS_BIT), virtualAmpsEnable);
}

void test_amp_driver_TurnOffAll(void)
{
	amp_driver_turn_all_off();
	TEST_ASSERT_EQUAL_HEX8((1<<STANDBYAMP1_BIT), virtualAmp1Stdby);
	TEST_ASSERT_EQUAL_HEX8((1<<STANDBYAMP2_BIT), virtualAmp2Stdby);
	TEST_ASSERT_EQUAL_HEX8(0x0, virtualAmpsEnable);
}

void test_amp_driver_TurnOnAllWhenTimerNotReady(void)
{TEST_ASSERT_EQUAL(1,0);}

void test_amp_driver_TurnOnAllWhenOCError(void)
{TEST_ASSERT_EQUAL(1,0);}

void test_amp_driver_TurnOnAllWhenThermalError(void)
{TEST_ASSERT_EQUAL(1,0);}
