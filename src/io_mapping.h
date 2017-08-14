// io_mapping.h
#ifndef _IO_MAPPING_H
#define _IO_MAPPING_H
#include <stdint.h>

#if COMPILING_FOR_XPLAINED
#include "io_mapping_xplained.h"
#elif COMPILING_FOR_BWAVE
#include "io_mapping_bwave.h"
#elif TEST
#include "io_mapping_test.h"
#else
#error "No I/O map selected for the board. What is your target?"
#endif  // COMPILING_FOR...
#endif  // _IO_MAPPING_H
