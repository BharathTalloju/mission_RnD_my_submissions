//product of the n-1 array elements in the nth array index
#include<stdio.h>
//#include<conio.h>
void mul1(int,int[]);
void mul2(int,int[]);
void mul3(int,int[]);

void main()
{
{
int n,a[100];
printf("enter the size of array");
scanf("%d",&n);
printf("enter the array elements");
for(i=0;i<n;i++)
{
scanf("%d",&a[i]);
}
mul1(n,a);
//mul2(n,a);
//mul3(n,a);

for(i=0;i<n;i++)
{
printf("%d",a[i]);
}
}

void mul1(int n,int a[n])
{
int i,j,b[100];
for(i=0;i<n;i++)
for(j=0;j<n;j++)
if(i!=j)
b[i]*=a[j];
}

void mul2(int n,int a[n])
{
int b[n], prod_above[n],prod_below[n];
p=1;
for(int i=0;i<n;i++)
{
prod_below[i]=p;
p*=a[i];
}
for(int i=n-1;i>0;--i)
{
prod_above[i]=p;
p*=a[i];
}
for(i=0;i<n;i++)
{
b[i]=prod_above[i]*prod_below[i];
}
}

void mul3(int n,int a[n])
{
int i=0,b[n];
p=1;
for(i=0;i<n;i++)
{
b[i]=p;
p*=a[i];
}
p=1;
for(i=n;i>0;i--)
{
b[i]*=p;
p*=a[i];
}
}

