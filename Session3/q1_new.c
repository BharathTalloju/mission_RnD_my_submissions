#include <stdio.h>
#include <stdlib.h>

int check(int num,int product);
int enumerate();
int check_if(int r,int num);

int main(){
	enumerate();
}

int enumerate(){
	int d0,d1,d2,d3,d4,d5;
	int num ,product;
	
	for(d5 = 1 ; d5 < 5 ; d5++){
		num = d5; 
		for(d4 = 0 ; d4 <= 9 ; d4++){
			num = num*10 + d4; 
			for(d3 = 0 ; d3 <= 9 ; d3++){
				num = num *10 +d3;
				for(d2 = 0 ; d2 <= 9 ; d2++){
					num = num *10 +d2;
					for(d1 = 0 ; d1 <= 9 ; d1++){
						num = num *10 +d1;
						for(d0 = 0 ; d0 <= 9 ;d0++){
							num = num *10 +d0;
							product = num * 2;
							if(check(product,num)){
								if(check(num,product)){
									printf("\n Num = %ld product = %ld",num,product);
								}
							//exit(0);
							}
							num = num / 10;
						}
						num = num / 10;
					}
					num = num / 10;
				}
				num = num / 10;
			}
			num = num / 10;
		}
		
	}
}

int check(int product,int num){
	int r;
	int count =0;
	//printf("\nChecking %d and %d",num,product);
	while(product){
		r = product % 10;
		if(check_if(r,num))
			count++;
		else 
			return 0;
		product = product / 10;
	}
	//printf("\n%d = %d",num2,product);
	if(count == 6)
		return 1;
	else 
		return 0;
}

int check_if(int r,int num){
	int rem;
	//printf("\nChecking if %d is in %d",r,product);
	while(num){
		rem = num % 10;
		if(rem == r){
			//printf("\n Yes %d is in %d",rem,product 	);
			return 1;
		}
		num = num/10;
	}
	return 0;
}
