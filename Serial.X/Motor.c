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

void Motor_Movimiento(char Oupcode,int Motor_CoordenadaX, int Motor_CoordenadaY) {
    Motor_Calcular_PasosX(Motor_CoordenadaX);
    Motor_Calcular_PasosY(Motor_CoordenadaY);
    PasosX = Motor_Conversion(DeltaX);
    PasosY = Motor_Conversion(DeltaY);
    coordenada_anteriorX=Motor_CoordenadaX;
    coordenada_anteriorY=Motor_CoordenadaY;
    PWM_GeneratePulsos(Oupcode, PasosX, PasosY);
    USART_TxS("COMPLETED\n",sizeof("COMPLETED\n")-1);
    return;
}

void Motor_Calcular_PasosX(int coordenada_actualX) {
    if (coordenada_actualX < coordenada_anteriorX) {
        
        Direction_DriverX = 1;
        DeltaX = coordenada_anteriorX - coordenada_actualX;
    } else if (coordenada_actualX > coordenada_anteriorX) {
       
        Direction_DriverX = 0;
        DeltaX = coordenada_actualX - coordenada_anteriorX;
    } else if (coordenada_actualX == coordenada_anteriorX) {
        DeltaX = 0;
    }
}

void Motor_Calcular_PasosY(int coordenada_actualY) {
    if (coordenada_actualY < coordenada_anteriorY) {
       
        Direction_DriverY = 1;
        DeltaY = coordenada_anteriorY - coordenada_actualY;
    } else if (coordenada_actualY > coordenada_anteriorY) {
       
        Direction_DriverY = 0;
        DeltaY = coordenada_actualY - coordenada_anteriorY;
    } else if (coordenada_actualY == coordenada_anteriorY) {
        DeltaY=0;
    }
}

void Motor_MovimientoZ_Init(char direccion) {
    GPIO_RD4_SetDigitalOutput();
}

void Motor_MovimientoZ() {
    GPIO_RD4_SetHigh();
    if (PORTCbits.RC5==1) { //Aqui se va a comprobar el estado del boton en dado caso
        GPIO_RD5_SetHigh();
        GPIO_RD6_SetLow();
    } else if (PORTCbits.RC6==1) { //Aqui se va a comprobar el estado del boton en dado caso
        GPIO_RD5_SetLow();
        GPIO_RD6_SetHigh();
    } if (PORTCbits.RC5==0 &&PORTCbits.RC6==0){
        GPIO_RD5_SetLow();
        GPIO_RD6_SetLow();
    }
    return;
}
void Motor_Home(){
    Direction_DriverX = 1;
    Direction_DriverY = 1;
    PWM_InitS();
    T2CONbits.TMR2ON = 1;
}
void Motor_Movimiento_Home(char Oupcode,int Motor_CoordenadaX, int Motor_CoordenadaY) {
    T2CONbits.TMR2ON =0 ;
    Direction_DriverX = 0;
    Direction_DriverY = 0;
    PasosX = Motor_Conversion(Motor_CoordenadaX);
    PasosY = Motor_Conversion(Motor_CoordenadaY);
    PWM_GeneratePulsos(Oupcode, PasosX, PasosY);
    return;
}