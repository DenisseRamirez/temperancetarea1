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
#include <pic18f4550.h>
#include "configuration.h"
#include "UART.h"
#include "serial.h"
#include "PWM.h"
#include "motor.h"
#include "Actuator.h"
#include "EEPROM.h"
#include "GPIOsparcA1.h"
#include "ControlZ.h"
#include "User_Interface.h"
#include "Interrupt.h"

void Serial_Oupcode(void) {
    char instruction_counter = 0;
    while (1) {
        if (instruction_counter == 0) {
            USART_TxS("R\n", sizeof ("R\n") - 1);
            instruction_counter = 1;
        }
        char Oupcode = USART_RxC(); //Variable que indica la instruccion
        switch (Oupcode) { // Checa el Opcode que llega para saber a que funcion del serial llamar para decodificar lo que llega
            case 'F'://Movimiento a coordenada rapido 
                USART_RxS(7, coordenada_array); //Lectura de las coordenadas
                if (Conexion_perdida == 1) {
                    USART_TxS("E3\n", sizeof ("E3\n") - 1);
                    Conexion_perdida = 0;
                    break;
                } else {
                    USART_TxS("W\n", sizeof ("W\n") - 1);
                    Usart_Interface_OFF('V');
                    Usart_Interface_ON('A');
                    Serial_DecodificacionX(coordenada_array, &CoordenadaX); // LLamar a serial de decodificacion Coordenada LAS VARIABLES CX Y CY YA SE ENCUENTRAN CON VALORES
                    Serial_DecodificacionY(coordenada_array, &CoordenadaY); // LLamar a serial de decodificacion Coordenada LAS VARIABLES CX Y CY YA SE ENCUENTRAN CON VALORES
                    Serial_RangosCoordenadas(CoordenadaX);
                    Serial_RangosCoordenadas(CoordenadaY);
                    if (Coordenadas_fuera == 1) {//En caso de Coordenada ingresada fuera del rango no comenzar
                        USART_TxS("E1\n", sizeof ("E1\n") - 1);
                        Usart_Interface_OFF('V');
                        Usart_Interface_OFF('A');
                        Coordenadas_fuera = 0;
                    } else if (Coordenadas_mal == 1) {
                        USART_TxS("E2\n", sizeof ("E2\n") - 1);
                        Usart_Interface_OFF('V');
                        Usart_Interface_OFF('A');
                        Coordenadas_mal = 0;
                    } else {
                        Motor_Movimiento(Oupcode, CoordenadaX, CoordenadaY);
                    }
                }
                break;
            case 'S':
                USART_RxS(7, coordenada_array); //Lectura de las coordenadas
                if (Conexion_perdida == 1) {
                    USART_TxS("E3\n", sizeof ("E3\n") - 1);
                    Conexion_perdida = 0;
                    break;
                } else {
                    USART_TxS("W\n", sizeof ("W\n") - 1);
                    Usart_Interface_OFF('V');
                    Usart_Interface_ON('A');
                    Serial_DecodificacionX(coordenada_array, &CoordenadaX); // LLamar a serial de decodificacion Coordenada LAS VARIABLES CX Y CY YA SE ENCUENTRAN CON VALORES
                    Serial_DecodificacionY(coordenada_array, &CoordenadaY); // LLamar a serial de decodificacion Coordenada LAS VARIABLES CX Y CY YA SE ENCUENTRAN CON VALORES
                    Serial_RangosCoordenadas(CoordenadaX); //Checar las coordenadas
                    Serial_RangosCoordenadas(CoordenadaY); //Checar las coordenadas
                    if (Coordenadas_fuera == 1) {//En caso de Coordenada ingresada fuera del rango no comenzar
                        USART_TxS("E1\n", sizeof ("E1\n") - 1);
                        Usart_Interface_OFF('V');
                        Usart_Interface_OFF('A');
                        Coordenadas_fuera = 0;
                    } else if (Coordenadas_mal == 1) {
                        USART_TxS("E2\n", sizeof ("E2\n") - 1);
                        Usart_Interface_OFF('V');
                        Usart_Interface_OFF('A');
                        Coordenadas_mal = 0;
                    } else {
                        Motor_Movimiento(Oupcode, CoordenadaX, CoordenadaY);
                    }
                }
                break;
            case 'T':
                USART_TxS("W\n", sizeof ("W\n") - 1);
                Usart_Interface_OFF('V');
                Usart_Interface_ON('A');
                Actuator_Touch();
                break;
            case 'H':
                USART_TxS("W\n", sizeof ("W\n") - 1);
                Usart_Interface_OFF('V');
                Usart_Interface_ON('A');
                Actuator_Hold();
                break;
            case 'R':
                USART_TxS("W\n", sizeof ("W\n") - 1);
                Usart_Interface_OFF('V');
                Usart_Interface_ON('A');
                Actuator_Retract();

                break;
            case 'O':
                USART_TxS("W\n", sizeof ("W\n") - 1);
                Usart_Interface_OFF('V');
                Usart_Interface_ON('A');
                Direccion_Memoria = USART_RxC();
                Direccion_Memoria = Seria_Decodificacion_Memoria(Direccion_Memoria);
                Serial_Lectura_MemoriaX(Direccion_Memoria, &CoordenadaX);
                Serial_Lectura_MemoriaY(Direccion_Memoria, &CoordenadaY);
                Serial_Lectura_MemoriaZ(Direccion_Memoria, &CoordenadaZ);
                if (Coordenadas_fuera == 1) {//En caso de Coordenada ingresada fuera del rango no comenzar
                    USART_TxS("E1\n", sizeof ("E1\n") - 1);
                    Usart_Interface_OFF('V');
                    Usart_Interface_OFF('A');
                    // USART_TxS("PLEASE MODIFY THE SETPOINT AND TRY AGAIN\n", sizeof ("PLEASE MODIFY THE SETPOINT AND TRY AGAIN\n") - 1);
                    Coordenadas_fuera = 0;
                } else if (Coordenadas_mal == 1) {
                    USART_TxS("E2\n", sizeof ("E2\n") - 1);
                    Usart_Interface_OFF('V');
                    Usart_Interface_OFF('A');
                    // USART_TxS("PLEASE MODIFY THE SETPOINT AND TRY AGAIN\n", sizeof ("PLEASE MODIFY THE SETPOINT AND TRY AGAIN\n") - 1);
                    Coordenadas_mal = 0;
                } else {
                    if (Coordenadas_control_fuera == 1) {
                        Coordenadas_control_fuera = 0;
                        USART_TxS("A\n", sizeof ("A\n") - 1);
                        Usart_Interface_ON('A');
                        Usart_Interface_OFF('V');
                        __delay_ms(200);
                        while (BOTON_OK_GetValue() == 0) {
                            Motor_MovimientoZ();
                        }
                        INPUT_A_SetHigh();
                        INPUT_B_SetHigh();
                        USART_TxS("R\n", sizeof ("R\n") - 1);
                        Usart_Interface_ON('V');
                        Usart_Interface_OFF('A');
                        __delay_ms(200);
                        Motor_Movimiento(Oupcode, CoordenadaX, CoordenadaY);
                    } else {
                       Control_Z(CoordenadaZ);
                        __delay_ms(200);
                        Motor_Movimiento(Oupcode, CoordenadaX, CoordenadaY);
                    }

                }
                break;
            case 'M':
                Direccion_Memoria = USART_RxC();
                USART_RxS(11, coordenada_setpoint); //Lectura de las coordenadas
                if (Conexion_perdida == 1) {
                    USART_TxS("E3\n", sizeof ("E3\n") - 1);
                    Conexion_perdida = 0;
                    break;
                } else {
                    USART_TxS("W\n", sizeof ("W\n") - 1);
                    Usart_Interface_OFF('A');
                    Usart_Interface_ON('V');
                    Direccion_Memoria = Seria_Decodificacion_Memoria(Direccion_Memoria);
                    Serial_Escritura_Memoria(Direccion_Memoria, coordenada_setpoint);
                }
                break;
            case 'A'://Movimiento con botones 
                USART_TxS("W\n", sizeof ("W\n") - 1);
                Usart_Interface_OFF('V');
                Usart_Interface_ON('A');
                while (BOTON_OK_GetValue() == 0) {
                    Motor_MovimientoZ();
                }
                USART_TxS("R\n", sizeof ("R\n") - 1);
                Usart_Interface_ON('V');
                Usart_Interface_OFF('A');
                break;
            case 'E':
                USART_TxS("F", sizeof ("F") - 1);
                Usart_Interface_OFF('V');
                Usart_Interface_OFF('A');
                return;
                break;
        }

    }
}

