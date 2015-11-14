#include <stdio.h>

int is_divisible(char *n);

int main(){
	char str[1000];
	unsigned int k;
	scanf("%s%d",str,&k);

    if((k%3) == 0)						//Any number repeated 3x times is a multiple of 3
        printf("is Divisible");			//Since 3(sumOfDigits) is a multiple of digits
	else if(is_divisible(str))
		printf("Divisible by 3");
	else
		printf("Not Divisible");
}

int is_divisible(char *n){
	int sum = 0;
    int i;
	for(i = 0 ; n[i] != '\0' ; i++){
		sum += (n[i] - '0')%3;
		if((sum%3) == 0) sum = 0;
	}
	return !sum;
}
