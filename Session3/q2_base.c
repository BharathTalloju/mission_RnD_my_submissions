#include <stdio.h>
#include <stdlib.h>

long int table[20];
int representation[20]= {0};

void find_representation(long int n);

int main(){
	int i = 0;
	fill_table();
	
	printf("Enter number : ");
	scanf("%d",&i);
	find_representation(i);
	printf("\nFibo = \n");
	for( i = 0 ; i < 5 ; i++)
		printf("%d ",representation[i]);
}

int fill_table(){
	int i = 2;
	
	table[0] = 1;
	table[1] = 1;
	while(i<19){
		table[i] = table[i-1] + table[i-2];
		i++;  
	}
	
}

void find_representation(long int n){
	int walker,j;
	long int sum = 0;
	
	if(n){
		for(walker = 0 ; walker < 20 ; walker++){
		sum = sum + table[walker];
		if(sum >= n){
			printf("\nNumber = %d, Sum =  %d, setting representation[%d] as 1",n,sum,walker);
			representation[walker] = 1;
			find_representation(n-table[walker]);
			break;
		}	
		}
	}
	
}

