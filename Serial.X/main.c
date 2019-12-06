/* 
 * File:   main.c
 * Author: saenz
 *
 * Created on November 25, 2019, 11:05 PM
 */
#include <xc.h>
#include <stdio.h>
#include <stdlib.h>
#include "main.h"
#include "configuration.h"
#include "ControlZ.h"
#include "UART.h"
#include "motor.h"
#include "PWM.h"
#include "serial.h"
#include "Actuator.h"
#include "GPIOsparcA1.h"
#include "User_Interface.h"

void main(void) {
    OSCCON = 0x72;
    GPIO_init_PORTA();
    GPIO_init_PORTB();
   GPIO_init_PORTC();
   GPIO_init_PORTD();
    GPIO_init_PORTE();
    ENABLE_Z_SetLow();
    ENABLE_X = 1;
    ENABLE_Y = 1;
    USART_Init(9600);
    Int_Ext();
    USART_TxS("WELCOME TO SPARC\n", sizeof ("WELCOME TO SPARC\n") - 1);
   Usart_Interface_ON('A');
    USART_TxS("W\n", sizeof ("W\n") - 1);
   main_Home();
    Usart_Interface_OFF('A');
    USART_TxS("C\n", sizeof ("C\n") - 1);
     Usart_Interface_ON('V');
    Serial_Oupcode();
    USART_TxS("F", sizeof ("F") - 1);
    while(1);
}

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

void __interrupt() INT_isr(void) {

    if (INTCON3bits.INT1IF == 1) {
        INT1_ACTION(); //take action 1 before action 0
        __delay_ms(10); //debouncing
        INTCON3bits.INT1IF = 0; //FLAG INT1 down
    }
    if (INTCON3bits.INT2IF == 1) {
        INT2_ACTION(); //take action 2 before any other
        __delay_ms(10); //debouncing
        INTCON3bits.INT2IF = 0; //FLAG INT2 down
    }
    if (INTCONbits.INT0IF == 1) {
        INT0_ACTION(); //take action 0
        __delay_ms(10); //debouncing
        INTCONbits.INT0F = 0; //FLAG INT0 down
    }
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
        Motor_Movimiento_Home('S', 10, 0);
    }
    BanderaX = 1;
    return;
}

void INT2_ACTION(void) {
    ENABLE_X = 1; //Habilita los drivers
    ENABLE_Y = 1;
    __delay_ms(100);
    if (BanderaY == 0) {
        Motor_Movimiento_Home('S', 0, 10);
    }
    BanderaY = 1;
    return;
}

void main_Home(void) {
    while (BanderaX == 0) {
        ENABLE_X = 0; //Habilita los drivers
        ENABLE_Y = 1;
        Motor_Home();
    }
    while (BanderaY == 0) {
        ENABLE_X = 1; //Habilita los drivers
        ENABLE_Y = 0;
        Motor_Home();
    }
    ENABLE_X = 1;
    ENABLE_Y = 1;
    T2CONbits.TMR2ON = 0;
    BanderaX = 0;
    BanderaY = 0;
    return;
}


/*
void Oneshot() {
    if (PORTBbits.RB2 == 0 & oneshot == 0) {
        cont++;
        oneshot = 1;
    }
}
 */