#include<stdio.h>
void main()
{
    int x,y,a,b,c,i,j,k,l,t,p[50];
    scanf("%d",&x);
    scanf("%d",&y);
    scanf("%d",&a);
    i=0;
    while(y!=0)
    {
        p[i]=y%2;
        y=y/2;
        i++;
    }
    k=i;
    l=i;
    if(p[0]!=0)
    {
        p[0]=1;
    }
    for(i=1; i<k; i++)
    {
        if(p[i]!=0)
        {
            for(j=1; j<k; j++)
            {
                p[i]=2*j*p[i];
            }
        }
    }
    c=1;
    for(i=0; i<k; i++)
    {
        t=1;
        if(p[i]!=0)
        {
        for(j=0; j<l; j++)
        {
            t=(x*t);
        }
        l--;
        }
        b=(t%a);
        c=(c*b)%a;
    }
    printf("\nc=%d",c);

}
