/* 
 * File:   Motor.c
 * Author: saenz
 *
 * Created on November 20, 2019, 9:22 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include "PWM.h"
#include "motor.h"
#include "GPIOsparcA1.h"
#include "UART.h"
#include "User_Interface.h"

/*
 * 
 */
int Motor_Conversion(int Coordenada) {
    float conversion = 0.2; //Cada paso nos da 0.2 mm
    pasos_convertidos = Coordenada / conversion;
    return pasos_convertidos;
}

void Motor_Movimiento(char Oupcode, int Motor_CoordenadaX, int Motor_CoordenadaY) {
    Motor_Calcular_PasosX(Motor_CoordenadaX);
    Motor_Calcular_PasosY(Motor_CoordenadaY);
    PasosX = Motor_Conversion(DeltaX);
    PasosY = Motor_Conversion(DeltaY);
    coordenada_anteriorX = Motor_CoordenadaX;
    coordenada_anteriorY = Motor_CoordenadaY;
    PWM_GeneratePulsos(Oupcode, PasosX, PasosY);
    ENABLE_X = 1;
    ENABLE_Y = 1;
    USART_TxS("C\n", sizeof ("C\n") - 1);
    Usart_Interface_ON('V');
    Usart_Interface_OFF('A');
    return;
}

void Motor_Calcular_PasosX(int coordenada_actualX) {
    if (coordenada_actualX < coordenada_anteriorX) {

        DIRECCION_X = 0;
        DeltaX = coordenada_anteriorX - coordenada_actualX;
    } else if (coordenada_actualX > coordenada_anteriorX) {

        DIRECCION_X = 1;
        DeltaX = coordenada_actualX - coordenada_anteriorX;
    } else if (coordenada_actualX == coordenada_anteriorX) {
        DeltaX = 0;
    }
}

void Motor_Calcular_PasosY(int coordenada_actualY) {
    if (coordenada_actualY < coordenada_anteriorY) {

        DIRECCION_Y = 0;
        DeltaY = coordenada_anteriorY - coordenada_actualY;
    } else if (coordenada_actualY > coordenada_anteriorY) {

        DIRECCION_Y = 1;
        DeltaY = coordenada_actualY - coordenada_anteriorY;
    } else if (coordenada_actualY == coordenada_anteriorY) {
        DeltaY = 0;
    }
}

void Motor_MovimientoZ(void) {
    if (BOTON_UP_GetValue() == 1) { //Aqui se va a comprobar el estado del boton en dado caso

        ENABLE_Z_SetHigh();
        INPUT_A_SetHigh();
        INPUT_B_SetLow();
    } else if (BOTON_DOWN_GetValue() == 1) { //Aqui se va a comprobar el estado del boton en dado caso

        ENABLE_Z_SetHigh();
        INPUT_A_SetLow();
        INPUT_B_SetHigh();
    }
    while (BOTON_DOWN_GetValue() == 0 && BOTON_UP_GetValue() == 0) {
        INPUT_A_SetHigh();
        INPUT_B_SetHigh();
        ENABLE_Z_SetLow();
        return;
    }
}

void Motor_Home(void) {
    DIRECCION_X = 0;
    DIRECCION_Y = 0;
    PWM_InitF();
    T2CONbits.TMR2ON = 1;
}

void Motor_Movimiento_Home(char Oupcode, int Motor_CoordenadaX, int Motor_CoordenadaY) {
    T2CONbits.TMR2ON = 0;
    DIRECCION_X = 1;
    DIRECCION_Y = 1;
    PasosX = Motor_Conversion(Motor_CoordenadaX);
    PasosY = Motor_Conversion(Motor_CoordenadaY);
    PWM_GeneratePulsos(Oupcode, PasosX, PasosY);
    return;
}