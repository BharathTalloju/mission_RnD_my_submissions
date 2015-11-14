#include <stdio.h>

void sum(char* a , char * b);
int no_of_digits(char * str);
void shift(char *a , int n);
char result[10000]; 						 //Storing the sum in array as addition off two unsigned ints may exceed the range of unsigned int

void strAdderEqual(char* a,char *b);

int main(){
  char a[1000],b[1000];

  scanf("%s %s",a,b);

  strAdderEqual(a,b);

  printf("Sum = %s",result);
}

void strAdderEqual(char* a,char *b){
	int writer,reader,sum = 0;
	int walker ;

	for(writer = 0,reader = 0 ; a[reader] != '\0' ; reader++){
		sum = a[reader] + b[reader] - (2*'0');
		//printf("\nsum = %d",sum);
		if(sum < 9 ){
			writer = reader;
			result[reader] = sum + '0';
			//printf("\n %s",result);

		}
		else if(sum == 9){
			result[reader] = '9';

		}
		else{
			result[writer] = result[writer] + 1;
			result[reader] = sum%10 + '0';
			//printf("\nWriter = %d reader = %d",writer,reader);
			for( writer++; writer<reader ; writer++)result[writer] = '0';
			//printf("\n %s",result);
			//printf("\nWriter = %d",writer);

		}

	}
	result[reader] = '\0';
}
