/*micro definitions used for test
 for rationale, see http://vandervoord.net/blog/2015/5/24/unit-test-how-registers
*/
#ifdef TEST
    #ifndef EXTERN
        #define EXTERN extern
    #endif
#endif

/*If defined as variable, then must handle multiple includes. Once for the
test and once for the file to be tested*/
#define PORT_INVEN_bm 0x40

EXTERN volatile uint8_t PORTD_DIR;
EXTERN volatile uint8_t PORTD_OUT;
EXTERN volatile uint8_t PORTD_PIN4CTRL;

