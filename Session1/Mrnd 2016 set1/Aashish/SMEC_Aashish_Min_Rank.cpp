#include <stdio.h>
#include<conio.h>
int fact(int);
int min_rank(int[], int);
void main()
{
	int a[10], i, n, rank;
	printf("\nenter size:");
	scanf_s("%d", &n);
	printf("\nenter elements:");
	for (i = 0;i < n;i++)
	{
		scanf_s("%d", &a[i]);
	}
	rank = min_rank(a, n);
	printf("\nRank : %d", rank);
	_getch();
}
int min_rank(int a[],int n)
{
	int i, j, k, m, sum, count;
	k = 1;m = 1;sum = 0;
	for (i = 0;i<n;i++)
	{
		if (i == n - 1)
		{
			sum = sum + 0;
			break;
		}

		else
		{
			count = 0;
			for (j = m;j<n;j++)
			{
				if (a[i]>a[j])
				{
					count++;
				}
			}
			

			sum = sum + (count*(fact(n - k)));
			k++;
			m++;
			
		}

	}
	
	return sum;
}

int fact(int a)
{
	int res = 1, i;
	if (a == 0)
	{
		return 1;
	}
	else
	{
		for (i = a;i>0;i--)
		{
			res = res*i;
		}
		
		return res;
	}
}