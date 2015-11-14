//compute the value of a*b without multiplication or addition.use bitwise operartors

#include<stdio.h>
main()
{
int a,b,result;
printf("nEnter the numbers to be multiplied :");
scanf("%d%d",&a,&b);
while(b != 0)
{
if (b&01)
{
printf("Adding %d and %d",result,a);
result=result+a;
}
a<<=1;
b>>=1;
}
printf("nResult:%d",result);
}
