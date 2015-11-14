//min rank of the number.
#include<stdio.h>
#include<stdlib.h>
//#include<conio.h>
void visit(int);
int rank(int,int[],int);
int lev=-1,n,val[50],a[50];
void main()
{
    int i,j;
    clrscr();
    printf("Enter how many numbers?\n");
    scanf("%d",&n);
    printf("\nEnter %d numbers:\n\n",n);
    for(i=0;i<n;i++)
    {
        val[i]=0;
        j=i+1;
        scanf("%d\n\n",&a[j]);
    }
    visit(0);
printf("enter the number whose rank is to be found");
scanf("%d",&x);
rank(x,val);
    getch();
}
visit(int k)
{
    int i;
    val[k]=++lev;
    if(lev==n)
    {
        for(i=0;i<n;i++)
        printf("%2d",a[val[i]]);
        printf("        ");
    }
    for(i=0;i<n;i++)
    if(val[i]==0)
    visit(i);
    lev--;
    val[k]=0;

}

int rank(int x,int val[n],int n)
{
for(i=0;i<n;i++)
{
if(val[i]==x)
{
return i;
}
}
