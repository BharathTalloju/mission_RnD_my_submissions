#include <stdio.h>
#include <stdlib.h>

int check_if_digit_in(int d, long int n);
int start();
int check(long int n,long int m);

int main(){
	start();
}

int start(){
	int i1,i2,i3,i4,i5,i6,mul;
	long int num = 0;
	long int product = 0;
	for(i1 = 1 ; i1 <5 ; i1++){
		num = 0;
		num = num*10 + i1;
		for(i2 = 0 ; i2 <= 9 ; i2++){
			num = num*10 + i2;
			for(i3 = 0 ; i3 <= 9 ; i3++ ){
				num = num*10 + i3;
				for(i4 = 0 ; i4 <= 9 ; i4++){
					num = num*10 + i4;
					for(i5 = 0  ; i5 <= 9 ; i5++){
						num = num*10 + i5;
						for(i6 = 0 ; i6 <= 9 ; i6++){
							num = num*10 + i6;
							for(mul = 2 ; mul < 10 ; mul++){
							product  = num*mul;
							//printf("\nNum = %ld \n Product = %ld",num,product);
							if(check(num,product)){
								printf("\nNUM = %ld\t Product = %ld",num,product);
								exit(0);
							}
							product = product /mul ;
							}
							num = num /10;
							//exit(0);
						}
					num = num /10;
					}
				num = num /10;
				}
			num = num /10;
			}
		num = num /10;
		}
	num = num /10;
	}
num = num /10;
}

int check(long int num,long int product){
	int d;
	int count = 0;
	while(num){
		d = num % 10;
		if(check_if_digit_in(d,product))
			count++;
		else return 0;
	}
	if(count == 6) 
		return 1;
	return 0;
}

int check_if_digit_in(int d, long int n){
	int i = 0;
	while(n){
		i = n % 10;
		if(i == d)return 1;
		n = n /10;
	}
	return 0;
}