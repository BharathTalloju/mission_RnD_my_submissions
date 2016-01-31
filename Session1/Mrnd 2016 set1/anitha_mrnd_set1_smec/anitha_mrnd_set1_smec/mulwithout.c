// program to find out multiplication without using * and +

void main()
{
int a,b,c;
printf("enter values for a,b");
scanf("%d%d",&a,&b);
if((a==0)||(b==0))
{
c=0;
}
else
{
while(b!=0)
{
if(b&01)
{
c=c-(-a);
}
a<<2;
b>>1;
}
}
printf("product is :%d",c);
}
