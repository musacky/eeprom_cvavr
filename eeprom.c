/*****************************************************
This program was produced by the
CodeWizardAVR V2.05.6 Evaluation
Automatic Program Generator
© Copyright 1998-2012 Pavel Haiduc, HP InfoTech s.r.l.
http://www.hpinfotech.com

Project : 
Version : 
Date    : 20/04/2013
Author  : Freeware, for evaluation andnon-commercial use only
Company : 
Comments: 


Chip type               : ATmega16
Program type            : Application
AVR Core Clock frequency: 12,000000 MHz
Memory model            : Small
External RAM size       : 0
Data Stack size         : 256
*****************************************************/

#include <mega16.h>
#include <delay.h>
#include <stdlib.h>

int eeprom*pointer_eeprom;
int data;
char temp[16];
// Alphanumeric LCD Module functions
#asm
.equ __lcd_port=0x15 ;PORTC
#endasm


void tulis_data_ke_eeprom()
{
*pointer_eeprom=data;
}
void baca_data_ke_eeprom()
{
data=*pointer_eeprom;
}




// Alphanumeric LCD functions
#include <alcd.h>
void tampil_lcd()
{
lcd_gotoxy(0,0);
lcd_putsf("ElectrO-cOntrOl");
itoa(data,temp);
lcd_gotoxy(0,1);
lcd_puts(temp);
}

// Declare your global variables here

void main(void)

{

// Declare your local variables here

// Input/Output Ports initialization
// Port A initialization
// Func7=In Func6=In Func5=In Func4=In Func3=In Func2=In Func1=In Func0=In 
// State7=T State6=T State5=T State4=T State3=T State2=T State1=T State0=T 
PORTA=0x00;
DDRA=0x00;

// Port B initialization
// Func7=In Func6=In Func5=In Func4=In Func3=In Func2=In Func1=In Func0=In 
// State7=T State6=T State5=T State4=T State3=T State2=T State1=T State0=T 
PORTB=0x1f;
DDRB=0x00;

// Port C initialization
// Func7=In Func6=In Func5=In Func4=In Func3=In Func2=In Func1=In Func0=In 
// State7=T State6=T State5=T State4=T State3=T State2=T State1=T State0=T 
PORTC=0x00;
DDRC=0x00;

// Port D initialization
// Func7=In Func6=In Func5=In Func4=In Func3=In Func2=In Func1=In Func0=In 
// State7=T State6=T State5=T State4=T State3=T State2=T State1=T State0=T 
PORTD=0xff;
DDRD=0x00;

// Timer/Counter 0 initialization
// Clock source: System Clock
// Clock value: Timer 0 Stopped
// Mode: Normal top=0xFF
// OC0 output: Disconnected
TCCR0=0x00;
TCNT0=0x00;
OCR0=0x00;

// Timer/Counter 1 initialization
// Clock source: System Clock
// Clock value: Timer1 Stopped
// Mode: Normal top=0xFFFF
// OC1A output: Discon.
// OC1B output: Discon.
// Noise Canceler: Off
// Input Capture on Falling Edge
// Timer1 Overflow Interrupt: Off
// Input Capture Interrupt: Off
// Compare A Match Interrupt: Off
// Compare B Match Interrupt: Off
TCCR1A=0x00;
TCCR1B=0x00;
TCNT1H=0x00;
TCNT1L=0x00;
ICR1H=0x00;
ICR1L=0x00;
OCR1AH=0x00;
OCR1AL=0x00;
OCR1BH=0x00;
OCR1BL=0x00;

// Timer/Counter 2 initialization
// Clock source: System Clock
// Clock value: Timer2 Stopped
// Mode: Normal top=0xFF
// OC2 output: Disconnected
ASSR=0x00;
TCCR2=0x00;
TCNT2=0x00;
OCR2=0x00;

// External Interrupt(s) initialization
// INT0: Off
// INT1: Off
// INT2: Off
MCUCR=0x00;
MCUCSR=0x00;

// Timer(s)/Counter(s) Interrupt(s) initialization
TIMSK=0x00;

// USART initialization
// USART disabled
UCSRB=0x00;

// Analog Comparator initialization
// Analog Comparator: Off
// Analog Comparator Input Capture by Timer/Counter 1: Off
ACSR=0x80;
SFIOR=0x00;

// ADC initialization
// ADC disabled
ADCSRA=0x00;

// SPI initialization
// SPI disabled
SPCR=0x00;

// TWI initialization
// TWI disabled
TWCR=0x00;

// Alphanumeric LCD initialization
// Connections are specified in the
// Project|Configure|C Compiler|Libraries|Alphanumeric LCD menu:
// RS - PORTC Bit 0
// RD - PORTC Bit 1
// EN - PORTC Bit 2
// D4 - PORTC Bit 4
// D5 - PORTC Bit 5
// D6 - PORTC Bit 6
// D7 - PORTC Bit 7
// Characters/line: 16
lcd_init(16);
pointer_eeprom=0;//alamat eeprom yg akan ditulis/dibaca
baca_data_ke_eeprom();//memanggil fungsi baca eeprom

while (1)
      {
if (PIND.0==0)//jika ditekan maka akan menulis data=0 ke EEPROM
{
data=0;
lcd_clear();
delay_ms(300);
tulis_data_ke_eeprom();
} 

if (PIND.1==0)//jika ditekan maka akan menulis data=1 ke EEPROM
{
data=1;
delay_ms(300);
lcd_clear();
tulis_data_ke_eeprom();
} 

if (PIND.2==0)//jika ditekan maka akan menulis data=2 ke EEPROM
{
data=2;
delay_ms(300);
lcd_clear();
tulis_data_ke_eeprom();
}

if (PIND.3==0)//jika ditekan maka akan menulis data=3 ke EEPROM
{
data=3;
delay_ms(300);
lcd_clear();
tulis_data_ke_eeprom();
}

if (PIND.4==0)//jika ditekan maka akan menulis data=4 ke EEPROM
{
data=4;
delay_ms(300);
lcd_clear();
tulis_data_ke_eeprom();
}

tampil_lcd();//menampilkan data ke LCD
};
}
