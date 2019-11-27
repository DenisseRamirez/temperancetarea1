/* 
 * File:   serial.c
 * Author: saenz
 *
 * Created on November 16, 2019, 11:24 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include <xc.h>
#include <string.h>
#include "configuration.h"
#include "UART.h"
#include "serial.h"
#include "PWM.h"
#include "motor.h"
#include "Actuator.h"
#include "EEPROM.h"
#include "GPIOsparcA1.h"

void main() {
    OSCCON= 0x72;// Defines el valor del oscilador interno
    USART_Init(9600);
    GPIO_RD0_TRIS=0;
    GPIO_RD2_TRIS=0;
    GPIO_RD1_TRIS=0;
    GPIO_RD3_TRIS=0;
    Enable_DriverX=1;
    Enable_DriverX=1;
     TRISCbits.RC1 = 0;
    TRISCbits.RC2 = 0;
    PORTCbits.RC1=0;
    while (1) {
        char Oupcode = USART_RxC();//Variable que indica la instruccion
        switch (Oupcode) { // Checa el Opcode que llega para saber a que funcion del serial llamar para decodificar lo que llega
            case 'F'://Movimiento a coordenada rapido 
                USART_RxS(7, coordenada_array); //Lectura de las coordenadas
                Serial_DecodificacionX(coordenada_array, &CoordenadaX); // LLamar a serial de decodificacion Coordenada LAS VARIABLES CX Y CY YA SE ENCUENTRAN CON VALORES
                Serial_DecodificacionY(coordenada_array, &CoordenadaY); // LLamar a serial de decodificacion Coordenada LAS VARIABLES CX Y CY YA SE ENCUENTRAN CON VALORES
                Motor_Movimiento(Oupcode, CoordenadaX, CoordenadaY);
                break;
            case 'S':
                USART_RxS(7, coordenada_array); //Lectura de las coordenadas
                Serial_DecodificacionX(coordenada_array,&CoordenadaX); // LLamar a serial de decodificacion Coordenada LAS VARIABLES CX Y CY YA SE ENCUENTRAN CON VALORES
                Serial_DecodificacionY(coordenada_array,&CoordenadaY); // LLamar a serial de decodificacion Coordenada LAS VARIABLES CX Y CY YA SE ENCUENTRAN CON VALORES
                Motor_Movimiento(Oupcode, CoordenadaX, &CoordenadaY);
                break;
            case 'T':
                Actuator_Touch();
                break;
            case 'H':
                Actuator_Hold();
                break;
            case 'R':
                Actuator_Retract();
                break;
            case 'O':
                Direccion_Memoria = USART_RxC();
                Direccion_Memoria = Seria_Decodificacion_Memoria(Direccion_Memoria);
                Serial_Lectura_Memoria(Direccion_Memoria,&CoordenadaX, &CoordenadaY, &CoordenadaZ);
                //Iniciar control Manadando Variable CZ
                Motor_Movimiento(Oupcode, CoordenadaX, CoordenadaY);
                break;
            case 'M':
                Direccion_Memoria = USART_RxC();
                USART_RxS(11, coordenada_setpoint); //Lectura de las coordenadas
                Direccion_Memoria = Seria_Decodificacion_Memoria(Direccion_Memoria);
                Serial_Escritura_Memoria(Direccion_Memoria,coordenada_setpoint);
                break;
        }
    }
}

void Serial_DecodificacionX(char string_coordenada[], int *pointerCX) { //Convierte la coordenada en str a int
    char coordenadaX[3]; //
    for (int i = 0; i < 3; i++) {
        coordenadaX[i] = string_coordenada[i];
    }
    *pointerCX = atoi(coordenadaX); //Cambia el valor de string a una variable int, por lo que se deja el valor de la coordenada x
    return;
}

void Serial_DecodificacionY(char string_coordenada[], int *pointerCY) {//Convierte la coordenada en str a int
    char coordenadaY[3];
    for (int i = 0; i < 3; i++) {
        coordenadaY[i] = string_coordenada[4 + i];
    } 
    *pointerCY = atoi(coordenadaY); //Cambia el valor de string a una variable int, por lo que se deja el valor de la coordenada y
    return;
}

void Serial_DecodificacionZ(char string_coordenada[], int *pointerCZ) {//Convierte la coordenada en str a int
    char coordenadaZ[3];
    for (int i = 0; i < 3; i++) {
        coordenadaZ[i] = string_coordenada[8 + i];
    }
    *pointerCZ = atoi(coordenadaZ); //Cambia el valor de string a una variable int, por lo que se deja el valor de la coordenada y
    return;
}

char Seria_Decodificacion_Memoria(char direccion) {
    switch (direccion) {
        case '0':
            direccion = 0x00;
            break;
        case '1':
            direccion = 0x10;
            break;
        case '2':
            direccion = 0x20;
            break;
        case '3':
            direccion = 0x30;
            break;
        case '4':
            direccion = 0x40;
            break;
        case '5':
            direccion = 0x50;
            break;
        case '6':
            direccion = 0x60;
            break;
        case '7':
            direccion = 0x70;
            break;
        case '8':
            direccion = 0x80;
            break;
        case '9':
            direccion = 0x90;
            break;
        case 'A':
            direccion = 0xA0;
            break;
        case 'B':
            direccion = 0xB0;
            break;
        case 'C':
            direccion = 0xC0;
            break;
        case 'D':
            direccion = 0xD0;
            break;
        case 'E':
            direccion = 0xE0;
            break;
        case 'F':
            direccion = 0xF0;
            break;
    }
    return direccion;
}

void Serial_Lectura_Memoria(char direccion, int *pointerCX, int *pointerCY, int *pointerCZ) {
    char coordenadaX[3];
    char coordenadaY[3];
    char coordenadaZ[3];
    char direccionX;
    char direccionY;
    char direccionZ;
    for (int i = 0; i < 3; i++) {
        direccionX = direccion + i;
        coordenadaX[i] = EEPROM_Rx(direccionX);//Guardar datos de le EEPROM en string
    }
    for (int i = 0; i < 3; i++) {
        direccionY = direccion + i + 3;
        coordenadaY[i] = EEPROM_Rx(direccionY);//Guardar datos de le EEPROM en string
    }
    for (int i = 0; i < 3; i++) {
        direccionZ = direccion + i + 6;
        coordenadaZ[i] = EEPROM_Rx(direccionZ);//Guardar datos de le EEPROM en string
    }
    
    *pointerCX = atoi(coordenadaX); //Cambia el valor de string a una variable int, por lo que se deja el valor de la coordenada x
    *pointerCY = atoi(coordenadaY); //Cambia el valor de string a una variable int, por lo que se deja el valor de la coordenada y
    *pointerCZ = atoi(coordenadaZ); //Cambia el valor de string a una variable int, por lo que se deja el valor de la coordenada z
    return;
}
void Serial_Escritura_Memoria(char direccion,char string_setpoint[]){
    char direccionFinal;
    for (int i=0;i<3;i++){
        direccionFinal=direccion+i;
        EEPROM_Tx(direccionFinal,string_setpoint[i]);
    }
    for (int i=0;i<3;i++){
        direccionFinal=direccion+i+3;
        EEPROM_Tx(direccionFinal,string_setpoint[i+4]);
    }
    for (int i=0;i<3;i++){
        direccionFinal=direccion+i+6;
        EEPROM_Tx(direccionFinal,string_setpoint[i+8]);
    }
    return;
}

