#ifndef PWM_H
#define	PWM_H

#ifdef	__cplusplus

#endif
char oneshotX=0;
char oneshotY=0;
int pulsosX=0;
int pulsosY=0;
void PWM_GeneratePulsos(int pulsosX,int pulsosY);
int PWM_OneshotX ();
int PWM_OneshotY ();
void PWM_InitF();
void PWM_InitS();
#define Enable_DriverX PORTCbits.RC0
#define Enable_DriverY PORTCbits.RC4
#ifdef	__cplusplus
}
#endif

#endif	