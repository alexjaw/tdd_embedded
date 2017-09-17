# tdd_embedded
An example for how to arrange registers for targets and for tests. It follows closely the suggestions provided by 
[Mark Vandervoord](http://vandervoord.net/blog/2015/5/24/unit-test-how-registers). The setup is important in order to test
code on the host. However, the setup must be done with care in order to prevent link errors (multiple declarations) later
in the project. Each test file defines EXTERN which is used to prevent link errors. The project yml-file defines TEST.

Tests are done using [Ceedling](http://www.throwtheswitch.org/ceedling)

Initially, there is only one source file, led_driver.c, and corresponding header, led_driver.h. led_driver is used to turn an
LED on and off.

The project is setup to use [ATxmega32E5](http://www.microchip.com/wwwproducts/en/ATXMEGA32E5) as micro.

The project is using two versions of the micro header. The original avr/io.h is used for target builds, and 
testable_registers.h in test/support is used for tests. There is a third header, src/io_map.h, that define
names specific for the project.

In many cases, an embedded project will have at least three build targets. A test target for the host, a hw target for the
product in development, and a third hw target that often is a dev board provided by the chip manufacturer. In our case,
there would be two different io_map.h, one for the product board (io_map_product.h), and another for the devboard (for
example io_map_xplained.h, [XMEGA-E5 Xplained](http://www.atmel.com/tools/XMEGA-E5XPLAINED.aspx)). The build system should
set the correct io_map_<target>.h file so that the individual source files only need to include io_map.h.

testable_registers.h defines the necessary registers in the computer RAM. Example: io.h defines PORTD_DIR and PORTD_OUT
for control of pin direction and pin level. testable_registers.h uses EXACTLY the same names and define these as uint8_t
variables. testable_registers.h also define constants such as PORT_INVEN_bm, however these are defined using #define in order
to set these to specific values. These values are the same for all projects using the specific micro. 

Project resources, such as an LED, is defined in io_map.h. Here PORTD_OUT is given the more specific name LED_OUT. The reason
is that we can reuse testable_registers.h for other projects using the same micro. At the same time, io_map.h, isolates our
project from the specifics of the target micro. An alternative is to put the definitions in led_driver.c. However, then some 
other mechanism must be provided for tests to check if the registers are manipulated as expected. With the present solution, 
test_led_driver.h can include io_map.h and thereby have access to the registers that are manipulated by led_driver.c (see 
test_led_driver.c). Another alternative is to inject led_driver with a data structure containing LED_DIR, LED_OUT, etc...
The data structure should be defined in led_driver.h.

Initialization of the pin is performed in led_driver.c (led_init()). It involves setting direction, logic level, and initial
value (on/off).

## Project Structure
* Source files are in src/
* Test files are in test/, testable_registers.h are in test/support
* Ceedling files are in vendor/
