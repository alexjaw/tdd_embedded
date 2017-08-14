#ifndef _BWAVE_CTRL_H
#define _BWAVE_CTRL_H
#ifndef _IO_MAPPING_H
#include "io_mapping.h"
#endif  // _IO_MAPPING_H
#include "led_driver.h"

void bwave_ctrl_create(void);
void bwave_ctrl_turn_on(void);
void bwave_ctrl_turn_off(void);

#endif // _BWAVE_CTRL_H
