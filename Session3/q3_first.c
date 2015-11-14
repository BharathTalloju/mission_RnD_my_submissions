#include <stdio.h>
#include<stdlib.h>

int find_winner();

typedef struct array{
	int *a;
	int size;
}Array;

Array input,condition;

int main(){
	int i = 0;
	int cond ;
	
	printf("Size of the input array : ");
	scanf("%d",&(input.size));
	input.a = (int*)calloc(input.size,sizeof(int));
	for(i = 0 ; i<(input.size) ; i++)
		scanf("%d",&(input.a)[i]);
	printf("Enter Condition :");
	scanf("%d",&cond);
	
	find_condition(cond);
	printf("Winner = %d",find_winner(&input,&condition));
}

int find_winner(){
	int sum=0,max[]={0,0};
	int i= 0,j,index;
	int s1 = input.size;
	int s2 = condition.size;
	
	for(i = 0 ; i < s1 ; i++ ){
		sum = 0;
		for(j = 0 ; j < s2 ; j++){
			index = i + (condition.a)[j];
			if(index<0);
			else 
				sum += (input.a)[index];
		}
		if(sum>max[1]){
			max[1] = sum;
			max[0] = i;
		}
	}
	return max[0];
}

int find_condition(int n){
	int walker = 0;
	int left = n/2,right = (n-1)/2;
	condition.size = n;
	condition.a = (int*)calloc(n,sizeof(int));
	condition.a[walker++] = 0;
	while(left){
		condition.a[walker++] = -left;
		left--;
	}
	while(right){
		condition.a[walker++] = right--;
	}
	return --walker;
	
}