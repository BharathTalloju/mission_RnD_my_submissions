
#include <stdio.h>
#include <stdlib.h>

int add(int,int);
int bitAt(int,int);
void setBit(int,int*,int);
int mul(int x, int y);
int shiftMul(int x,int k);
void increment(int*);
void main(){
    int x,y;

    printf("Enter x y: ");
    scanf("%d %d",&x,&y);

    printf("\n%d * %d =  %d\n",x,y,mul(x,y));


}

int mul(int x, int y){
    int flag=0;
    int k = 1<<30;

    if(y == -1) return -x;
    if((x>0 && y<0)){
     flag = 1;
     y = -y;
     }
    else if(x<0 && y>0){
     flag = 1;
     x = -x;
    }
    else if(x<0 && y<0){
     x = -x;
     y = -y;
    }
    while(k>y){
    k>>=1;
    }k<<1;

    if(y == 0) return 0;
    else if(y == 1) return x;
    else{
     if(flag)return -(add( shiftMul(x,k),mul(x,y-k)));
     else return add( shiftMul(x,k),mul(x,y-k));
     }


}

int shiftMul(int x,int k){
    int count = 0;
    k>>=1;
    while(k){
    increment(&count);
    k>>=1;
    }

    return x<<count;
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
        increment(&k);    //had to use increment, still finding another way to increment.
     }
    return final;



}


int bitAt(int k,int num){

    return ((num>>(k-1))&1);
}

void setBit(int k,int* ans,int val){

    *ans = (val<<(k-1))|(*ans);
}

void increment(int* n){
    int x = *n;
    int w = 1;
    while(x&w){
        x = x^w;
        w<<=1;
    }x = x^w;
    *n = x;

}
