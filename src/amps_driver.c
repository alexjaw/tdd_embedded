/*
 * In a driver we should have:
 * - hardware setup...but what if we are unit testing...ifndef?
 * Or the setup could be called from main() only, which normally
 * is not tested with unit tests.
 */
#include "amps_driver.h"

static uint8_t * addrAmp1Stdby;
static uint8_t * addrAmp2Stdby;
static uint8_t * addrAmpsEnable;

static void standby()
{
	*addrAmp1Stdby = (1 << STANDBYAMP1_BIT);
	*addrAmp2Stdby = (1 << STANDBYAMP2_BIT);
	*addrAmpsEnable = 0x0;
}

void amp_driver_create(uint8_t * addr1, uint8_t * addr2, uint8_t * addr3)
{

	addrAmp1Stdby = addr1;
	addrAmp2Stdby = addr2;
	addrAmpsEnable = addr3;
	standby();
}

void amp_driver_turn_all_on(void)
{
	*addrAmp1Stdby = 0x0;
	*addrAmp2Stdby = 0x0;
	*addrAmpsEnable = (1 << ENABLEAMPS_BIT);
}

void amp_driver_turn_all_off(void)
{
	amp_driver_turn_all_on();
	standby();
}

