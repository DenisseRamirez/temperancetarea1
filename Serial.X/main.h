
    
#ifndef EEPROM_H
#define	EEPROM_H

#ifdef	__cplusplus

#endif

void __interrupt(high_priority) INT_isr (void);
void Int_Ext();
char oneshot=0;
void Oneshot();
void maain_interrrupt();
 int cont=0;

#ifdef	__cplusplus

#endif

#endif	
