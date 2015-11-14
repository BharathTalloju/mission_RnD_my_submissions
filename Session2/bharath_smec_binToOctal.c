
#include <stdio.h>
#include <stdlib.h>

void toOctal(char *bin);
int lengthOf(char *a);

int main(){
	char bin[1000];
	int i = 0,N;

	scanf("%s",bin);
	toOctal(bin);
	printf("%s",bin);


}

void toOctal(char *bin){
	int last = lengthOf(bin) - 1;
	int k = last,counter = 0;
	int table[] ={1,2,4};
	int sum = 0;

	while(last >= 0){
		counter = 0;
		while(counter <3){
			if(bin[last] == '1'){
				sum = sum + table[counter];
			}
			counter++;
			last--;
		}bin[k--] = sum + '0';
		sum = 0;
	}
	while(k>=0)bin[k--] = '0';
}

int lengthOf(char *a){
	int len ;

	for(len = 0 ; a[len] != '\0' ; len++);

	return len;
}
