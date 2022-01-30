#include<pic.h>
#include<htc.h>
#define _XTAL_FREQ 20e6
__CONFIG(0X3F3A);

#define RS RC0
#define EN RC1

#define ON 1
#define OFF 0

void Lcd_Command(char cmd)
{
	RS = OFF;
	EN = ON;
	PORTB = cmd;
	__delay_ms(5);
	EN = OFF;
}

void Lcd_Data(char Data)
{
	RS = ON;
	EN = ON;
	PORTB = Data;
	__delay_ms(5);
	EN = OFF;
}

void Lcd_String(const unsigned char *Str)
{
	while(Str != 0)
	{
		Lcd_Data(*Str++);
	}	
}

void Lcd_Intialization()
{
	Lcd_Command(0x06);
	Lcd_Command(0x38);
	Lcd_Command(0x0c);
}

void main()
{
	TRISB=0X00;
	PORTB=0X00;
	TRISC=0X00;
	PORTC=0X00;
	
	Lcd_Intialization();
	
	while(1)
	{
		Lcd_Command(0x80);
		Lcd_String("LYCO SOFT");
	}
}