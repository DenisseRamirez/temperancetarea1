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
    OSCCON = 0x72; // Defines el valor del oscilador interno
    USART_Init(9600);
    GPIO_RD0_TRIS = 0;
    GPIO_RD2_TRIS = 0;
    GPIO_RD1_TRIS = 0;
    GPIO_RD3_TRIS = 0;
    Enable_DriverX = 1;
    Enable_DriverX = 1;
    TRISCbits.RC1 = 0;
    TRISCbits.RC2 = 0;
    PORTCbits.RC1 = 0;
    char instruction_counter = 0;
    USART_TxS("WELCOME TO SPARK", sizeof ("WELCOME TO SPARK"));
    USART_TxS("PLEASE INSERT THE INSTRUCTION OF SETPOINT", sizeof ("PLEASE INSERT THE INSTRUCTION OF SETPOINT"));
    while (1) {
        if (instruction_counter == 0) {
            USART_TxS("WAITING FOR INSTRUCTION", sizeof ("WAITING FOR INSTRUCTION"));
            instruction_counter = 1;
        }
        char Oupcode = USART_RxC(); //Variable que indica la instruccion
        switch (Oupcode) { // Checa el Opcode que llega para saber a que funcion del serial llamar para decodificar lo que llega
            case 'F'://Movimiento a coordenada rapido 
                USART_RxS(7, coordenada_array); //Lectura de las coordenadas
                USART_TxS("WAIT UNTIL COMPLETE...", sizeof ("WAIT UNTIL COMPLETE..."));
                Serial_DecodificacionX(coordenada_array, &CoordenadaX); // LLamar a serial de decodificacion Coordenada LAS VARIABLES CX Y CY YA SE ENCUENTRAN CON VALORES
                Serial_DecodificacionY(coordenada_array, &CoordenadaY); // LLamar a serial de decodificacion Coordenada LAS VARIABLES CX Y CY YA SE ENCUENTRAN CON VALORES
                Serial_RangosCoordenadas(CoordenadaX);
                Serial_RangosCoordenadas(CoordenadaY);
                if (Coordenadas_fuera == 1) {
                    Coordenadas_fuera == 0;
                } else {
                    Motor_Movimiento(Oupcode, CoordenadaX, CoordenadaY);
                }
                break;
            case 'S':
                USART_RxS(7, coordenada_array); //Lectura de las coordenadas
                USART_TxS("WAIT UNTIL COMPLETE...", sizeof ("WAIT UNTIL COMPLETE..."));
                Serial_DecodificacionX(coordenada_array, &CoordenadaX); // LLamar a serial de decodificacion Coordenada LAS VARIABLES CX Y CY YA SE ENCUENTRAN CON VALORES
                Serial_DecodificacionY(coordenada_array, &CoordenadaY); // LLamar a serial de decodificacion Coordenada LAS VARIABLES CX Y CY YA SE ENCUENTRAN CON VALORES
                Serial_RangosCoordenadas(CoordenadaX); //Checar las coordenadas
                Serial_RangosCoordenadas(CoordenadaY); //Checar las coordenadas
                if (Coordenadas_fuera == 1) {//En caso de Coordenada ingresada fuera del rango no mover motores
                    Coordenadas_fuera == 0;
                } else {
                    Motor_Movimiento(Oupcode, CoordenadaX, CoordenadaY);
                }
                break;
            case 'T':
                USART_TxS("WAIT UNTIL COMPLETE...", sizeof ("WAIT UNTIL COMPLETE..."));
                Actuator_Touch();
                break;
            case 'H':
                USART_TxS("WAIT UNTIL COMPLETE...", sizeof ("WAIT UNTIL COMPLETE..."));
                Actuator_Hold();
                break;
            case 'R':
                USART_TxS("WAIT UNTIL COMPLETE...", sizeof ("WAIT UNTIL COMPLETE..."));
                Actuator_Retract();
                break;
            case 'O':
                USART_TxS("WAIT UNTIL COMPLETE...", sizeof ("WAIT UNTIL COMPLETE..."));
                Direccion_Memoria = USART_RxC();
                Direccion_Memoria = Seria_Decodificacion_Memoria(Direccion_Memoria);
                Serial_Lectura_Memoria(Direccion_Memoria, &CoordenadaX, &CoordenadaY, &CoordenadaZ);
                if (Coordenadas_fuera == 1) {//En caso de Coordenada ingresada fuera del rango no comenzar
                    USART_TxS("PLEASE MODIFY THE SETPOINT AND TRY AGAIN", sizeof ("PLEASE MODIFY THE SETPOINT AND TRY AGAIN"));
                    Coordenadas_fuera == 0;
                } else {
                    //Iniciar control Manadando Variable CZ
                    Motor_Movimiento(Oupcode, CoordenadaX, CoordenadaY);
                }
                break;
            case 'M':
                Direccion_Memoria = USART_RxC();
                USART_RxS(11, coordenada_setpoint); //Lectura de las coordenadas
                USART_TxS("WAIT UNTIL COMPLETE...", sizeof ("WAIT UNTIL COMPLETE..."));
                Direccion_Memoria = Seria_Decodificacion_Memoria(Direccion_Memoria);
                Serial_Escritura_Memoria(Direccion_Memoria, coordenada_setpoint);
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

void Serial_RangosCoordenadas(int C) {//Funcion que checa que las coordenadas se encuentren dentro del rango
    if (C > 300 | C < 0) {//En caso de Coordenada ingresada fuera del rango prender banderra y enviar error
        USART_TxS("ERROR CORDINATES OUTSIDE THE RANGE", sizeof ("ERROR CORDINATES OUTSIDE THE RANGE"));
        Coordenadas_fuera = 1;
    }
    return;
}

char Seria_Decodificacion_Memoria(char direccion) {
    switch (direccion) {
        case '0':
            direccion = 0x00;
            USART_TxS("COORDINATE OF SETPOINT 0 ", sizeof ("COORDINATE OF SETPOINT 0 "));
            break;
        case '1':
            direccion = 0x10;
            USART_TxS("COORDINATE OF SETPOINT 1 ", sizeof ("COORDINATE OF SETPOINT 1 "));
            break;
        case '2':
            direccion = 0x20;
            USART_TxS("COORDINATE OF SETPOINT 2 ", sizeof ("COORDINATE OF SETPOINT 2 "));
            break;
        case '3':
            direccion = 0x30;
            USART_TxS("COORDINATE OF SETPOINT 3 ", sizeof ("COORDINATE OF SETPOINT 3 "));
            break;
        case '4':
            direccion = 0x40;
            USART_TxS("COORDINATE OF SETPOINT 4 ", sizeof ("COORDINATE OF SETPOINT 4 "));
            break;
        case '5':
            direccion = 0x50;
            USART_TxS("COORDINATE OF SETPOINT 5 ", sizeof ("COORDINATE OF SETPOINT 5 "));
            break;
        case '6':
            direccion = 0x60;
            USART_TxS("COORDINATE OF SETPOINT 6 ", sizeof ("COORDINATE OF SETPOINT 6 "));
            break;
        case '7':
            direccion = 0x70;
            USART_TxS("COORDINATE OF SETPOINT 7 ", sizeof ("COORDINATE OF SETPOINT 7 "));
            break;
        case '8':
            direccion = 0x80;
            USART_TxS("COORDINATE OF SETPOINT 8 ", sizeof ("COORDINATE OF SETPOINT 8 "));
            break;
        case '9':
            direccion = 0x90;
            USART_TxS("COORDINATE OF SETPOINT 9 ", sizeof ("COORDINATE OF SETPOINT 9 "));
            break;
        case 'A':
            direccion = 0xA0;
            USART_TxS("COORDINATE OF SETPOINT 10 ", sizeof ("COORDINATE OF SETPOINT 10 "));
            break;
        case 'B':
            direccion = 0xB0;
            USART_TxS("COORDINATE OF SETPOINT 11 ", sizeof ("COORDINATE OF SETPOINT 11 "));
            break;
        case 'C':
            direccion = 0xC0;
            USART_TxS("COORDINATE OF SETPOINT 12 ", sizeof ("COORDINATE OF SETPOINT 12 "));
            break;
        case 'D':
            direccion = 0xD0;
            USART_TxS("COORDINATE OF SETPOINT 13 ", sizeof ("COORDINATE OF SETPOINT 13 "));
            break;
        case 'E':
            direccion = 0xE0;
            USART_TxS("COORDINATE OF SETPOINT 14 ", sizeof ("COORDINATE OF SETPOINT 14 "));
            break;
        case 'F':
            direccion = 0xF0;
            USART_TxS("COORDINATE OF SETPOINT 15 ", sizeof ("COORDINATE OF SETPOINT 15 "));
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
        coordenadaX[i] = EEPROM_Rx(direccionX); //Guardar datos de le EEPROM en string
    }
    for (int i = 0; i < 3; i++) {
        direccionY = direccion + i + 3;
        coordenadaY[i] = EEPROM_Rx(direccionY); //Guardar datos de le EEPROM en string
    }
    for (int i = 0; i < 3; i++) {
        direccionZ = direccion + i + 6;
        coordenadaZ[i] = EEPROM_Rx(direccionZ); //Guardar datos de le EEPROM en string
    }

    *pointerCX = atoi(coordenadaX); //Cambia el valor de string a una variable int, por lo que se deja el valor de la coordenada x
    *pointerCY = atoi(coordenadaY); //Cambia el valor de string a una variable int, por lo que se deja el valor de la coordenada y
    *pointerCZ = atoi(coordenadaZ); //Cambia el valor de string a una variable int, por lo que se deja el valor de la coordenada z
    USART_TxS("READ", sizeof ("READ"));
    USART_TxS("COORDINATE X:", sizeof ("COORDINATE X:"));
    USART_TxS(coordenadaX, sizeof (coordenadaX));
    USART_TxS("COORDINATE Y:", sizeof ("COORDINATE Y:"));
    USART_TxS(coordenadaX, sizeof (coordenadaY));
    USART_TxS("COORDINATE Z:", sizeof ("COORDINATE Z:"));
    USART_TxS(coordenadaX, sizeof (coordenadaZ));
    Serial_RangosCoordenadas(CoordenadaX);
    Serial_RangosCoordenadas(CoordenadaY);
    Serial_RangosCoordenadas(CoordenadaZ);
    return;
}

void Serial_Escritura_Memoria(char direccion, char string_setpoint[]) {
    char direccionFinal;
    for (int i = 0; i < 3; i++) {
        direccionFinal = direccion + i;
        EEPROM_Tx(direccionFinal, string_setpoint[i]);
    }
    USART_TxS("COORDINATE X SAVED", sizeof ("COORDINATE X SAVED"));
    for (int i = 0; i < 3; i++) {
        direccionFinal = direccion + i + 3;
        EEPROM_Tx(direccionFinal, string_setpoint[i + 4]);
    }
    USART_TxS("COORDINATE Y SAVED", sizeof ("COORDINATE Y SAVED"));
    for (int i = 0; i < 3; i++) {
        direccionFinal = direccion + i + 6;
        EEPROM_Tx(direccionFinal, string_setpoint[i + 8]);
    }
    USART_TxS("COORDINATE Z SAVED", sizeof ("COORDINATE Z SAVED"));
    return;
}

