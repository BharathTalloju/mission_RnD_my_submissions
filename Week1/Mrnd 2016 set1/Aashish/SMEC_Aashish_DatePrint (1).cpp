#include<stdio.h>
//#include<conio.h>
#include<string.h>
#include<stdlib.h>
int toint(char);
int toint2(char[]);
void validation();
void date();
void idle();
void month();
void year();
char *day[] = { "","first","second","third","fourth","fifth","sixth","seventh","eighth","ninth","tenth","eleventh","twelvth","thirteenth","fourteenth","fifteenth","sixteenth","seventeenth","eighteenth","nineteenth" };
char *day2[] = { "","tenth","twenty","thirty","fourty","fifty","sixty","seventy","eighty","ninty" };
char *day3[] = { "zero","one","two","three","four","five","six","seven","eight","nine","ten","eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen"};
char *mnths[] = { "","january","february","march","april","may","june","july","august","september","october","november","december" };
int limits[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
int i = 0, len = 0, buffer_len = 4, temp, temp1, x = 6, y = 7, z = 0;
char ips[11],buffer[4];

void main()
{
	printf("\nEnter Date:");
	gets_s(ips);
	validation();
	_getch();
}
int  toint(char a)
{
	int temp = 0;
	temp = temp * 10 + a - '0';
	return temp;
}
int toint2(char a[])
{
	int temp = 0;
	for (i = 0;a[i] != '\0';i++)
	{
		temp = temp * 10 + a[i] - '0';
	}
	return temp;
}
void validation()
{
	int j = 0;
	for (i = 0;ips[i] != '\0';i++)
	{
		len++;
	}
	if (len > 10)
	{
		printf("\nInput length exceeded");
		idle();
	}
	if ((ips[0] == 0) && (ips[1] == 0))
	{
		printf("\nInvalid date");
		idle();
	}
	else if ((ips[3] == 0) && (ips[4] == 0))
	{
		printf("\nInvalid month");
		idle();
	}
	else
	{
		buffer[0] = ips[0];
		buffer[1] = ips[1];
		temp = toint2(buffer);
		buffer[0] = ips[3];buffer[1] = ips[4];
		temp1 = toint2(buffer);
		if (temp1 > 12)
		{
			printf("\nNumber of months exceeded");
			idle();
		}
		if ((temp == 29) && (temp1 == 2))
		{
			for (i = 6;ips[i] != '\0';i++)
			{
				buffer[j] = ips[i];
				j++;
			}
			temp1 = toint2(buffer);
			if ((temp1 % 4) != 0)
			{
				printf("\nIncorrect Year");
				idle();
				z = 1;
			}
			else if ((temp > 29)&&(z==0))
			{
				printf("\nNumber of days Exceded");
				idle();
			}
			else
			{
				printf("\n-----LEAP YEAR-----");
				date();
			}
		}
	}
	if ((temp > limits[temp1])&&(z==0))
	{
		printf("\nNumber of Days exceeded:");
		idle();
	}
	else
	{
		date();
	}
}
void idle()
{
	printf("\nPlease try again with the  input format==> ab/cd/efgh.\n\tThank you.");
}
void date()
{
	if (z == 0)
	{
		if ((ips[0] != '0') && (ips[1] == '0'))
		{
			buffer[0] = ips[0];buffer[1] = ips[1];
			temp = toint2(buffer);
			printf("\n %s", day2[temp]);

		}
		if ((ips[0] == '0') && (ips[1] != '0'))
		{
			temp = toint(ips[1]);
			printf("\n %s", day[temp]);
			month();
		}
		if ((ips[0] != '0') && (ips[1] != '0'))
		{
			if (ips[0] == ips[1])
			{
				buffer[0] = ips[0];
				buffer[1] = ips[1];
				temp = toint2(buffer);
				printf("\n %s", day[temp]);
				month();
			}
			else if (ips[0] == '1')
			{
				buffer[0] = ips[0];buffer[1] = ips[1];
				temp = toint2(buffer);
				printf("\n %s", day[temp]);
				month();
			}
			else
			{
				temp = toint(ips[0]);
				printf("\n %s", day2[temp]);
				temp = toint(ips[1]);
				printf(" %s", day[temp]);
				month();
			}
		}
	}
}
void month()
{
	if ((ips[3] == '0') && (ips[4] != '0'))
	{
		temp = toint(ips[4]);
		printf(" %s", mnths[temp]);
		year();
	}
	if ((ips[3] != '0'))
	{
		buffer[0] = ips[3];buffer[1] = ips[4];
		temp = toint2(buffer);
		printf(" %s", mnths[temp]);
		year();
	}
}
void year()
{
	int count = 0;
	for (i = 6;ips[i] != '\0';i++)
	{
		if (ips[i] == '0')
		{
			count++;
		}
	}
	if (count == 4)
	{
		idle();
	}
	if ((ips[7] == '0') && (ips[8] == '0'))
	{
		temp = toint(ips[6]);
		printf(" %s thousand", day3[temp]);
		temp = toint(ips[9]);
		printf(" %s", day3[temp]);
		z = 1;

	}
	if (((ips[6] == '0') && (ips[8] == '0')) && ((ips[7] != '0') && (ips[9] != '0')))
	{
		temp = toint(ips[7]);
		printf(" zero %s", day3[temp]);
		temp = toint(ips[9]);
		printf(" zero %s", day3[temp]);
		z = 1;
	}
	if (((ips[6] == '0') && (ips[9] == '0')) && ((ips[7] != '0') && (ips[8] != '0')))
	{
		temp = toint(ips[7]);
		printf(" zero %s", day3[temp]);
		temp = toint(ips[8]);
		printf(" %s zero", day3[temp]);
		z = 1;
	}
	if (((ips[7] == '0') && (ips[9] == '0')) && ((ips[6] != '0') && (ips[8] != '0')))
	{
		temp = toint(ips[6]);
		if (temp == 1)
		{
			printf(" %s", day3[temp]);
		}
		else
		{
			printf(" %s", day2[temp]);
		}
		temp = toint(ips[8]);
		if (temp == 1)
		{
			printf(" %s ", day3[temp]);
		}
		else
		{
			printf(" %s", day2[temp]);
		}
		z = 1;
	}
	x = 6;y = 7;
lable:
	if (z == 1)
	{

	}
	else
	{
		if ((ips[x] == '0') && (ips[y] == '0'))
		{
			printf(" zero zero");
		}
		if ((ips[x] == '0') && (ips[y] != '0'))
		{
			temp = toint(ips[y]);
			printf(" zero %s", day3[temp]);
		}
		if ((ips[x] != '0') && (ips[y] == '0'))
		{
			if (ips[x] == 1)
			{
				buffer[0] = ips[x];
				buffer[1] = ips[y];
				temp = toint2(buffer);
				if (temp == 10)
				{
					printf(" %s", day3[10]);
				}
				printf(" %s", day3[temp]);
				printf("\nerr here");
			}
			else
			{
				temp = toint(ips[x]);
				printf(" %s", day2[temp]);
			}
		}
		if ((ips[x] != '0') && (ips[y] != '0'))
		{
			if (ips[x] == '1')
			{
				buffer[0] = ips[x];buffer[1] = ips[y];
				temp = toint2(buffer);
				printf(" %s", day3[temp]);
			}
			else
			{
				temp = toint(ips[x]);
				printf(" %s", day2[temp]);
				temp = toint(ips[y]);
				printf(" %s", day3[temp]);
			}
		}
		if ((x == 6) && (y == 7))
		{
			x = x + 2;y = y + 2;
			goto lable;
		}
		if ((x > 8) && (y > 9))
		{
			idle();
		}
	}
}
