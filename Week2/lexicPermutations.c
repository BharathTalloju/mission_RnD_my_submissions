#include <stdio.h>
#include <stdlib.h>

int main(){
	unsigned int a;
	
	scanf("%u",&a);
	printf("\nThe Perutations are :\n");
	permutations(a);
}

void permutatiions(int a){
	int* result[40320];
	int pivot,i;
	int *arr;

	arr = toArray(a);
	for(pivot = 0 ; pivot<8 ; pivot++){
		for(i = 0 ; i<8 ; i++){
			swap(arr,i,pivot);
			result[j++] = arr;
			swap(arr,i,pivot); 
		}
	}
	//quickSort(arr,0,7);
	for(i = 0 ; i<40320 ; i++){
		for(pivot = 0 ; pivot <8 ; pivot++)
			printf("%d",result[i][j]);
		printf("\n");
	}
	
}

int* toArray(int a){
	int s[8];
	int i;
	
	for(i = 0 ; a ; i++){
		s[i] = a%10;
		a = a/10;
	}
	return &s;
}

void swap(int *arr,i,j){
	
	arr[i] = arr[i] + arr[j];
	arr[j] = arr[i] - arr[j];
	arr[j] = arr[i] - arr[j];
	
}