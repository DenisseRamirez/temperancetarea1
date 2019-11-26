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

/*
 *
 */
void Actuator_Ini(){
   GPIO_RC0_SetDigitalOutput();
}
void Actuator_Touch(){
    GPIO_RC0_SetHigh();
    __delay_ms(100);
    GPIO_RC0_SetLow();
}
void Actuator_Hold(){
    GPIO_RC0_SetHigh();
}
void Actuator_Retract(){
    GPIO_RC0_SetLow();
}

