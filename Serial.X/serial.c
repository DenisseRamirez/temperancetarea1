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

void main() {
    USART_Init(9600);
    while (1) {
        char Oupcode = USART_Rx();
        switch (Oupcode) { // Checa el Opcode que llega para saber a que funcion del serial llamar para decodificar lo que llega
            case 'F':
                USART_RxS(7, coordenada_array); //Lectura de las coordenadas
                Serial_DecodificacionX(coordenada_array, &CX); // LLamar a serial de decodificacion Coordenada LAS VARIABLES CX Y CY YA SE ENCUENTRAN CON VALORES
                Serial_DecodificacionY(coordenada_array, &CY); // LLamar a serial de decodificacion Coordenada LAS VARIABLES CX Y CY YA SE ENCUENTRAN CON VALORES
                Motor_Movimiento(Oupcode, CX, CY);
                break;
            case 'S':
                USART_RxS(7, coordenada_array); //Lectura de las coordenadas
                Serial_DecodificacionX(coordenada_array, &CX); // LLamar a serial de decodificacion Coordenada LAS VARIABLES CX Y CY YA SE ENCUENTRAN CON VALORES
                Serial_DecodificacionY(coordenada_array, &CY); // LLamar a serial de decodificacion Coordenada LAS VARIABLES CX Y CY YA SE ENCUENTRAN CON VALORES
                Motor_Movimiento(Oupcode, CX, CY);
                break;
            case 'T':
                Actuator_Touch();
                break;
            case 'H':
                Actuator_Hold();
                break;
            case 'R':
                Actuator_Retrain();
                break;
            case 'O':
                Direccion_Memoria = USART_Rx();
                Direccion_Memoria = Seria_Decodificacion_Memoria(Direccion_Memoria);
                Serial_Lectura_Memoria(Direccion_Memoria, &CX, &CY, &CZ);
                //Iniciar control Manadando Variable CZ
                Motor_Movimiento(Oupcode, CX, CY);
                break;
            case 'M':
                Direccion_Memoria = USART_Rx();
                USART_RxS(11, coordenada_setpoint); //Lectura de las coordenadas
                Direccion_Memoria = Seria_Decodificacion_Memoria(Direccion_Memoria);
                Serial_Escritura_Memoria(Direccion_Memoria,coordenada_setpoint);
                break;
        }
    }

}

void Serial_DecodificacionX(char string_coordenada[], int *pointerCX) {
    char coordenadaX[3]; //
    for (int i = 0; i < 3; i++) {
        coordenadaX[i] = string_coordenada[i];
    }
    USART_Tx('2');
    *pointerCX = atoi(coordenadaX); //Cambia el valor de string a una variable int, por lo que se deja el valor de la coordenada x

}

void Serial_DecodificacionY(char string_coordenada[], int *pointerCY) {
    char coordenadaY[3];
    for (int i = 0; i < 3; i++) {
        coordenadaY[i] = string_coordenada[4 + i];
    }
    USART_Tx('1');
    *pointerCY = atoi(coordenadaY); //Cambia el valor de string a una variable int, por lo que se deja el valor de la coordenada y
}

void Serial_DecodificacionZ(char string_coordenada[], int *pointerCZ) {
    char coordenadaZ[3];
    for (int i = 0; i < 3; i++) {
        coordenadaZ[i] = string_coordenada[8 + i];
    }
    *pointerCZ = atoi(coordenadaZ); //Cambia el valor de string a una variable int, por lo que se deja el valor de la coordenada y
}

char Seria_Decodificacion_Memoria(char direccion) {
    switch (direccion) {
        case '0':
            direccion = 0x00;
            break;
        case '1':
            direccion = 0x01;
            break;
        case '2':
            direccion = 0x02;
            break;
        case '3':
            direccion = 0x03;
            break;
        case '4':
            direccion = 0x04;
            break;
        case '5':
            direccion = 0x05;
            break;
        case '6':
            direccion = 0x06;
            break;
        case '7':
            direccion = 0x07;
            break;
        case '8':
            direccion = 0x08;
            break;
        case '9':
            direccion = 0x09;
            break;
        case 'A':
            direccion = 0x0A;
            break;
        case 'B':
            direccion = 0x0B;
            break;
        case 'C':
            direccion = 0x0C;
            break;
        case 'D':
            direccion = 0x0D;
            break;
        case 'E':
            direccion = 0x0E;
            break;
        case 'F':
            direccion = 0x0F;
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
    for (char i = 0; i < 3; i++) {
        direccionX = direccion + i;
        coordenadaX[i] = EEPROM_Rx(direccionX);
    }
    for (char i = 0; i < 3; i++) {
        direccionY = direccion + i + 3;
        coordenadaY[i] = EEPROM_Rx(direccionY);
    }
    for (char i = 0; i < 3; i++) {
        direccionZ = direccion + i + 6;
        coordenadaZ[i] = EEPROM_Rx(direccionZ);
    }
    *pointerCX = atoi(coordenadaX); //Cambia el valor de string a una variable int, por lo que se deja el valor de la coordenada x
    *pointerCY = atoi(coordenadaY); //Cambia el valor de string a una variable int, por lo que se deja el valor de la coordenada y
    *pointerCZ = atoi(coordenadaZ); //Cambia el valor de string a una variable int, por lo que se deja el valor de la coordenada z

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
}

