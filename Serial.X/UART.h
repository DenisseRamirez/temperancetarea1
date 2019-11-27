#ifndef UART_H
#define	UART_H

#ifdef	__cplusplus
extern "C" {
#endif

void USART_Init(long BAUD);
void USART_TxC(char data);
char USART_RxC();
void USARTStr(char *Output, unsigned int size);
void USART_TxSP(char Str[]);
void USART_RxS (char lenght, char* pointer );
char USART_TxS(char str[]);

#ifdef	__cplusplus
}
#endif

#endif	/* USART_H */