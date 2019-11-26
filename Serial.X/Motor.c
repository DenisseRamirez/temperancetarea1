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

/*
 * 
 */
int Motor_Conversion(int Coordenada) {
    float conversion = 0.2; //Cada paso nos da 0.2 mm
    pasos_convertidos = Coordenada / conversion;
    return pasos_convertidos;
}

void Motor_Movimiento(char Oupcode, int CoordenadaX, int CoordenadaY) {
    CoordenadaXX = Motor_Calcular_PasosX(CoordenadaX);
    CoordenadaYY = Motor_Calcular_PasosY(CoordenadaY);
    pasosX = Motor_Conversion(CoordenadaXX);
    pasosY = Motor_Conversion(CoordenadaYY);
    coordenada_anteriorX=CoordenadaX;
    coordenada_anteriorY=CoordenadaY;
    PWM_GeneratePulsos(Oupcode, pasosX, pasosY);
    return;
}

int Motor_Calcular_PasosX(int coordenada_converX) {
    if (coordenada_converX < coordenada_anteriorX) {
        USART_Tx('-');
        Direction_DriverX = 0;
        coordenaX = coordenada_anteriorX - coordenada_converX;
    } else if (coordenada_converX > coordenada_anteriorX) {
        USART_Tx('+');
        Direction_DriverX = 1;
        coordenaX = coordenada_converX - coordenada_anteriorX;
    } else if (coordenada_converX == coordenada_anteriorX) {
        coordenaX = 0;
    }
    return (coordenaX);
}

int Motor_Calcular_PasosY(int coordenada_converY) {
    if (coordenada_converY < coordenada_anteriorY) {
        USART_Tx('-');
        Direction_DriverY = 0;
        coordenaY = coordenada_anteriorY - coordenada_converY;
    } else if (coordenada_converY > coordenada_anteriorY) {
        USART_Tx('+');
        Direction_DriverY = 1;
        coordenaY = coordenada_converY - coordenada_anteriorY;
    } else if (coordenada_converY == coordenada_anteriorY) {
        coordenaY=0;
    }
    return (coordenaY);
}

void Motor_MovimientoZ_Init(char direccion) {
    GPIO_RD4_SetDigitalOutput();
}

void Motor_MovimientoZ(char direccion) {
    GPIO_RD4_SetHigh();
    if (direccion == '1') { //Aqui se va a comprobar el estado del boton en dado caso
        GPIO_RD5_SetHigh();
        GPIO_RD6_SetLow();
    } else if (direccion == '0') { //Aqui se va a comprobar el estado del boton en dado caso
        GPIO_RD5_SetLow();
        GPIO_RD6_SetHigh();
    }
    return;
}