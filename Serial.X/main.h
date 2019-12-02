
    
#ifndef EEPROM_H
#define	EEPROM_H

#ifdef	__cplusplus

#endif

void __interrupt(high_priority) INT_isr (void);
void Int_Ext();
void Int_Ext(void);
void INT0_ACTION(void);
void INT1_ACTION(void);
void INT2_ACTION(void);
void main_Home();
char home=0;
//char oneshot=0;
//void Oneshot();
//int cont=0;
void maain_interrrupt();

#ifdef	__cplusplus

#endif

#endif	
