#include<stdio.h>
#include<conio.h>
void bubble_sort(int*, int);
void count_0(int*, int);
void count_1(int*, int);
void sum(int*, int);
int a[1000], n, i, count = 0, temp;
void main()
{
	printf("\nEnter size of Array:");
	scanf_s("%d", &n);
	printf("\nEnter Elements:");
	for (i = 0;i < n;i++)
	{
		scanf_s("%d", &a[i]);
	}
	//bubble_sort(a, n);
	count_0(a, n);
	//count_1(a, n);
	//sum(a, n);
	printf("\nSorted Array");
	for (i = 0;i < n;i++)
	{
		printf("\n%d", a[i]);
	}
	_getch();
}
void bubble_sort(int *p, int n)
{
	int j;
	for (i = 0;i < n;i++)
	{
		for (j = i + 1;j < n;j++)
		{
			if (p[i] > p[j])
			{
				temp = p[i];
				p[i] = p[j];
				p[j] = temp;
			}
		}
	}
}
void count_0(int *p, int n)
{
	
	for (i = 0;i < n;i ++ )
	{
		if (p[i] == 0)
		{
			count++;
		}
	}
	for (i = 0;i < count;i++)
	{
		p[i] = 0;
	}
	for (i = count;i < n;i++)
	{
		p[i] = 1;
	}
	count = 0;
}
void count_1(int *p, int n)
{
	for (i = 0;i < n;i++)
	{
		if (p[i] == 1)
		{
			count++;
		}
	}
	if (count == 0)
	{
		return;
	}
	for (i = n - 1;i >= 0;i--)
	{
		if (count != 0)
		{
			p[i] = 1;
			count--;
		}
		else
		{
			p[i] = 0;
		}
	}
}
void sum(int *p, int n)
{
	int sum = 0;
	for (i = 0;i < n;i++)
	{
		sum = sum + p[i];
	}
	sum = n - sum;
	if (sum == 0)
	{
		return;
	}
	for (i = 0;i < sum;i++)
	{
		p[i] = 0;
	}
	for (i = sum;i < n;i++)
	{
		p[i] = 1;
	}
}