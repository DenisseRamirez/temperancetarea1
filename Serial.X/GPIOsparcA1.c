#include "GPIOsparcA1.h"
#include <xc.h>
#include <stdint.h>

void GPIO_init_PORTA(void) {
    UCONbits.USBEN = 0;
    UCONbits.SUSPND = 0;
    UCFGbits.UTRDIS = 1;
    PORTA = 0x00;
    LATA = 0x00;
    ADCON1 = 0x0E;
    CMCON = 0x07; //Datasheet initializing PORTA as IO
    //RA0 has been assigned as sensor z1 (check initialization in ADC.h)
    //RA1 has been assigned as sensor z2 (check initialization in ADC.h)
    //RA2 has NOT been assigned
    //RA3 has NOT been assigned
    GPIO_RA4_SetDigitalInput(); //RA4 is physically connected to RC1
    GPIO_RA5_SetDigitalInput(); //RA5 is OKAY button
    //RA6 has NOT been assigned
    //RA7 is not available
}

void GPIO_init_PORTB(void) {
    PORTB = 0x00;
    LATB = 0x00;
    ADCON1 = 0x0E; //Datasheet initializing PORTB as IO
    GPIO_RB0_SetDigitalInput(); //RB0 has been assigned as Limit Switch 1
    GPIO_RB1_SetDigitalInput(); //RB1 has been assigned as Limit Switch HOME
    GPIO_RB2_SetDigitalInput(); //RB2 has been assigned as RESET
    //RB3 has NOT been assigned
    //RB4 has NOT been assigned
    GPIO_RB5_SetDigitalOutput(); //RB5 has been assigned as RED LED
    GPIO_RB6_SetDigitalOutput(); //RB6 has been assigned as GREEN LED
    GPIO_RB7_SetDigitalOutput(); //RB7 has been assigned as BLUE LED
}

void GPIO_init_PORTC(void) {
    PORTC = 0x00;
    LATC = 0x00; //Datasheet initializing PORTC as IO
    GPIO_RC0_SetDigitalInput(); //RC0 is physically connected to RC2
    GPIO_RC1_SetDigitalOutput(); //RC1 has been assigned as PWM/Step X
    GPIO_RC2_SetDigitalOutput(); //RC2 has been assigned as PWM/Step Y (bridged)
    //RC3 is not available
    //RC4 has been assigned as UP, RC4 is built as input only
    //RC5 has been assigned as DOWN, RC5 is built as input only
    GPIO_RC6_SetDigitalOutput(); //RC6 has been assigned as TX
    GPIO_RC7_SetDigitalInput(); //RC7 has been assigned as RX
}

void GPIO_init_PORTD(void) {
    PORTD = 0x00;
    LATD = 0x00;
    CMCON = 0x07; //Datasheet initializing PORTC as IO
    GPIO_RD0_SetDigitalOutput(); //RD0 has been assigned as Enable X
    GPIO_RD1_SetDigitalOutput(); //RD1 has been assigned as Direction X
    GPIO_RD2_SetDigitalOutput(); //RD2 has been assigned as Enable Y (bridged-notted)
    GPIO_RD3_SetDigitalOutput(); //RD3 has been assigned as Direction Y
    GPIO_RD4_SetDigitalOutput(); //RD4 has been assigned as Enable for 2 DC motors on platform
    GPIO_RD5_SetDigitalOutput(); //RD5 has been assigned as MA DC H bridge
    GPIO_RD6_SetDigitalOutput(); //RD6 has been assigned as MB DC H bridge
    //RD7 has NOT been assigned
}

void GPIO_init_PORTE(void) {
    PORTE = 0x00;
    LATE = 0x00;
    ADCON1 = 0x0E;
    CMCON = 0x07; //Datasheet initializing PORTE as IO
    GPIO_RE0_SetDigitalOutput(); //RE0 has been assigned as actuator
    //RE1 has NOT been assigned
    //RE2 has NOT been assigned
    //RE3 is MCLR
    //RE4 is not available
    //RE5 is not available+
    //RE6 is not available
    //RE7 is not available
}