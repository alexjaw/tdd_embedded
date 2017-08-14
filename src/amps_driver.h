/*
 * amp_driver is supposed to control one amp
 */
#ifndef _AMPS_DRIVER_H
#define _AMPS_DRIVER_H
#ifndef __STDINT_H_
#include <stdint.h>
#endif
#ifndef _IO_MAPPING_H
#include "io_mapping.h"
#endif

void amp_driver_create(uint8_t *, uint8_t *, uint8_t *);
void amp_driver_turn_all_on(void);
void amp_driver_turn_all_off(void);
#endif // _AMPS_DRIVER_H
