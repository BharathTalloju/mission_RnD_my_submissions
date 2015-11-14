#include <stdio.h>

void sum(char* a , char * b);
int no_of_digits(char * str);
void shift(char *a , int n);
char result[1000]; 						 //Storing the sum in array as addition off two unsigned ints may exceed the range of unsigned int

int main(){
  char a[1000],b[1000];

  scanf("%s %s",a,b);

  sum(a,b);

  printf("Sum = %s",result);
}

void sum(char* a ,char *b ){
	char *x,*y;
	int i,l,c,r;
	y = a;
	x = b;

	if(no_of_digits(a) > no_of_digits(b)){ //Finding the largest number to align the digits
		y = b;
		x = a;
	}

	l = no_of_digits(x) + 1;
	shift(x,1);							  //Aligning the digits for addition
	shift(y,l-(no_of_digits(y)));

	c = 0;                                // initial carry

	for(i = l-1 ; i>=0 ; i--){
		r = x[i] + y[i] - '0' - '0' + c ; // converting the char to int and adding carry
		c = (r)/10;
		r = r % 10;
		result[i] = r + '0';
	}
	result[l] = '\0';
	


}

int no_of_digits(char * str){
    int digits;
    
    for(digits = 0 ; str[digits] != '\0' ; digits++);
    
    return digits;
}

void shift(char *a , int n){
	int i;
	for(i = no_of_digits(a) ; i>=0 ; i--)				// Making the no. of digits is both the numbers equal by shifting to the right
		a[i+n] = a[i];
	for(i = 0 ; i<n ; i++)
		a[i] = '0';										// Making the additional spaces 0
    

    
}
