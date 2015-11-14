//date 1/12/1992 to print first december ninteen ninety two
#include<stdio.h>
//#include<conio.h>
void main()
{
int dd,mm,yyyy;
int a,w,z;
clrscr();
printf("enter the date in the format ddmmyyyy ");
scanf("%d%d%d",&dd,&mm,&yyyy);
if(dd==1)
printf("first");
else if(dd==2)
printf("second");
else if(dd==3)
printf("third");
else if(dd==4)
printf("fourt");
else if(dd==5)
printf("fifth");
else if(dd==6)
printf("sixth");
else if(dd==7)
printf("seventh");
else if(dd==8)
printf("eight");
else if(dd==9)
printf("ninth");
else if(dd==10)
printf("tenth");
else if(dd==11)
printf("eleventh");
else if(dd==12)
printf("twelvth");
else if(dd==13)
printf("thirteenth");
else if(dd==14)
printf("fourteenth");
else if(dd=15)
printf("fifteenth");
else if(dd==16)
printf("sixteenth");
else if(dd==17)
printf("seventeenth");
else if(dd==18)
printf("eighteenth");
else if(dd==19)
printf("nineteenth");
else if(dd==20)
printf("twentyth");
else if(dd==21)
printf("twenty first");
else if(dd==22)
printf("twenty second");
else if(dd==23)
printf("twenty third");
else if(dd==24)
printf("twenty fourth");
else if(dd==25)
printf("twenty fifth");
else if(dd==26)
printf("twenty sixth");
else if(dd==27)
printf("twenty seventh");
else if(dd==28)
printf("twenty eighth");
else if(dd==29)
printf("twenty ninth");
else if(dd==30)
printf("thirtyth");
else if(dd==31)
printf("thirty first");
else
printf("invalid date");

if(mm==1)
printf("january");
if(mm==2)
printf("febraury");
if(mm==3)
printf("march");
if(mm==4)
printf("april");
if(mm==5)
printf("may");
if(mm==6)
printf("june");
if(mm==7)
printf("july");
if(mm==8)
printf("august");
if(mm==9)
printf("september");
if(mm==10)
printf("october");
if(mm==11)
printf("november");
if(mm==12)
printf("december");
else
printf("invalid month");

a=yyyy/100;
w=yyyy%100;
if(a==11||w==11)
printf("eleven");

if(a==12||w==12)
printf("twelve");
if(a==13||w==13)
printf("thirteen");
if(a==14||w==14)
printf("fourteen");
if(a==15||w==15)
printf("fifteen");
if(a==16||w==16)
printf("sixteen");
if(a==17||w==17)
printf("seventeen");
if(a==18||w==18)
printf("eighteen");
if(a==19||w==19)
printf("ninteen");
if(a==20 && a<30)
printf("two thousand");
if(a==30 && a<40)
printf("four thousand");
if(a==40 && a<50)
printf("five thousand");
if(a==50 && a<60)
printf("six thousand");
if(a==60 && a<70)
printf("7 thousand");
if(a==70 && a<80)
printf("8 thousand");
if(a==80 &&a<90)
printf("8 thousand");
if(a==90 && a<100)
printf("9 thousand");



else
printf("invalid");
x=a/10;
w=yyyy%100
if(a==1||w==1)
printf("one");
if(a==2||w==2)
printf("two");
if(a==3||w==3)
printf("three");
if(a==4 ||w==4)
printf("four");
if(a==5|| w==5)
printf("five");
if(a==6||w==6)
printf("six");
if(a==7 || w==7)
printf("seven");
if(a==8||w==8)
printf("eight");
if(a==9 || w==9)
printf("nine");

 getch();
}
