#include "GPIOsparcA1.h"
#include <xc.h>
#include <stdint.h>

void GPIO_PORTB(void){
    PORTB = 0x00; 
    LATB = 0x00;                    
    ADCON1 = 0x0E;                  //Datasheet initializing PORTC as IO
    GPIO_RB0_SetDigitalInput();     //RB0 has been assigned as Limit Switch 1
    GPIO_RB1_SetDigitalInput();     //RB1 has been assigned as Limit Switch HOME
    GPIO_RB2_SetDigitalInput();     //RB2 has been assigned as RESET
    //RB3 has been assigned as Sensor Z1
    //RB4 has been assigned as Sensor Z2
    GPIO_RB5_SetDigitalOutput();    //RB5 has been assigned as RED LED
    GPIO_RB6_SetDigitalOutput();    //RB6 has been assigned as GREEN LED
    GPIO_RB7_SetDigitalOutput();    //RB7 has been assigned as BLUE LED
}

void GPIO_PORTC(void){
    PORTC = 0x00; 
    LATC = 0x00;                    //Datasheet initializing PORTC as IO
    GPIO_RC0_SetDigitalOutput();    //RC0 has been assigned as the linear actuator
    GPIO_RC1_SetDigitalOutput();    //RC1 has been assigned as PWM/Step X
    GPIO_RC2_SetDigitalOutput();    //RC2 has been assigned as PWM/Step Y (bridged)
                                    //RC3 is not available
                                    //RC4 has been assigned as UP
                                    //RC5 has been assigned as DOWN
    GPIO_RC6_SetDigitalOutput();    //RC6 has been assigned as TX
    GPIO_RC7_SetDigitalInput();     //RC7 has been assigned as RX
}
