#include<stdio.h>

int isDivisible(char *n);

int main(){
    char str[1000];

    scanf("%s",str);

    if(isDivisible(str))
        printf("Is Divisible");
    else
            printf("Not Divisible");
    return 0;
}


int isDivisible(char *n){
    int i,j,sum = 0;

    for(i = 0 , j = 1 ; (n[i] != '\0') && (n[j] != '\0') ; i+=2,j+=2){
            sum = sum+(n[i] - n[j]);			// A number is divisible by 11 if the sum of digits at even places - sum of digits at odd places is 0 or multiple of 11
            //if(sum == 11) sum = 0;
        }
        if(n[j] == '\0'){
            sum += (n[i] - '0');				//In case of odd digited numbers
            //if(sum == 11) sum = 0;
        }
    return !(sum%11);
}

