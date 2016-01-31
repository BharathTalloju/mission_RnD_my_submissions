#include <stdio.h>
#include <stdlib.h>
void increment(int* n);

void main(){
    int n =1;
    increment(&n);
    printf("%d",n);
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
