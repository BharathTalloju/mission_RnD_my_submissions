#include<stdio.h>
void mult_except_num(int a[50],int b[50],int n);
int i;
void main()
{
    int m,a[50],b[50];
    scanf("%d",&m);
    for(i=0; i<m; i++)
    {
        scanf("%d",&a[i]);
    }
    mult_except_num(a,b,m);
}
void mult_except_num(int a[],int b[],int n)
{
    int l[50],r[50];
    l[0]=a[0];
    for(i=1; i<n; i++)
    {
        l[i]=l[i-1]*a[i];
    }
    r[n-1]=a[n-1];
    for(i=n-2; i>=0; i--)
    {
        r[i]=r[i+1]*a[i];
    }
    for(i=0; i<n; i++)
    {
        if(i==0)
        {
            b[i]=r[i+1];
        }
        else if(i==n-1)
        {
            b[i]=l[i-1];
        }
        else
        {
            b[i]=l[i-1]*r[i+1];
        }
        printf("\nfor %d :%d\n",a[i],b[i]);
    }
}


