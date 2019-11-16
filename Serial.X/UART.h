#ifndef USART_H
#define	USART_H

#ifdef	__cplusplus
extern "C" {
#endif

void USART_Init(long BAUD);
void USART_Tx(char data);
char USART_Rx();
void USARTStr(char *Output, unsigned int size);
void USART_SPrint(char Str[]);
char Coordenada (char lenght);

#ifdef	__cplusplus
}
#endif

#endif	/* USART_H */