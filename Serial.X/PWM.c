
#include <xc.h>
#include "configuration.h"
#include "PWM.h"

void PWM_GeneratePulsos(char Oupcode,int pulsosX, int pulsosY) {
    if (Oupcode == 'S') {
        PWM_InitS();
    } else {
        PWM_InitF();
    }
    Enable_DriverX = 0;//Habilita los drivers
    Enable_DriverY = 0; //Habilita los drivers
    T2CONbits.TMR2ON = 1; // Timer ON
    int countX = 0;
    int countY = 0;
    while ((countX < pulsosX) || (countY < pulsosY)) {
        if (countX < pulsosX) {
            if (PORTCbits.RC2 == 1) {
                countX = PWM_OneshotX(countX);
            } else {
                oneshotX = 0;
            }
        } else {
            Enable_DriverX = 1;
        }
        if (countY < pulsosY) {
            if (PORTCbits.RC1 == 1) {
                countY = PWM_OneshotY(countY);
            } else {
                oneshotY = 0;
            }
        } else {
            Enable_DriverY = 1;
        }
    }
    countX = 0;
    oneshotX = 0;
    countY = 0;
    oneshotY = 0;
    T2CONbits.TMR2ON = 0; // Timer OFF
    return;
}

void PWM_InitF() {

    PR2 = 0X7C;
    CCPR1L = 0X3E;
    CCPR2L = 0X3E;
    TRISCbits.RC1 = 0;
    TRISCbits.RC2 = 0;
    T2CON = 0X03; //PREESCALER 16 TIMER 2
    CCP1CON = 0X0C;
    CCP2CON = 0X0C;
    T2CONbits.TMR2ON = 0; // Timer ON
    return;
}

void PWM_InitS() {

    PR2 = 0XFF;
    CCPR1L = 0X3E;
    CCPR2L = 0X3E;
    TRISCbits.RC1 = 0;
    TRISCbits.RC2 = 0;
    T2CON = 0X03; //PREESCALER 16 TIMER 2
    CCP1CON = 0X0C;
    CCP2CON = 0X0C;
    T2CONbits.TMR2ON = 0; // Timer ON
    return;
}

int PWM_OneshotX(int countX) {
    if (PORTCbits.RC2 == 1 & oneshotX == 0) {
        countX++;
        oneshotX = 1;
    }
    return countX;
}

int PWM_OneshotY(int countY) {
    if (PORTCbits.RC1 == 1 & oneshotY == 0) {
        countY++;
        oneshotY = 1;
    }
    return countY;
}


