#include <stdio.h>

int main(){
	unsigned int a[8] = {1,2,3,9,6,0,0,0};
	
	 printf("\n%d",findN(a));
}

int findN(unsigned int* a){
	int i=0 , x =1;
	
	while(1){
		i = x-1;
		if(!a[i])break;
		x = x*2;
	}
	
	return search(x/2,a);
}

int search(int i,unsigned int *a){
	int w;
	w = i + i/2;
	
	if(a[w] == 0)
		return search(w-(i/4),a);
	if(a[w] < a[w+1])
		return search(w+(i/4),a);
	if(a[w] > a[w+1])
		return w;
}
