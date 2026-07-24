#include<lpc21xx.h>
void GSM()
{
UART1_INIT();	   
	while(1)
	{
	UART1_STR("at\r\n");
	delay(50);
	UART1_STR("at+cmgf=1\r\n");
	delay(50);	
	UART1_STR("at+cmgs=\"+919629841133\"\r\n");
	delay(2);
	UART1_STR("UNAUTHORISED PERSON ACCESS YOUR LOCKER\r\n");
	delay(50);
	UART1_TX(0x1A);
	while(1);	
	}
}