/*RTk.GPIO Device Side
Based for a STM32F030 Micronctoller on MBED
Ported from David Whale's code for arduino which can be viewed at
https://github.com/whaleygeek/anyio

The limitations mentioned shouldn't be as bad due to how fast the MCU can run

*/

//Setup MBED and USB

#include "mbed.h"
#include <stdio.h>
#include <stdlib.h>
#include "SoftPWM.h"
#include "math.h"

Serial serialPort(SERIAL_TX, SERIAL_RX);

//AnyIO requests the version if V is sent
#define VERSION_STR "RTKGPIO V0.1.4"
//Serial baud rate
#define BAUD_RATE 230400


//Min pin is 2, Max is 27
#define MIN_PIN 0
#define MAX_PIN 27



// Errors are sent back via the 'E' Response.

enum
{
    ERROR_BAD_PIN_RANGE = 1,
    ERROR_UNKNOWN_COMMAND = 2
};

//Local function prototypes

static void command(char cmdch, char paramch);
static void gpio(char pinch, char cmdch);
static void agpio(char pinch, char cmdch);
static void error(int code);
//static void SystemClock_Config(void);

static int ioPin;
static int p;

//DigitalInOut
//If we add GPIO 0 & 1
DigitalInOut IO0(GPIO2);
DigitalInOut IO1(GPIO1);
DigitalInOut IO2(GPIO2);
DigitalInOut IO3(GPIO3);
DigitalInOut IO4(GPIO4);
DigitalInOut IO5(GPIO5);
DigitalInOut IO6(GPIO6); //Commented out for debugging
DigitalInOut IO7(GPIO7);
DigitalInOut IO8(GPIO8);
DigitalInOut IO9(GPIO9);
DigitalInOut IO10(GPIO10);
DigitalInOut IO11(GPIO11);
DigitalInOut IO12(GPIO12);
DigitalInOut IO13(GPIO13); //Commented out for debugging
DigitalInOut IO14(GPIO14);
DigitalInOut IO15(GPIO15);
DigitalInOut IO16(GPIO16);
DigitalInOut IO17(GPIO17);
DigitalInOut IO18(GPIO18);
DigitalInOut IO19(GPIO19);
DigitalInOut IO20(GPIO20);
DigitalInOut IO21(GPIO21);
DigitalInOut IO22(GPIO22);
DigitalInOut IO23(GPIO23);
DigitalInOut IO24(GPIO24);
DigitalInOut IO25(GPIO25);
DigitalInOut IO26(GPIO26);
DigitalInOut IO27(GPIO27);
//Development Lines for DIO
//DigitalInOut IO6(NC);
//DigitalInOut IO13(NC);
//DigitalInOut GIO11(NC);

//And the same for SoftPWM
//SoftPWM PIO23(GPIO23);

AnalogIn AIO11(GPIO11);
//PwmOut PIO22(GPIO22);

//I2C
DigitalInOut gpios[] = {IO0,IO1,IO2,IO3,IO4,IO5,IO6,IO7,IO8,IO9,IO10,IO11,IO12,IO13,IO14,IO15,IO16,IO17,IO18,IO19,IO20,IO21,IO22, IO23, IO24,IO25,IO26,IO27};
AnalogIn agpios[] = {AIO11};


//DigitalInOut gpios[] = {IO4,IO5,IO6,IO7,IO8,IO9,IO10,IO11,IO12,IO13,IO14,IO15,IO16,IO17,IO18,IO19,IO20,IO21,IO22, IO23, IO24,IO25,IO26,IO27};

//I2C i2c(GPIO2,GPIO3);
//Debug





int main() {
    //SystemClock_Config
    //Arduino equiv for setup



    //All setup as digital in.

    //Setup serial
    serialPort.baud(BAUD_RATE);
    //Now the loop
    serialPort.printf("RTk.GPIO Is ready");
    //SetSysClock(48000000);

    //HAL_RCC_OscConfig();
    //HAL_RCC_GetClockConfig
    serialPort.printf("SystemCoreClock = %d Hz\n",SystemCoreClock);
    //PIO23.write(0.5f);
    //PIO23.period_ms(10);


    while(1) {
        //serialPort.printf("Tick\n\r");

        if(serialPort.readable() == 1) {
            //If serial available
            char pinch = (char) serialPort.getc();

            if(pinch != '\r' && pinch != '\n')
            {
                if(pinch >= 'A' && pinch <= 'Z') {
                    //Upper case so its a global command
                    char paramch = (char) serialPort.getc();
                    command(pinch, paramch);
                }
                else if (pinch >= 'a' && pinch <= '|')
                {
                    //Lower case so its a pin number for the gpio module
                    char cmdch = (char) serialPort.getc();
                    gpio(pinch, cmdch);
                }
                else
                {
                    //Reject
                    error(ERROR_UNKNOWN_COMMAND);
                }
            }
        }

    }
//Main end
}

