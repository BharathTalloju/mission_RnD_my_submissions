#include<stdio.h>
#include<conio.h>
unsigned int modulo(unsigned int, unsigned int, unsigned int);
void main()
{
	unsigned int x, y, a;
	printf("\nEnter Values of x,y,a:");
	scanf_s("%d%d%d", &x,&y,&a);
	_getch();
}
unsigned int modulo(unsigned int x, unsigned int y, unsigned int a)
{
	unsigned int b[64], t[64], i, j = 0, m = 0, res = 1, n, p = 0;
	if (y == 0)
	{
		return 1;
	}
	else if (y == 1)
	{
		return x % a;
	}
	else
	{
		n = y;
		for (i = 0;n != 0;i++)
		{
			b[i] = n%a;
			n = n / a;
			m++;
		}
		t[0] = x%a;
		for (i = 1;j <= y;i++)
		{
			t[i] = (t[i - 1] * t[i - 1]) % a;
			j = 2 * j;
			p++;
		}
		for (i = 0;i < p;i++)
		{
			printf("\n%d-", t[i]);
		}
		for (i = 0;i < m;i++)
		{
			if (b[i] == 1)
			{
				res = res*t[i];
			}
		}
		return res;
	}
}


