#define STANDBYLED_BIT 0
#define POWERLED_BIT 4
uint8_t virtualLeds;
uint8_t virtualBtns;

// 700W Total of 5 bits for both amps: [PA2, PD2, PD3, PD4, PD5]
// amps amplifier
#define STANDBYAMP1_BIT 2  //PD2
#define STANDBYAMP2_BIT 3  //PD3
#define ENABLEAMPS_BIT 2  //PA2
#define THERMALAMPS_BIT 5  //PD5
#define CLIPAMPS_BIT 4  //PD4

uint8_t virtualAmp1Stdby;
uint8_t virtualAmp2Stdby;
uint8_t virtualAmpsEnable;

/*
typedef struct AMPs_struct
{
    volatile uint8_t stdby_amp1;  //Address for stdby mode amp 1
    volatile uint8_t stdby_amp2;  //Address for stdby mode amp 2
    volatile uint8_t enable_amps;  //Amplifier 1 and 2 enable
} AMPs_t;

AMPs_t amps = {(1 << STANDBYAMP1_BIT),(1 << STANDBYAMP2_BIT), (1 << ENABLEAMPS_BIT)};
*/
/*
typedef enum
{
	stdby_amp1_reg = 0x0,
	stdby_amp2_reg = 0x0,
	enable_amps_reg = 0x0
} Amps_regs;

typedef enum
{
	stdby_amp1 = (1 << STANDBYAMP1_BIT),
	stdby_amp2 = (1 << STANDBYAMP2_BIT),
	enable_amps = (1 << ENABLEAMPS_BIT)
} Amps_cmds;
*/
