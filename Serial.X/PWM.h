#ifndef PWM_H
#define	PWM_H

#ifdef	__cplusplus

#endif
char oneshotX=0;
char oneshotY=0;
char BanderaX=0;
char BanderaY=0;
void PWM_GeneratePulsos(char Oupcode,int pulsosX, int pulsosY);
//void PWM_Pulsos_Home(char banderaX, char banderaY);
int PWM_OneshotX(int countX);
int PWM_OneshotY(int countY);
void PWM_InitF(void);
void PWM_InitS(void);
//#define ENABLE_X PORTDbits.RD0
//#define ENABLE_Y PORTDbits.RD2
//#define DIRECCION_X PORTDbits.RD1
//#define DIRECCION_Y PORTDbits.RD3
#ifdef	__cplusplus
}
#endif

#endif	