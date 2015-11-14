/*
 * powerMod_bharath_smec.c
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

// find x^y%a 
#include <stdio.h>


void power_mod(unsigned int,unsigned int,unsigned int);

int main(int argc, char **argv)
{
	unsigned int x,y,a;
	
	scanf("%u %u %u",&x,&y,&a);
	
	power_mod(x,y,a);
	
	return 0;
}

void power_mod(unsigned int x,unsigned int y,unsigned int a){
	
	unsigned int table[100];
	int i = 1;
	unsigned int k = 1;
	unsigned int temp = 0;
	unsigned int mod = 1;
	
	if(a == 0) {
		printf("Cannot divide by zero\n");
		exit(0);
	}
	if(a == 1){
		printf("Value = 0");
		exit(0);
	}
	
	table[0] = x%a;
	while(k<y){     //No need to evaluate extra values and independent of whether 32 or 64 bit  int
		temp = table[i-1] % a;			
		
		table[i] = (temp * temp)%a;
		i++;
		k<<=1;
	}
	
	k=1;
	i = 0;
	while(k<y){
		if(k & y){
			mod = ((mod) * (table[i]))%a;
			
		}
		k<<=1;
		i++;
	}

	
	printf("Value = %u\n",mod);
}
		