void Serial_DecodificacionX(char string_coordenada[], int *pointerCX) { //Convierte la coordenada en str a int
    char coordenadaX[3];
    for (int i = 0; i < Longitud_Coordenada; i++) {
        coordenadaX[i] = string_coordenada[i];
    }
    for (int i = 0; i < Longitud_Coordenada; i++) {
        if (!(coordenadaX[i] >= 48 && coordenadaX[i] <= 57)) {//En caso de Coordenada ingresada fuera del rango prender banderra y enviar error
            Coordenadas_mal = 1;
        }
    }
    *pointerCX = atoi(coordenadaX); //Cambia el valor de string a una variable int, por lo que se deja el valor de la coordenada x
    return;
}

void Serial_DecodificacionY(char string_coordenada[], int *pointerCY) {//Convierte la coordenada en str a int
    char coordenadaY[3];
    for (int i = 0; i < Longitud_Coordenada; i++) {
        coordenadaY[i] = string_coordenada[4 + i];
    }
    for (int i = 0; i < Longitud_Coordenada; i++) {
        if (!(coordenadaY[i] >= 48 && coordenadaY[i] <= 57)) {//En caso de Coordenada ingresada fuera del rango prender banderra y enviar error
            Coordenadas_mal = 1;
        }
    }
    *pointerCY = atoi(coordenadaY); //Cambia el valor de string a una variable int, por lo que se deja el valor de la coordenada y
    return;
}

