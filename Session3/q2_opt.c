#include <stdio.h>
#include <stdlib.h>

int find_representation(int n);

int representation[10];

int main(){
	int i = 0;
	
	find_representation(3);
	for(i = 0 ; i < 5 ; i++)
		printf("\t %d",representation[i]);
}

int find_representation(int n){
	int prev=0,sum=0,present = 1;
	int walker = 0;
	
	while(n){
		prev =  sum = walker = 0;
		present = 1;
		while(n<present){
			sum += present;
			present = present + prev;
			
			walker++;
		}
		
		representation[--walker] = 1;
		sum += prev;
		n = n- prev;
 	}
}