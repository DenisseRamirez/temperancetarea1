#ifndef PWM_H
#define	PWM_H

#ifdef	__cplusplus

#endif
char oneshotX=0;
char oneshotY=0;
void PWM_GeneratePulsos(char Oupcode,int pulsosX, int pulsosY);
int PWM_OneshotX ();
int PWM_OneshotY ();
void PWM_InitF();
void PWM_InitS();
#define Enable_DriverX PORTDbits.RD0
#define Enable_DriverY PORTDbits.RD2
#define Direction_DriverX PORTDbits.RD1
#define Direction_DriverY PORTDbits.RD3
#ifdef	__cplusplus
}
#endif

#endif	