/*
void Serial_DecodificacionZ(char string_coordenada[], int *pointerCZ) {//Convierte la coordenada en str a int
    char coordenadaZ[3];
    for (int i = 0; i < 3; i++) {
        coordenadaZ[i] = string_coordenada[8 + i];
    }
    for (int i = 0; i < 3; i++) {
        if (!(coordenadaZ[i] >= 48 && coordenadaZ[i] <= 57)) {//En caso de Coordenada ingresada fuera del rango prender banderra y enviar error
            Coordenadas_mal = 1;
        }
    }
 *pointerCZ = atoi(coordenadaZ); //Cambia el valor de string a una variable int, por lo que se deja el valor de la coordenada y
    return;
}
 */
void Serial_RangosCoordenadas(int C) {//Funcion que checa que las coordenadas se encuentren dentro del rango
    if (C > 300 || C < 0) {//En caso de Coordenada ingresada fuera del rango prender banderra y enviar error
        Coordenadas_fuera = 1;
    }
    return;
}

void Serial_RangosControl(int C) {
    if (C > 170 || C < 139) {//En caso de Coordenada ingresada fuera del rango prender banderra y enviar error
        Coordenadas_control_fuera = 1;
    }
    return;
}

char Seria_Decodificacion_Memoria(char direccion) {
    switch (direccion) {
        case '0':
            direccion = 0x00;
            USART_TxS("C0\n", sizeof ("C0\n") - 1);
            break;
        case '1':
            direccion = 0x10;
            USART_TxS("C1\n", sizeof ("C1\n") - 1);
            break;
        case '2':
            direccion = 0x20;
            USART_TxS("C2\n", sizeof ("C2\n") - 1);
            break;
        case '3':
            direccion = 0x30;
            USART_TxS("C3\n", sizeof ("C3\n") - 1);
            break;
        case '4':
            direccion = 0x40;
            USART_TxS("C4\n", sizeof ("C4\n") - 1);
            break;
        case '5':
            direccion = 0x50;
            USART_TxS("C5\n", sizeof ("C5\n") - 1);
            break;
        case '6':
            direccion = 0x60;
            USART_TxS("C6\n", sizeof ("C6\n") - 1);
            break;
        case '7':
            direccion = 0x70;
            USART_TxS("C7\n", sizeof ("C7\n") - 1);
            break;
        case '8':
            direccion = 0x80;
            USART_TxS("C8\n", sizeof ("C8\n") - 1);
            break;
        case '9':
            direccion = 0x90;
            USART_TxS("C9\n", sizeof ("C9\n") - 1);
            break;
        case 'A':
            direccion = 0xA0;
            USART_TxS("CA\n", sizeof ("CA\n") - 1);
            break;
        case 'B':
            direccion = 0xB0;
            USART_TxS("CB\n", sizeof ("CB\n") - 1);
            break;
        case 'C':
            direccion = 0xC0;
            USART_TxS("CC\n", sizeof ("CC\n") - 1);
            break;
        case 'D':
            direccion = 0xD0;
            USART_TxS("CD\n", sizeof ("CDn") - 1);
            break;
        case 'E':
            direccion = 0xE0;
            USART_TxS("CE\n", sizeof ("CE\n") - 1);
            break;
        case 'F':
            direccion = 0xF0;
            USART_TxS("CF\n", sizeof ("CF\n") - 1);
            break;
    }
    return direccion;
}

void Serial_Lectura_MemoriaX(char direccion, int *pointerCX) {
    char coordenadaX[3];
    char direccionX;
    for (int i = 0; i < Longitud_Coordenada; i++) {
        direccionX = direccion + i;
        coordenadaX[i] = EEPROM_Rx(direccionX); //Guardar datos de le EEPROM en string
    }
    for (int i = 0; i < Longitud_Coordenada; i++) {
        if (!(coordenadaX[i] >= 48 && coordenadaX[i] <= 57)) {//En caso de Coordenada ingresada fuera del rango prender banderra y enviar error
            Coordenadas_mal = 1;
        }
    }
    *pointerCX = atoi(coordenadaX); //Cambia el valor de string a una variable int, por lo que se deja el valor de la coordenada x
    USART_TxS("CX", sizeof ("CX") - 1);
    USART_TxS(coordenadaX, sizeof (coordenadaX));
    Serial_RangosCoordenadas(CoordenadaX);
    return;
}

