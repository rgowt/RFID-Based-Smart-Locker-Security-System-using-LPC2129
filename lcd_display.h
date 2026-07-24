#include<lpc21xx.h>
#define LCD 0xff<<10
#define RS 1<<18
#define E 1<<19
void LCD_INIT(void);
void LCD_COMMAND(unsigned char);
void LCD_DATA(unsigned char);
void LCD_STRING(unsigned char *);
void delay(int);
void LCD_INIT(void)
{
	IODIR0=LCD|RS|E;
	LCD_COMMAND(0x01);
	LCD_COMMAND(0x02);
	LCD_COMMAND(0x0c);
	LCD_COMMAND(0X38);
}
void LCD_COMMAND(unsigned char d)
{
	IOCLR0=LCD;
	IOSET0=d<<10;
	IOCLR0=RS;
	IOSET0=E;
	delay(2);
	IOCLR0=E;
}

void LCD_DATA(unsigned char d)
{
	IOCLR0=LCD;
	IOSET0=d<<10;
	IOSET0=RS;
	IOSET0=E;
	delay(2);
	IOCLR0=E;
}

void LCD_STRING(unsigned char *s)
{
	while(*s)
	{
		LCD_DATA(*s++);
	}
}


