#include<lpc21xx.h>
#include "delay.h"
#include "lcd_display.h"
#include "keypad.h"
#include "rfid.h"
#include "GSM.h"
#define m1 1<<6
#define m2 1<<7
#define B1 1<<21
int main()
{
	unsigned char store[14],rx;
	unsigned char rfid[]="600682384C90600682384C9";
	unsigned char pass[5];
	unsigned char org_pass[]="1234";
   LCD_INIT();			   
   UART_INIT();
   UART1_INIT();
   LCD_COMMAND(0x80);
   delay(1000);
   LCD_STRING("SCAN RFID CARD...");
   delay(1000);
   LCD_COMMAND(0x01);
 
   while(1)
   {
    int i=0,count=0;
	for(i=0;i<12;)
	{
		rx=UART_RX();
	   if((rx>='0' && rx<='9')||(rx>='A' && rx<='Z'))
	   {
	   store[i]=rx;
	   	i++;	
		}
	   UART_TX(store[i]);
	}
	   store[12]='\0';
	   UART_STR(store);
	    LCD_COMMAND(0x01);
		UART_TX('\r');
	   UART_TX('\n');
	   if(strstr(rfid,store)!=0)
	   {
	   			LCD_STRING("VALID CARD.....");
				delay(2000);

				LCD_COMMAND(0x01);

				//THE PASSWORD VALID IS TO CHECK PIN IN KEYPAD
				LCD_STRING("4*4 KEYPAD");
				delay(1000);
	 			while(1)
    			{
        			LCD_COMMAND(0x01);
        			LCD_STRING("ENTER PASS");
        			LCD_COMMAND(0xC0);
        			for(i=0;i<4;i++)
					{
    					pass[i] = keyscan() + '0';
    					LCD_DATA('*');
					}
					pass[4] = '\0';
					LCD_COMMAND(0x01);
					if(strcmp(pass, org_pass) == 0)
					{
    					LCD_STRING("PASSWORD CORRECT");
						LCD_COMMAND(0x01);
						delay(1000);

						//MOTOR
						IODIR0=m1|m2;
						while(1)
						{
							IOSET0=m1;
							IOCLR0=m2;
						}
					}
					else
					{
						count++;
    					LCD_STRING("PASSWORD INCORRECT");
						
						if(count==3)
						{
							LCD_COMMAND(0x01);
							LCD_STRING("YOUR SYSTEM IS ");
							LCD_COMMAND(0xc0);
							LCD_STRING("LOCKED....");

							//BUZZER
							IODIR0=B1;
						/*	while(1)
							{
								IOSET0=B1;
								delay(1000);
								IOCLR0=B1;
								delay(1000);
							}*/
							
							//GSM CODE
							GSM();
						//	break;
						}
					}
					delay(2000);
	   			}
		}
	   	else
	   	{
	   		LCD_STRING("INVALID CARD.....");
	   	}
	}
	}