void Serial_Lectura_MemoriaY(char direccion, int *pointerCY) {
    char coordenadaY[3];
    char direccionY;
    for (int i = 0; i < Longitud_Coordenada; i++) {
        direccionY = direccion + i + 3;
        coordenadaY[i] = EEPROM_Rx(direccionY); //Guardar datos de le EEPROM en string
    }
    for (int i = 0; i < Longitud_Coordenada; i++) {
        if (!(coordenadaY[i] >= 48 && coordenadaY[i] <= 57)) {//En caso de Coordenada ingresada fuera del rango prender banderra y enviar error
            Coordenadas_mal = 1;
        }
    }
    *pointerCY = atoi(coordenadaY); //Cambia el valor de string a una variable int, por lo que se deja el valor de la coordenada x
    USART_TxS("CY", sizeof ("CY") - 1);
    USART_TxS(coordenadaY, sizeof (coordenadaY));
    Serial_RangosCoordenadas(CoordenadaY);
    return;
}

void Serial_Lectura_MemoriaZ(char direccion, int *pointerCZ) {
    char coordenadaZ[3];
    char direccionZ;
    for (int i = 0; i < Longitud_Coordenada; i++) {
        direccionZ = direccion + i + 6;
        coordenadaZ[i] = EEPROM_Rx(direccionZ); //Guardar datos de le EEPROM en string
    }
    for (int i = 0; i < Longitud_Coordenada; i++) {
        if (!(coordenadaZ[i] >= 48 && coordenadaZ[i] <= 57)) {//En caso de Coordenada ingresada fuera del rango prender banderra y enviar error
            Coordenadas_mal = 1;
        }
    }
    *pointerCZ = atoi(coordenadaZ); //Cambia el valor de string a una variable int, por lo que se deja el valor de la coordenada x
    USART_TxS("CZ", sizeof ("CZ") - 1);
    USART_TxS(coordenadaZ, sizeof (coordenadaZ));
    Serial_RangosCoordenadas(CoordenadaZ);
    Serial_RangosControl(CoordenadaZ);
    return;
}

void Serial_Escritura_Memoria(char direccion, char string_setpoint[]) {
    char direccionFinal;
    for (int i = 0; i < Longitud_Coordenada; i++) {
        direccionFinal = direccion + i;
        EEPROM_Tx(direccionFinal, string_setpoint[i]);
    }
    USART_TxS("CXS\n", sizeof ("CXS\n") - 1);
    for (int i = 0; i < Longitud_Coordenada; i++) {
        direccionFinal = direccion + i + 3;
        EEPROM_Tx(direccionFinal, string_setpoint[i + 4]);
    }
    USART_TxS("CYS\n", sizeof ("CYS\n") - 1);
    for (int i = 0; i < Longitud_Coordenada; i++) {
        direccionFinal = direccion + i + 6;
        EEPROM_Tx(direccionFinal, string_setpoint[i + 8]);
    }
    USART_TxS("CZS\n", sizeof ("CZS\n") - 1);
    return;
}

/*
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
    USART_TxS("READ\n", sizeof ("READ\n")-1);
    USART_TxS("COORDINATE X:", sizeof ("COORDINATE X:")-1);
    USART_TxS(coordenadaX, sizeof (coordenadaX));
    USART_TxS("\nCOORDINATE Y:", sizeof ("\nCOORDINATE Y:")-1);
    USART_TxS(coordenadaY, sizeof (coordenadaY));
    USART_TxS("\nCOORDINATE Z:", sizeof ("\nCOORDINATE Z:")-1);
    USART_TxS(coordenadaZ, sizeof (coordenadaZ));
    Serial_RangosCoordenadas(CoordenadaX);
    Serial_RangosCoordenadas(CoordenadaY);
    Serial_RangosCoordenadas(CoordenadaZ);
    return;
}
 
 void Serial_FiltroCaracteres(char C[]) {//Funcion que checa que las coordenadas se encuentren dentro del rango
    for (int i=0;i<3;i++){
    if (!(C[i] >= 48 && C[i] <= 57)) {//En caso de Coordenada ingresada fuera del rango prender banderra y enviar error
        Coordenadas_mal = 1;
    }
    }
    return;
}
 
 */

