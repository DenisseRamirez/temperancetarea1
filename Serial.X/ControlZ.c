/* 
 * File:   ControlZ.c
 * Author: saenz
 *
 * Created on November 24, 2019, 10:36 AM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
void ControlZ (){
    
}
/*Referencia = 150
Sensor = read_ADC()
Error = Sensor - Referencia
Proporcional = Error * Kp
Integral = Integral + Error * Ki * T
Derivativo = (Error - Error_0) * Kd / T
Error_0 = Error
Control = Proporcional + Integral + Derivativo
write_DAC(Control)
*/