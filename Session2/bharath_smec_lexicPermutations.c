#include <stdio.h>
#include <stdlib.h>
#define NUM 8
#define F 40320

void permutations(int* a,int start);
void swap(int *a,int i,int j);
int result[F][NUM];
int main(){
	int n,i = NUM-1,j;
	int a[NUM];

	scanf("%d",&n);
	while(n){
		a[i--] = n%10;
		n = n/10;
	}

	permutations(a,0);

    printf("The permutations are : \n");

	for(i = 0 ; i<F ; i++ ){
        for(j = 0 ; j<NUM ; j++)
            printf("%d",result[i][j]);
        printf("\n");
    }
}

void permutations(int *a,int start){
	int i = start;
    static int count = 0;

	if(start == (NUM)){
        i = rank_of(a);
        for(start = 0 ; start<NUM ; start++)
            result[i][start] = a[start];
        /* for(i = 0 ; i<NUM ; i++)
            result[count][i] = a[i];
        count++;*/
		return;
	}
	else for(i = start ; i<NUM ; i++){
			swap(a,i,start);
			permutations(a,start +1);
			swap(a,i,start);
	}
}

void swap(int *a,int i,int j){
	int temp = a[i];
	a[i] = a[j];
	a[j] = temp;

}

int rank_of(int *a){
    int i,j;
    int rank=0,count;

    for(i = 0 ; i < NUM ; i++){
        count= 0;
        for(j = i+1 ; j<NUM ; j++)
            if(a[j] < a[i])
                count++;
        rank = rank + count*fact(NUM - i - 1);
    }
    //printf("\nrank = %d",rank);
    return rank;
}

int fact(int n){
	if(n == 0)
	 return 1;
	else
	 return n*fact(n-1);
 }
