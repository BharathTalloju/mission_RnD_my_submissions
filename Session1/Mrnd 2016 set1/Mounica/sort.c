//sorting the array of 0's and 1's
#include<stdio.h>
//#include<conio.h>
#include<stdlib.h>

void sort1(int,int[]);

int main()
{
int a[100],n,i;
clrscr();
printf("enter the size");
scanf("%d",&n);
printf("enter values into array");
for(i=0;i<n;i++)
{
scanf("%d",&a[i]);
}
sort1(n,a);
//sort2(n,a);
//sort3(n,a);

for(i=0;i<n;i++)
{
printf("%d",a[i]);
}
}

void sort1(int n,int a[n])
{
int i,count=0;
for(i=0;i<n;i++)
{
if(a[i]==0)
{
count++;
}
}
for(i=0;i<n;i++)
{
a[i]=0;
}
for(i=count+1;i<n;i++)
{
a[i]=1;
}
}

void sort2(int n,int a[n])
{
int i=0,j=n-1;
while(i<=j)
{
if(a[i]==0)
{
if(a[i]==0)
i++;
if(a[j]==0)
j--;
if(a[i]==1 && a[j]==0)
{
a[i++]=0;
a[j--]==1;
}
}

void sort3(int n,int a[n])
{
int i,count=0;
for(i=0;i<n;i++)
{
if(a[i]==1)
{
count++;
a[i]=0;
}
}
for(i=0;i<count;i++)
{
a[i]=1;
}
}

void sort4(int n,int a[n])
{
l=0,r=n-1,temp;
while(l<r)
{
if(a[l]==0)
l++;
else(a[r]==1)
r--;
else
{
temp=a[l];
a[l]=a[r];
a[r]=temp;
l++;
r--;
}
}
}
