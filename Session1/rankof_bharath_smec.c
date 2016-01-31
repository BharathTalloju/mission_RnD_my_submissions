/*
 * untitled.c
 * 
 * Copyright 2015 BharathTalloju <heisenberg@heisenberg>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */

//To find the rank of the given number.
#include <stdio.h>

int fact(int);
void rank_of(int);


void rank_of(int num)
{

	int *n;
	int i,rank = 0;
	int len,l;
	int count,j;
	printf("RAnk of ");
	len = printf("%d\n",num)-1;
	
	n = (int*)calloc(len,sizeof(int));
	i = 0;
	while(num){
		n[i++]= num%10;
		num = num / 10;
	}
	
	l = len;
	for(i = len-1 ; i>=0 ; i--,l--){
		count = 0;
		for( j = i - 1; j>= 0  ; j--){
			if(n[j] < n[i])
				count++;
			}
		rank = rank + count*fact(l-1);
	}
	
	printf("is %d\n",rank);
	
}

int fact(int n){
	if(n == 0)
	 return 1;
	else
	 return n*fact(n-1);
 }

int main(){
	int num;
	scanf("%d",&num);
	rank_of(num);
	return 0;
}
	
