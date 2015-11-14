
#include <stdio.h>

int isDivisible(char*,int,int);
int check(char*,int,int);
int no_of_digits(char * str);

int main(){
    char str[1000];
    unsigned int digits,k;
    scanf("%s",str);
    rewind(stdin);
    digits =  no_of_digits(str);
    scanf("%d",&k);
    if(isDivisible(str,digits,k))
    printf("\nDivisible");
    else
     printf("not Divisible");
}

int isDivisible(char* n,int digits,int k){

    if((digits&1) && (!(k&1)))				//Odd No. of digits repeated even no. of times
        return 1;							//Always a multiple of 11
    else if((digits&1) && (k&1)){			//Odd No. of digits repeated odd no. of times
        return check(n,digits,1);
    }
    else if((!(digits&1)) && (k&1) ){		//Even no. of digits repeated odd no. of times
        return check(n,digits,0);
    }
    else if(!((digits & 1) && (k&1))){		//Even no. of digits repeated even no of times
        return check(n,digits,0);
    }
}

int check(char* n, int digits, int x){
    int i,j,sum = 0;

    if(x){
        for(i = 0 , j = 1 ; (i<digits) && (j<digits) ; i+=2,j+=2){
            sum = sum+(n[i] - n[j]);
        }

        if(n[j] == '\0'){
            sum += (n[i] - '0');
            //if(sum == 11) sum = 0;
        }

        return !(sum%11);
    }else{
        for(i = 0 , j = 1 ; (i<digits) && (j<digits) ; i+=2,j+=2){
            sum = sum+(n[i] - n[j]);
        }
        return !sum;
    }

}

int no_of_digits(char * str){
    int digits;

    for(digits = 0 ; str[digits] != '\0' ; digits++);

    return digits;
}
