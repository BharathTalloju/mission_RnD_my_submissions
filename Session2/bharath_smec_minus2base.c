#include <stdio.h>
//#define VAL 5

void base_minus2(unsigned int n,int* last);

int table[32];
int result[10];
int main(){
	int i,last;
	unsigned int n;

	scanf("%d",&n);
	base_minus2(n,&last);
	printf("\n");
	for( ; last>=0 ; last--)
		printf("%d",result[last]);
}

void base_minus2(unsigned int n,int *last){
	int q,r,writer = 0;

	q = n/(2);
	r = n%(2);
	q = -q;
	result[writer++] = r;
	printf("\nq = %d r = %d",q,r);
	printf("\n result[w] = %d",result[writer-1]);
	while( (q != 1) && (q)){
		r = q % (-2) ;
		q = q / (-2);
		if(r == -1){
			r = 1;
			q = q+1;
		}
		printf("\nq = %d r = %d",q,r);
		result[writer++] = r;
		printf("\n result[w] = %d",result[writer-1]);


	}
	if(q == 1) result[writer] = 1;

	*last = writer;
}

void construct_table(int n){
	int sum = 0,i=0;
	table[0] = 1;

	for(i = 1 ; i<32 ; i++){
		table[i] = table[i-1] * (-2);
	}


}
