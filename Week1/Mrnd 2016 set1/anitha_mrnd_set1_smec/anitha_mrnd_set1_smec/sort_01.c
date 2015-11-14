// program to sort array with 0s and 1s

void sort1(int a[],int );
void sort2(int a[],int );
void sort3(int a[],int );
void main()
{
int a[100],n,i;
printf("enter elements");
for(i=0;i<n;i++)
scanf("%d",&a[i]);
sort1(a,n);
for(i=0;i<n;i++)
printf("%d",a[i]);
sort2(a,n);
for(i=0;i<n;i++)
printf("%d",a[i]);
sort3(a,n);
for(i=0;i<n;i++)
printf("%d",a[i]);
getch();
}

void sort1(int a[],int n)
{
for(i=0,i<n;i++)
{
if(a[i]==0)
t1++;
}
for(i=0;i<t1:i++)
a[i]=0;
for(i=t1;i<n;i++)
a[i]=1;
return;
}

void sort2(int a[],int n)
{
for(i=0;i<n;i++)
{
if(a[i]==1)
t2++;
}
for(i=n;i<=t2;i--)
a[i]=1;
for(i=t2;i>=0;i--)
a[i]=0;
return;
}
void sort 3(int a[],int n)
{
for(i=0;i<n;i++)
{
if(a[i]>a[i+1])
{
t=a[i];
a[i]=a[j];
a[j]=t;
}
}
return;
}




