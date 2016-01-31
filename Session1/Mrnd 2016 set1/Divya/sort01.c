//sorting  array without using sorting array
#include<stdio.h>
void main()
{
int a[50],n,i,j,k,h;
scanf("%d",&n);
for(i=0;i<n;i++)
{
scanf("%d",&a[i]);
}
a[k]=0;
for(i=0;i<n;i++)
{
a[k]=a[k]+a[i];
}
j=a[k];
h=n-j;
printf("sorted  array is :");
for(i=0;i<h;i++)
{
printf("0");
}
for(i=0;i<j;i++)
{
printf("1");
}
}
