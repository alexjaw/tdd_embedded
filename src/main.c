#include "main.h"
#include "system.h"
#include "bwave_ctrl.h"

void init()
{
	bwave_ctrl_create();
}

#ifndef TEST
void main(void)
{
	init();

	while(1)
	{}
}
#endif
