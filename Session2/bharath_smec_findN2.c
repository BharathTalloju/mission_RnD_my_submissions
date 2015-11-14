#include <stdio.h>

int findN(unsigned int* a);
int searchN(unsigned int *a,int x);

int main(){
	unsigned int a[] = {1,2,5,6,2,0,0,0};

	printf("N = %d",findN(a));
}

int findN(unsigned int* a){
	int i = 1;

	while(1){
		if(a[i] > a[i+1]){
			if(a[i+1] == 0)
				return i-1;
			else return i;
		}
		else if(a[i] < a[i+1]){
			i = i*2;
		}
		else if(a[i] == 0)
			return searchN(a,(i/2));
	}
}

int searchN(unsigned int* a,int x){
	int divider = 2;
	int mid = x + x/divider;

	while(1){
		if(a[mid] > a[mid+1]){
			if(a[mid+1] == 0){
				return mid-1;
			}
			else {
				divider = divider * 2;
				mid = mid + x/divider;
			}
		}
		else if(a[mid] == 0){
			divider = divider * 2;
			mid = mid - x/divider;
		}
	}
}
  
