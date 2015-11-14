#include<stdio.h>
void main()
{
    int x,y,i=0,k;
    int b[50],c,d;
    scanf("%d",&x);
    scanf("%d",&y);
    while(y!=0)
    {
        b[i]=y%2;
        y=y/2;
        i++;
    }
    k=i;
    d=0;
    for(i=0; i<k; i++)
    {
        c=0;
        if(b[i]!=0)
        {
            c=(c|x);
        }
        else
        {
        }
        d=c-(-d);
        x=x<<1;
    }
    printf("\nres=%d",d);
}
