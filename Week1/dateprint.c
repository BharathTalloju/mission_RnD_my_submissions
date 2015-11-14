#include <stdio.h>
#include <stdlib.h>

void day_string(int);
void month_string(int);
void sub_string(int);
void year_string(int);

int main(){
	int day,month,year;

	scanf("%d/%d/%d",&day,&month,&year);

	day_string(day);
	printf(" ");
	month_string(month);
	printf(" of ");
	year_string(year);
	printf("\n");

}

void day_string(int day){

	if(day>32 || day<0){
		printf("Invalid day");
		return;
	}
	if((day-9) <= 0){
		switch (day){
		case 0:
			break;
		case 1:
			printf("First");
			break;
		case 2:
			printf("Second");
			break;
		case 3:
			printf("Third");
			break;
		case 4:
			printf("Fourth");
			break;
		case 5:
			printf("Fifth");
			break;
		case 6:
			printf("Fifth");
			break;
		case 7:
			printf("Seventh");
			break;
		case 8:
			printf("Eigth");
			break;
		case 9:
			printf("Ninth");
			break;
		default :
			printf("\nDate Cannot be negative");
			break;
		}

	}else if((day-19)<=0){
		switch (day){
		case 10:
			printf("Tenth");
			break;
		case 11:
			printf("Eleventh");
			break;
		case 12:
			printf("Twelfth");
			break;
		case 13:
			printf("Thirteenth");
			break;
		case 14:
			printf("Fourteenth");
			break;
		case 15:
			printf("Fifteenth");
			break;
		case 16:
			printf("Sixteenth");
			break;
		case 17:
			printf("Seventeenth");
			break;
		case 18:
			printf("Eighteenth");
			break;
		case 19:
			printf("Ninteenth");
			break;

		}
	}

	int r = day%10;
	int x = day -r;

	switch (x){
	case 20:
		printf("Twenty");
		day_string(r);
		break;
	case 30:
		printf("Thirty");
		day_string(r);
		break;
	}

}

void month_string(int month){

	switch (month){
	case 1:
		printf("January");
		break;
	case 2:
		printf("February");
		break;
	case 3:
		printf("March");
		break;
	case 4:
		printf("April");
		break;
	case 5:
		printf("May");
		break;
	case 6:
		printf("June");
		break;
	case 7:
		printf("July");
		break;
	case 8:
		printf("August");
		break;
	case 9:
		printf("September");
		break;
	case 10:
		printf("October");
		break;
	case 11:
		printf("November");
		break;
	case 12:
		printf("December");
		break;
	default:
		printf("Invalid month");
		break;
	}
}

void year_string(int year){
	int r = year%100;
	year = year/100;
	sub_string(year);
	printf(" hundred ");
	sub_string(r);
}

void sub_string(int n){

	if((n-19)<=0){
		switch (n){
		case 0:
			break;
		case 1:
			printf("One");
			break;
		case 2:
			printf("Two");
			break;
		case 3:
			printf("Three");
			break;
		case 4:
			printf("Four");
			break;
		case 5:
			printf("Five");
			break;
		case 6:
			printf("Six");
			break;
		case 7:
			printf("Seven");
			break;
		case 8:
			printf("Eight");
			break;
		case 9:
			printf("Nine");
			break;
		case 10:
			printf("Ten");
			break;
		case 11:
			printf("Eleven");
			break;
		case 12:
			printf("Twelve");
			break;
		case 13:
			printf("Thirteen");
			break;
		case 14:
			printf("Fourteen");
			break;
		case 15:
			printf("Fifteen");
			break;
		case 16:
			printf("Sixteen");
			break;
		case 17:
			printf("Seventeen");
			break;
		case 18:
			printf("Eighteen");
			break;
		case 19:
			printf("Ninteen");
			break;
		default:
			printf("Invalid Year");
			break;
		}
	}
	else{
		int r = n%10;
		n = n-r;
		switch(n){
		case 20:
			printf("Twenty");
			break;
		case 30:
			printf("Thirty");
			break;
		case 40:
			printf("Fourty");
			break;
		case 50:
			printf("Fifty");
			break;
		case 60:
			printf("Sixty");
			break;
		case 70:
			printf("Seventy");
			break;
		case 80:
			printf("Eighty");
			break;
		case 90:
			printf("Ninty");
			break;
		}
		sub_string(r);
	}
}
