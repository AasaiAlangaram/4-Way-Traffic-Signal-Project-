#include<pic.h>

//LCD PIN Connection
#define rs RE0
#define rw RE1
#define en RE2

//Signal1 LED
#define S1G RB0
#define S1Y RB1
#define S1R RB2

//Signal2 LED
#define S2G RB3
#define S2Y RB4
#define S2R RB5

//Signal3 LED
#define S3G RB6
#define S3Y RB7
#define S3R RC0

//Signal4 LED
#define S4G RC1
#define S4Y RC2
#define S4R RC3

unsigned int j,g=0,o=10,a,b;

//Delay function
void del(unsigned int y)
{
while(y--);
}

//Function to send LCD Command
void lcd_command(unsigned char com)
{
PORTD=com;
rs=0;
rw=0;
en=1;
del(125);
en=0;
}

//Function to send LCD Data
void lcd_data(unsigned char dat)
{
PORTD=dat;
rs=1;
rw=0;
en=1;
del(125);
en=0;
}
void lcd_init()
{
lcd_command(0X38);
lcd_command(0X06);
lcd_command(0X0c);
lcd_command(0X01);
}
void lcd_disply(const unsigned char *da)
{
unsigned int i;
for(i=0;da[i]!=0;i++)
{
del(1000);
lcd_data(da[i]);
}
}
void delay1()
{
for(j=0;j<110;j++)
{
TMR1L=0X2B;
TMR1H=0XCF;
T1CKPS0=1;
T1CKPS1=1;
TMR1CS=0;
TMR1ON=1;
while(TMR1IF==0);
TMR1IF=0;
TMR1ON=0;
g=g+1;
if(g==10)
{
g=0;
a=o/10;
b=o%10;
o=o-1;
lcd_command(0X85);
lcd_data(a+0X30);
lcd_data(b+0X30);
}
}
o=10;
}
void delay2()
{
for(j=0;j<110;j++)
{
TMR1L=0X2B;
TMR1H=0XCF;
T1CKPS0=1;
T1CKPS1=1;
TMR1CS=0;
TMR1ON=1;
while(TMR1IF==0);
TMR1IF=0;
TMR1ON=0;
g=g+1;
if(g==10)
{
g=0;
a=o/10;
b=o%10;
o=o-1;
lcd_command(0X8d);
lcd_data(a+0X30);
lcd_data(b+0X30);
}
}
o=10;
}
void delay3()
{
for(j=0;j<110;j++)
{
TMR1L=0X2B;
TMR1H=0XCF;
T1CKPS0=1;
T1CKPS1=1;
TMR1CS=0;
TMR1ON=1;
while(TMR1IF==0);
TMR1IF=0;
TMR1ON=0;
g=g+1;
if(g==10)
{
g=0;
a=o/10;
b=o%10;
o=o-1;
lcd_command(0Xc5);
lcd_data(a+0X30);
lcd_data(b+0X30);
}
}
o=10;
}
void delay4()
{
for(j=0;j<110;j++)
{
TMR1L=0X2B;
TMR1H=0XCF;
T1CKPS0=1;
T1CKPS1=1;
TMR1CS=0;
TMR1ON=1;
while(TMR1IF==0);
TMR1IF=0;
TMR1ON=0;
g=g+1;
if(g==10)
{
g=0;
a=o/10;
b=o%10;
o=o-1;
lcd_command(0Xcd);
lcd_data(a+0X30);
lcd_data(b+0X30);
}
}
o=10;
}
void delay5()
{
for(j=0;j<30;j++)
{
TMR1L=0X2B;
TMR1H=0XCF;
T1CKPS0=1;
T1CKPS1=1;
TMR1CS=0;
TMR1ON=1;
while(TMR1IF==0);
TMR1IF=0;
TMR1ON=0;
}
}
void main()
{
ADCON1=0X06;
TRISE=0X00;
TRISD=0X00;
PORTE=PORTD=0X00;
TRISB=0X00;
PORTB=0X00;
TRISC=0X00;
PORTC=0X00;
lcd_init();
lcd_command(0X80);
lcd_disply("SIG1:   SIG2:   ");
lcd_command(0XC0);
lcd_disply("SIG3:   SIG4:   ");
while(1)
{
S1G=1;
S2R=S3R=S4R=1;
delay1();
S1G=0;S1Y=1;
delay5();
S1Y=0;

S2G=1;S2R=0;
S1R=S3R=S4R=1;
delay2();
S2G=0;S2Y=1;
delay5();
S2Y=0;

S3G=1;S3R=0;
S1R=S2R=S4R=1;
delay3();
S3G=0;S3Y=1;
delay5();
S3Y=0;

S4G=1;S4R=0;
S1R=S3R=S2R=1;
delay4();
S4G=0;S4Y=1;
delay5();
S4Y=0;
}
}
