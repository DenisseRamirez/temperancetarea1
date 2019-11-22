
#include <xc.h>
#include "configuration.h"
#include "PWM.h"

void PWM_GeneratePulsos(char Oupcode,int pulsosX, int pulsosY) {
    if (Oupcode == 'S') {
        PWM_InitS();
    } else {
        PWM_InitF();
    }
    Enable_DriverX = 0;
    Enable_DriverY = 0;
    T2CONbits.TMR2ON = 1; // Timer ON
    int pasosX = 0;
    int pasosY = 0;
    while (pasosX < pulsosX && pasosY < pulsosY) {
        if (pasosX < pulsosX) {
            if (PORTCbits.RC2 == 1) {
                pasosX = PWM_OneshotX(pasosX);
            } else {
                oneshotX = 0;
            }
        } else {
            Enable_DriverX = 1;
        }
        if (pasosY < pulsosY) {
            if (PORTCbits.RC1 == 1) {
                pasosY = PWM_OneshotY(pasosY);
            } else {
                oneshotY = 0;
            }
        } else {
            Enable_DriverY = 1;
        }
    }
    pasosX = 0;
    oneshotX = 0;
    pasosY = 0;
    oneshotY = 0;
    T2CONbits.TMR2ON = 0; // Timer OFF
}

void PWM_InitF() {

    PR2 = 0X7C;
    CCPR1L = 0X3E;
    CCPR2L = 0X3E;
    TRISCbits.RC1 = 0;
    TRISCbits.RC0 = 0;
    TRISCbits.RC2 = 0;
    T2CON = 0X03; //PREESCALER 16 TIMER 2
    CCP1CON = 0X0C;
    CCP2CON = 0X0C;
    T2CONbits.TMR2ON = 0; // Timer ON
    Enable_DriverX = 1;
    Enable_DriverY = 1;
}

void PWM_InitS() {

    PR2 = 0XFF;
    CCPR1L = 0X3E;
    CCPR2L = 0X3E;
    TRISCbits.RC1 = 0;
    TRISCbits.RC0 = 0;
    TRISCbits.RC2 = 0;
    T2CON = 0X03; //PREESCALER 16 TIMER 2
    CCP1CON = 0X0C;
    CCP2CON = 0X0C;
    T2CONbits.TMR2ON = 0; // Timer ON
    Enable_DriverX = 1;
    Enable_DriverY = 1;
}

int PWM_OneshotX(int pasosX) {
    if (PORTCbits.RC2 == 1 & oneshotX == 0) {
        pasosX++;
        oneshotX = 1;
    }
    return pasosX;
}

int PWM_OneshotY(int pasosY) {
    if (PORTCbits.RC1 == 1 & oneshotY == 0) {
        pasosY++;
        oneshotY = 1;
    }
    return pasosY;
}


