#include<lpc21xx.h>
#include<string.h>
//#define rf 1<<0
void UART_INIT(void);
void UART_TX(unsigned char);
unsigned char UART_RX(void);
void UART_STR(unsigned char *);
void UART1_INIT(void);
void UART1_TX(unsigned char);
unsigned char UART1_RX(void);
void UART1_STR(unsigned char *);

 
 void UART_INIT(void)
   {
   	PINSEL0=0x5;
	U0LCR=0x83;
	U0DLL=97;
	U0DLM=0;
	U0LCR=0x03;
   }
   void UART_TX(unsigned char tx)
   {
   	U0THR=tx;
	while(((U0LSR>>5)&1)==0);
   }
   unsigned char UART_RX(void)
   {
   	while((U0LSR&1)==0);
	return U0RBR;
   }
   void UART_STR(unsigned char *s)
   {
   	while(*s)
	{
		//delay(500);
	    
	    UART_TX(*s++);
	}
   }
  void UART1_INIT(void)
   {
   	PINSEL0|=0x00050000;
	U1LCR=0x83;
	U1DLL=97;
	U1DLM=0;
	U1LCR=0x03;
   }
   void UART1_TX(unsigned char tx)
   {
   	U1THR=tx;
	while(((U1LSR>>5)&1)==0);
   }
   unsigned char UART1_RX(void)
   {
   	while((U1LSR&1)==0);
	return U1RBR;
   }
   void UART1_STR(unsigned char *s)
   {
   	while(*s)
	{
		//delay(500);
	    
	    UART1_TX(*s++);
	}
   }
   

