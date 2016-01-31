/*
 * excl_product_bharath_smec.c
 * 
 * Copyright 2015 bharath <bharath@bharath-Inspiron-3542>
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

//a[i] contains product of all the elemnts in the array excluding a[i]

#include <stdio.h>

void ex_product1(int list[],int len);
void ex_product2(int list[],int len);
void ex_product3(int list[],int len);
void ex_product_lessOpt(int list[],int len);

int main(int argc, char **argv)
{
	
	int list[100];
	int i,len;
	printf("Enter the size of the list : ");
	scanf("%d",&len);
	
	for(i = 0 ; i<len ; i++)
		scanf("%d",(list+i));
	
	
	ex_product1(list,len);
	
	ex_product2(list,len);
	
	ex_product3(list,len);
	
	ex_product_lessOpt(list,len);
	return 0;
}

void ex_product1(int list[100],int len){
	int i = 0;
	int *lmr = (int*)calloc(len,sizeof(int));
	int *rmr = (int*)calloc(len,sizeof(int));
	int *result = (int*)calloc(len,sizeof(int));
	
	lmr[0] = 1;
	for(i = 1 ; i< len ; i++){
		lmr[i] = lmr[i-1] * list[i-1];
	} 
	
	rmr[len-1] = 1;
	for(i = len-2 ; i>=0 ; i--)
		rmr[i] = rmr[i+1] * list[i+1];
	
	for(i = 0 ; i < len ; i++)
		result[i] = lmr[i] * rmr[i];
	
	printf("\n\n\n");
	for(i = 0 ; i< len ; i++)
		printf("%d, ",result[i]);
	}
	
void ex_product2(int list[100],int len){
	int i = 0;
	int *lmr = (int*)calloc(len,sizeof(int));
	int *result = (int*)calloc(len,sizeof(int));
	
	lmr[0] = 1;
	for(i = 1 ; i< len ; i++){
		lmr[i] = lmr[i-1] * list[i-1];
	} 
	
	result[len-1] = 1;
	for(i = len-2 ; i>= 0 ; i--)
		result[i] = result[i+1] * list[i+1];
	
	for(i = 0 ; i<len ; i++)
		result[i] = result[i] * lmr[i];
		
	printf("\n\n\n");
	for(i = 0 ; i< len ; i++)
		printf("%d, ",result[i]);


}

void ex_product3(int list[100],int len)	{
	int i = 0,p = 1;
	
	int *result = (int*)calloc(len,sizeof(int));
	
	result[0] = 1;
	for(i = 1 ; i<len ; i++)
		result[i] = result[i-1] * list[i-1];
	
	for(i = len - 2 ; i>= 0 ; i--){
		p = p * list[i+1];
		result[i] = result[i] * p;
	}
	
	printf("\n\n\n");
	for(i = 0 ; i< len ; i++)
		printf("%d, ",result[i]);
		
	
}

void ex_product_lessOpt(int list[100],int len){
	int p = 1,k;
	int i = 0;
	int* result = (int*)calloc(len,sizeof(int));
	for( ; i<len ; i++)
		if(list[i])
			p = p*list[i];
		
	for(i =0 ; i <len ; i++){
		if(list[i])
			result[i] = p/list[i];
		else{
			k = i;
			for(i = 0 ; i<len ; i++)
				result[i] = 0;
			result[k] = p;
		}
			
			
		}
	
	printf("\n\n\n");
	for(i = 0 ; i< len ; i++)
		printf("%d, ",result[i]);
}
	
	