//Error function
//Should always be E + Number with newline
static void error(int code)
{
    serialPort.putc('E');
    serialPort.putc('1');
    serialPort.putc('\r');
    serialPort.putc('\n');
}

/*--------------------------------------------------------------------*/
/* Process a command.
 *
 * A command is a single character that identifies the command,
 * followed by parameters. In most cases parameters are a single
 * character, but there is no need for them to be. Each command knows
 * how to detect the end of it's parameter string, be that length
 * or magic character based.
 */

static void command(char cmdch, char paramch)
{
    switch(cmdch)
    {
    case 'V': // Version
        serialPort.printf(VERSION_STR);
    break;

    case 'G': //GPIO
    {
        while (serialPort.readable() == 0)
        {
            /* Wait for stuff to arrive*/

        }
        char pinch = paramch;
        char cmdch = (char)serialPort.getc();
        gpio(pinch, cmdch);
    }


    default:
        //Reject all other commands
        serialPort.putc(cmdch);
        error(ERROR_UNKNOWN_COMMAND);
        break;
    }
}

/*--------------------------------------------------------------------*/
/* Process a GPIO command.
 *
 * GPIO Commands are two characters.
 * <pinch> <cmdch>
 *
 * pinch is the pin character (a..z) where 'a' represents pin 0.
 * cmdch is the command to perform on that pin:
 *   I: Set this pin to a digital input,        eg: aI
 *   O: Set this pin to a digital output,       eg: aO
 *   0: Write a digital low to this output,     eg: a0
 *   1: Write a digital high to this output,    eg: a1
 *   U: Write a pull input high,    eg: aU
 *   D: Write a pull input down,    eg: aD
 *   ?: Read the state of this digital input,   eg: a?
 *      State is returned as pinch + state(0|1) eg: a0
 */


static void gpio(char pinch, char cmdch)
{

    int pin = pinch - 'a';
    //pin = pin; //Fixes 25 pin issue

    if (pin < MIN_PIN || pin > MAX_PIN)
    {
        error(ERROR_BAD_PIN_RANGE);
    }

    else {
        //Valid pin label
        char pinC;
        pinC = pin;

        serialPort.putc(pinC);

        serialPort.putc('\n');

        ioPin = pin;

        switch (cmdch)
        {

            case 'A':
            {
            //ioPin = pin -2;

                double aIn = agpios[0].read();
                //char cAin[50];
                //snprintf(cAin,50, "%f", aIn);
                serialPort.putc(pinch);
                serialPort.printf("%.7f",aIn);
                serialPort.putc('\r');
                serialPort.putc('\n');

                //serialPort.putc(faIn);

                //serialPort.printf("SystemCoreClock = %c Hz\n",a8In);

            break;
            }

            case 'I': //Set as input
                //ioPin = pin - 2;
                gpios[ioPin].input();
                gpios[ioPin].mode(PullNone);
            break;

            case 'O':
                //ioPin = pin - 2;
                gpios[ioPin].output();
            break;

            case '0':
                //ioPin = pin - 2;
                gpios[ioPin] = 0;

            break;

            case '1':
                //ioPin = pin - 2;
                gpios[ioPin] = 1;
            break;


            case '?':
                //ioPin = pin -2;
                p = gpios[ioPin].read();
                serialPort.putc(pinch);
                serialPort.printf(p?"1":"0");
                serialPort.putc('\r');
                serialPort.putc('\n');

            break;

            case 'U':

                gpios[ioPin].mode(PullUp);
            break;

            case 'D':

                gpios[ioPin].mode(PullDown);
            break;




        }
    }
 }


/*--------------------------------------------------------------------*/
/* Process a Analogue command.
 *
 * Analogue Commands are two characters.
 * <pinch> <cmdch>
 *
 * pinch is the pin character (a..z) where 'a' represents pin 0.
 * cmdch is the command to perform on that pin:
 *   I: Set this pin to a Analogue input,        eg: aI
 *   O: Set this pin to a Analogue output,       eg: aO
 *   0: Write a Analogue low to this output,     eg: a0
 *   1: Write a Analogue high to this output,    eg: a1
 *   ?: Read the state of this Analogue input,   eg: a?
 *      State is returned as pinch + state(0|1) eg: a0
 */
