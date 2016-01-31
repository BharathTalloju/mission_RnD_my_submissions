#include<stdio.h>
#include<conio.h>
int* product_using_division(int[], int);
int* product_using_four_arrays(int[], int n);
int* product_using_three_arrays(int[], int n);
int* product_using_two_arrays(int[], int n);
void main()
{
	int a[100], i, n;
	int *p;
	printf("\nEnter Size of Array:");
	scanf_s("%d", &n);
	printf("\nEnter elements:");
	for (i = 0;i < n;i++)
	{
		scanf_s("%d", &a[i]);
	}
	p=product_using_division(a, n);
	/*p=product_using_four_arrays(a,n);*/
	/*p=product_using_three_arrays(a,n);*/
	/*p = product_using_two_arrays(a, n);*/
	printf("\nResultant Array:");
	for (i = 0;i < n;i++)
	{
		printf("%d-", p[i]);
	}
	_getch();
}
int* product_using_four_arrays(int a[], int n)
{
	int lma[100], rma[100], i;
	static int b[100];
	for (i = 0;i < n;i++)
	{
		if (i == 0)
		{
			lma[i] = a[i];
		}
		else
		{
			lma[i] = lma[i - 1] * a[i];
		}
	}
	for (i = n - 1;i >= 0;i--)
	{
		if (i == n - 1)
		{
			rma[i] = a[i];
		}
		else
		{
			rma[i] = rma[i + 1] * a[i];
		}
	}
	for (i = 0;i < n;i++)
	{
		if (i == 0)
		{
			b[i] = rma[i + 1];
		}
		else if (i + 1 >= n)
		{
			b[i] = lma[i - 1];
		}
		else
		{
			b[i] = lma[i - 1] * rma[i + 1];
		}

	}
	return b;
}
int* product_using_division(int a[], int n)
{
	int i, res = 1;
	for (i = 0;i<n;i++)
	{
		res = res*a[i];
	}
	for (i = 0;i<n;i++)
	{
		a[i] = res / a[i];
	}
	return a;
}

int* product_using_three_arrays(int a[], int n)
{
	int lma[100], i;
	static int rma[100];
	for (i = 0;i<n;i++)
	{
		if (i == 0)
			lma[i] = a[i];
		else
			lma[i] = lma[i - 1] * a[i];

	}
	for (i = n - 1;i >= 0;i--)
	{
		if (i == n - 1)
			rma[i] = a[i];
		else
			rma[i] = rma[i + 1] * a[i];
	}

	for (i = 0;i<n;i++)
	{
		if (i == 0)
		{
			rma[i] = rma[i + 1];
		}
		else if (i + 1 >= n)
		{
			rma[i] = lma[i - 1];
		}
		else
		{
			rma[i] = lma[i - 1] * rma[i + 1];
		}
	}
	return rma;

}

int* product_using_two_arrays(int a[], int n)
{
	int lma[10], i, j;
	for (i = 0;i<n;i++)
	{
		if (i == 0)
		{
			lma[i] = a[i];
		}
		else
		{
			lma[i] = lma[i - 1] * a[i];
		}

	}
	for (i = n - 1;i >= 0;i--)
	{
		if (i == n - 1)
		{
			;
		}
		else
		{
			a[i] = a[i + 1] * a[i];
		}
	}
	for (i = 0;i<n;i++)
	{
		if (i == 0)
		{
			a[i] = a[i + 1];
		}
		else if (i + 1 >= n)
		{
			a[i] = lma[i - 1];
		}
		else
		{
			a[i] = lma[i - 1] * a[i + 1];
		}
	}
	return a;

}



