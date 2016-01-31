#include<stdio.h>
//#include<conio.h>
int mod(int,int,int);
void main()
{
int x,y,a;

clrscr();
printf("enter the values of x,y,a");
scanf("%d%d%d",&x,&y,&a);
mod(x,y,a);
printf("x^y%a value is %d",mod(x,y,a));
getch();
}

int mod(int x,int y,int a)
{
int i,j,b[10];
int count = 0,prod = 1;
while(y>0)
{
b[i]=y%2;
i++;
count++;
}
for(i=0;i<count;i++)
{
prod=(prod*pow(2,b[i])%a);
}
prod=prod%a;
return prod;
}
