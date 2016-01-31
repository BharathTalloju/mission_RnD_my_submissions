#include <stdio.h>
#include <stdlib.h>

int indices[2] = {0};

int* find_largest_sub_array(int* arr, int len){
	int max = 0;
	int sum;
	int i,j;
	int walker;
	
	for(i = 0 ; i < len ; i++){
		for(j=i ; j < len ; j++){
			sum = 0;
			for(walker = i ; walker <= j ; walker++){
				sum += arr[walker];
			}
			if(sum > max){
				indices[0] = i;
				indices[1] = j;
			}
			else if(sum == max){
				if((j - i) < (indices[1] - indices[0])){
					indices[0] = i;
					indices[1] = j;
				}
			}
		}
	}
	return indices;
	
}

int main(){
	int arr[] = {-2,2,6,5,-6,8,12,-22,14};
	int len= 9;
	int *result;
	
	
	for()
	
}