#include <stdio.h>

int check(int num,int product){
	int r;
	int num2 = num;
	//printf("\nChecking %d and %d",num,product);
	while(num){
		r = num % 10;
		if(check_if(r,product));
			//count++;
		else 
			return 0;
		num = num / 10;
	}
	//printf("\n%d = %d",num2,product);
	
	return 1;
}

int check_if(int r,int product){
	int rem;
	//printf("\nChecking if %d is in %d",r,product);
	while(product){
		rem = product % 10;
		if(rem == r){
			//printf("\n Yes %d is in %d",rem,product 	);
			return 1;
		}
		product = product/10;
	}
	return 0;
}

int main(){
	printf("%d",check(123,3421));
}