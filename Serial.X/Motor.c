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
/*
 * 
 */
int Motor_Conversion(int Coordenada)
{
    float conversion = 0.2; //Cada paso nos da 0.2 mm
    pasos_convertidos = Coordenada / conversion;
    return pasos_convertidos;
}

void Motor_Movimiento(char Oupcode, int CoordenadaX, int CoordenadaY)
{
    pasosX = Motor_Conversion(CoordenadaX);
    pasosY = Motor_Conversion(CoordenadaY);
    pasosX=Motor_Calcular_PasosX(pasosX);
    pasosY=Motor_Calcular_PasosY(pasosY);
    PWM_GeneratePulsos(Oupcode, pasosX, pasosY);
}
int Motor_Calcular_PasosX(int pasos_converX)
{
    if (pasos_converX <= pasosX)
    {
        Direction_DriverX = 0;
        pulsX = pasosX - pasos_converX;
    }
    else
    {
        Direction_DriverX = 1;
        pulsX = pasos_converX-pasosX;
    }
    return (pulsX);
}
int Motor_Calcular_PasosY(int pasos_converY)
{
    if (pasos_converY < pasosY)
    {
        Direction_DriverY = 0;
        pulsY = pasosY - pasos_converY;
    } else
    {
        Direction_DriverY = 1;
        pulsY = pasos_converY-pasosY;
    }
    return (pulsY);
}

void Motor_MovimientoZ_Init(char direccion)
{
    GPIO_RD4_SetDigitalOutput();
}

void Motor_MovimientoZ(char direccion)
{
    GPIO_RD4_SetHigh();
    if (direccion == '1')
    { //Aqui se va a comprobar el estado del boton en dado caso
        GPIO_RD5_SetHigh();
        GPIO_RD6_SetLow();
    }
    else if (direccion == '0')
    { //Aqui se va a comprobar el estado del boton en dado caso
        GPIO_RD5_SetLow();
        GPIO_RD6_SetHigh();
    }
}