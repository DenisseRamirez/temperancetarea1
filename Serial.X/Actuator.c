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
/*
 *
 */

void Actuator_Touch(void) {
    GPIO_RC0_SetLow();
    __delay_ms(100);
    GPIO_RC0_SetHigh();
    USART_TxS("C\n", sizeof ("C\n") - 1);
    Usart_Interface_ON('V');
    Usart_Interface_OFF('A');
}

void Actuator_Retract(void) {
    GPIO_RC0_SetHigh();
    USART_TxS("C\n", sizeof ("C\n") - 1);
    Usart_Interface_ON('V');
    Usart_Interface_OFF('A');
}

void Actuator_Hold(void) {
    GPIO_RC0_SetLow();
    USART_TxS("C\n", sizeof ("C\n") - 1);
    Usart_Interface_ON('V');
    Usart_Interface_OFF('A');
}

