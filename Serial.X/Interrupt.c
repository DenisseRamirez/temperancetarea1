/* 
 * File:   Interrupt.c
 * Author: saenz
 *
 * Created on December 9, 2019, 8:10 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <xc.h>
#include "GPIOsparcA1.h"
#include "Interrupt.h"
#include "configuration.h"
#include "motor.h"
#include "main.h"

void Int_Ext(void) {
    TRISD = 0x00;
    INTCON2bits.RBPU = 1; //Pull up resistors are not used
    TRISBbits.RB0 = 1; //RB0 as input Limit Switch OR
    TRISBbits.RB1 = 1; //RB1 as input Limit Switch Home X
    TRISBbits.RB2 = 1; //RB2 as input Limit Switch Home Y
    RCONbits.IPEN = 0; //INT priorities are disabled
    INTCONbits.GIE = 1; //Enable all unmasked INT 
    INTCONbits.PEIE = 0; //Disable all peripheral INT
    INTCONbits.INT0IE = 1; //Enable external RB0 interrupt
    INTCON3bits.INT1IE = 1; //Enable external RB1 interrupt
    INTCON3bits.INT2IE = 1; //Enable external RB2 interrupt
    INTCON2bits.INTEDG0 = 1; //INT on rising edge
    INTCON2bits.INTEDG1 = 1; //INT on rising edge
    INTCON2bits.INTEDG2 = 1; //INT on rising edge
    INTCONbits.INT0F = 0; //FLAG INT0 down
    INTCON3bits.INT1IF = 0; //FLAG INT1 down
    INTCON3bits.INT2IF = 0; //FLAG INT2 down
}



void INT0_ACTION(void) {
    main_Home();
    coordenada_anteriorX = 0;
    coordenada_anteriorY = 0;
}

void INT1_ACTION(void) {
    ENABLE_X = 1;
    ENABLE_Y = 1;
    __delay_ms(100);
    if (BanderaX == 0) {
        Motor_Movimiento_Home('S', 20, 0);
    }
    BanderaX = 1;
    return;
}

void INT2_ACTION(void) {
    ENABLE_X = 1; //Habilita los drivers
    ENABLE_Y = 1;
    __delay_ms(100);
    if (BanderaY == 0) {
        Motor_Movimiento_Home('S', 0, 20);
    }
    BanderaY = 1;
    return;
}