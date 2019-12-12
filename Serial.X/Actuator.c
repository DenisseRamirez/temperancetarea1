/* 
 * File:   Actuator.c
 * Author: saenz
 *
 * Created on November 23, 2019, 3:39 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include "GPIOsparcA1.h"
#include "configuration.h"
#include "UART.h"
#include "User_Interface.h"
#include "main.h"
/*
 *
 */

void Actuator_Touch(void) {
    INTCONbits.INT0IE = 0; //Enable external RB0 interrupt
    INTCON3bits.INT1IE = 0; //Enable external RB1 interrupt
    INTCON3bits.INT2IE = 0; //Enable external RB2 interrupt
    INTCONbits.GIE = 0;
    ACTUADOR_SetHigh();
    __delay_ms(100);
    ACTUADOR_SetLow();
    USART_TxS("C\n", sizeof ("C\n") - 1);
    Usart_Interface_ON('V');
    Usart_Interface_OFF('A');
    __delay_ms(100);
    __delay_ms(100);
    __delay_ms(100);

}

void Actuator_Retract(void) {
    INTCONbits.INT0IE = 0; //Enable external RB0 interrupt
    INTCON3bits.INT1IE = 0; //Enable external RB1 interrupt
    INTCON3bits.INT2IE = 0; //Enable external RB2 interrupt
    INTCONbits.GIE = 0;
    ACTUADOR_SetLow();
    USART_TxS("C\n", sizeof ("C\n") - 1);
    Usart_Interface_ON('V');
    Usart_Interface_OFF('A');
    __delay_ms(100);
    __delay_ms(100);
    __delay_ms(100);
}

void Actuator_Hold(void) {
    INTCONbits.INT0IE = 0; //Enable external RB0 interrupt
    INTCON3bits.INT1IE = 0; //Enable external RB1 interrupt
    INTCON3bits.INT2IE = 0; //Enable external RB2 interrupt
    INTCONbits.GIE = 0;
    ACTUADOR_SetHigh();
    USART_TxS("C\n", sizeof ("C\n") - 1);
    Usart_Interface_ON('V');
    Usart_Interface_OFF('A');
    __delay_ms(100);
    __delay_ms(100);
    __delay_ms(100);

}

