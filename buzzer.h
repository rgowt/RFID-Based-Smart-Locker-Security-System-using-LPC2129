#include<lpc21xx.h>
#define B 1<<21
void buzzer()
{
	IODIR0=B;
	while(1)
	{
		IOSET0=B;
		delay(1000);
		IOCLR0=B;
		delay(1000);
		}
}