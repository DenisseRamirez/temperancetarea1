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
/*
 * 
 */
int Motor_Conversion(int Coordenada){
    float conversion=0.2;//Cada paso nos da 0.2 mm
    pasos_convertidos=Coordenada/conversion;
    return pasos_convertidos;
}

void Motor_Movimiento(char Oupcode,int CoordenadaX,int CoordenadaY){
    pasosX=Motor_Conversion(CoordenadaX);
    pasosY=Motor_Conversion(CoordenadaY);
    PWM_GeneratePulsos(Oupcode,pasosX,pasosY);
}