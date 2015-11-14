//sort a array of 0s and 1s

#include <stdio.h>
#include <stdlib.h>

void sort_1(int *a,int);
void sort_2(int *a,int);
void sort_3(int *a,int);
void sort_4(int *a,int len);

int main(){
	int a[100],a2[100],a3[100],a4[100];
	int len;
	int i;
	printf("Enter the length of the array : ");
	scanf("%d",&len);
	
	for(i = 0 ; i< len ; i++){
		scanf("%d",&a[i]);
		a2[i] =a3[i] = a4[i]=a[i];
		
	}
	
	sort_1(&a[0],len);
	 
	
	sort_2(&a2[0],len);
	

	
	sort_3(&a3[0],len);
	

	
	sort_4(&a4[0],len);
	
	
	return 0;
}

void sort_1(int *a,int len){
	int i,count0 = 0 ,count1 = 0;
	
	for(i = 0 ; i<len ;i++ ){
		if(!a[i])
			count0++;
		else if(a[i] == 1)
			count1++;
		else{
			printf("Only 0s and 1s are allowed");
			exit(0);
		}
	}
	
	for(len--; count1 ; a[len--] = 1,count1--);
	 
	for(count0-- ; count0 >= 0 ; a[count0--] = 0);
	}
	
void sort_2(int *a,int len){
	int i,sum=0;
	for(i = 0 ; i<len ; i++)
		sum +=a[i];
	
	for(len-- ; sum ; sum--,a[len--] = 1);
	
	for( ; len>=0 ;a[len--] = 0);
}

void sort_3(int *a,int len){
	int sum = 0;
	int i = 0;
	
	for(i = 0 ; i<len ; i++)
		sum +=a[i];
	for(len--;sum;sum--)
		a[len--] = 1;
	
	for( ; len >= 0 ; len--)
		a[len] = 0;
	}
	
void sort_4(int *a,int len){
	int i = 0,j = len-1;
	
	while(i<j){
		while(a[i] == 0)
				i++;
		while(a[j] == 1)
				j--;
			
		if(i<j){
				a[i] = !a[i];
				a[j] = !a[j];
				i++;
				j--; 
				}
		}

}
				

	
	
