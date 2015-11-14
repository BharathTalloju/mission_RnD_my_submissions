// Works only for positive numbers and zero
// Still working on negative numbers
#include <stdio.h>
#include <stdlib.h>

int add(int,int);
int bitAt(int,int);
void setBit(int,int*,int);

void main(){
    int x,y;

    printf("Enter x y: ");
    scanf("%d %d",&x,&y);

    printf("\n%d + %d =  %d\n",x,y,add(x,y));


}

int add(int x,int y){


     int c = 0,ans=0,final = 0,k=1;
     int a , b;

     while(k<31){
        a = bitAt(k,x);
        b = bitAt(k,y);
        ans = c^(a^b);
        setBit(k,&final,ans);
        c = (a&b)|(a&c)|(b&c);
        k++;
     }
    return final;


}


int bitAt(int k,int num){

    return ((num>>(k-1))&1);
}

void setBit(int k,int* ans,int val){

    *ans = (val<<(k-1))|(*ans);
}
