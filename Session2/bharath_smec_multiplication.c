/*Input : a[10] and b[5]
  The 320 bits in a[10] represent a binary number(say x) such that a[0] consists the 32-most significant bits.
  Similarly b[5] represents a binary number(say y). 

  Output : c[15]
  c[15] represents a number z = x*y

*/

#include <stdio.h>

int shift(unsigned int *c,unsigned int k);
void initialize_temp(unsigned int *a,unsigned int *t);
void addArray(unsigned int *c,unsigned int *t);
void increment(unsigned int* n);
unsigned int add(unsigned int x,unsigned int y,int* c);
unsigned int bitAt(unsigned int k,unsigned int num);
void setBit(unsigned int k,unsigned int* ans,unsigned int val);
unsigned int multiply(unsigned int* a,unsigned int *b,unsigned int* c);
void shift_bits(unsigned int *a,unsigned int k);
void display(unsigned int *x,int i);


int main(){
	unsigned int a[10] = {0,0,0,0,0,0,0,0,2,1};
	unsigned int b[5] = {1,0,0,0,0};
	unsigned int c[15] = {0};
	int i;
	
	printf("\n Multiplying ");
	display(a,10);
	printf("\n and ");
	display(b,5);
	multiply(a,b,c);
	
	display(c,15);
}

int shift(unsigned int *c,unsigned int k){
	unsigned int one = 1,carry = 0;
	int i;
	if(k == 0)
		return 1;
	else{
		for(i = 0 ; i<15 ; i++){
			carry = 0;
			if((one<<31) & c[i])
				c[i-1] = c[i-1]|1;
			c[i]<<=1;
		}
		shift(c,k-1);
	}
}

void initialize_temp(unsigned int *a,unsigned int *t){
	int i,j;
	for(i = 9,j=14 ; i>=0 ; i--,j--)
		t[j] = a[i];
	while(j+1)
		t[j--] = 0;
}

void addArray(unsigned int *c,unsigned int *t){
	unsigned int carry = 0;
	int i;
	
	for(i = 14 ; i>=0 ; i--){
		c[i] = add(c[i],t[i],&carry);
	}
}

void increment(unsigned int* n){
    unsigned int x = *n;
    unsigned int w = 1;
    while(x&w){
        x = x^w;
        w<<=1;
    }x = x^w;
    *n = x;

}

unsigned int add(unsigned int x,unsigned int y,int* c){
     unsigned int ans=0,final = 0,k=1;
     unsigned int a , b;

     while(k<31){
        a = bitAt(k,x);
        b = bitAt(k,y);
        ans = *c^(a^b);
        setBit(k,&final,ans);
        *c = (a&b)|(a&(*c))|(b&(*c));
        increment(&k);   
     }
    return final;
}


unsigned int bitAt(unsigned int k,unsigned int num){

    return ((num>>(k-1))&1);
}

void setBit(unsigned int k,unsigned int* ans,unsigned int val){

    *ans = (val<<(k-1))|(*ans);
}


unsigned int multiply(unsigned int* a,unsigned int *b,unsigned int* c){
	unsigned int temp[15];
	unsigned int k=0,i,one = 1;
	int index;
	//printf("\n%u",a[3]);
	for(index = 4 ; index >= 0 ; index--){
		printf("\nChecking b[%d]",index);	
		for(i = 0 ; i<32 ; i++,k++){
			initialize_temp(a,temp);
			//printf("\ntemp = ");
			//display(temp,15);
			if((one<<i)&(b[index])){
				printf("\n %dth bit is 1",k);
				shift_bits(temp,k);
				addArray(c,temp);
				//printf("\n c = ");
				//display(c,15);
			}
		}
	}
}

void shift_bits(unsigned int *a,unsigned int k){
	int i;
	
	if(k>32){
		for(i =0 ; i<14 ; i++)
			a[i] = a[i+1];
		a[i] = 0;
		shift_bits(a,k-32);
		//printf("\ntemp =");
		//display(a,15);
	}
	else{
		shift(a,k);
	}
}

void display(unsigned int *x,int i){
	int w;
	printf("\n");
	for(w = 0 ; w<i ; w++)
		printf("%u ",x[w]);
	printf("\n");
}
