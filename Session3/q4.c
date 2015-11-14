#include <stdio.h>
#include <stdlib.h>

int freq_vector[10] = {0};

int main(){
	int *a;
	int N,i,k;
	
	printf("Enter the size of array :");
	scanf("%d",&N);
	
	a = (int*)calloc(N,sizeof(int));
	
	for(i = 0 ; i < N ; i++)
		scanf("%d",&a[i]);
	
	printf("Enter value of k : ");
	scanf("%d",&k);
	
	find_winner(a,N,k);
	
}

int construct_freq_vector(int *a,int N){
	int i ;
	
	for(i = 0 ; i<N ; i++){
		freq_vector[a[i]] += 1;
	}
	
	//display();
}

int find_closest_frequency(int k){
	int difference,closest = 0,min_difference;
	int i;
	
	min_difference = mod(k - freq_vector[0]);
	
	for(i = 1 ; i < 10 ; i++){
		difference = mod(k-freq_vector[i]);
		if(difference < min_difference){
			closest = i;
			min_difference = difference;
		}
	}
	
	//printf("\n number_with_closest_freq = %d",closest);
	return closest;
	
}

int mod(int n){
	if(n<0)	return -n;
	else 	return n;
}

int find_winner(int *a,int N,int k){
	int number_with_closest_freq;
	
	construct_freq_vector(a,N);
	
	number_with_closest_freq = find_closest_frequency(k);
	
	if(freq_vector[number_with_closest_freq] == k){
		printf("%d",0);
		return 0;
	}
	else{
		find_cost(number_with_closest_freq,k);
	}
	
}

int find_cost(int num,int k){
	int i = 1;
	int cost = 0;
	
	if(freq_vector[num] > k){
		printf("%d",freq_vector[num]-k);
		return 0;
	}
	else{
		while(((num + i)<10) || ((num - i) >= 0)){
			if((num-i) >= 0){
				while(freq_vector[num - i]){
					cost += i;
					freq_vector[num - i] -= 1;
					freq_vector[num] += 1;
					if(freq_vector[num] == k)
						break;
				}
			}
			if(freq_vector[num] == k) break;
			
			if((num+i) < 10){
				while(freq_vector[num+i]){
					cost += i;
					freq_vector[num + i] -= 1;
					freq_vector[num] += 1;
					if(freq_vector[num] == k)
						break;
				}
			}
			if(freq_vector[num] == k) break;
		}
		
		printf("\nCost = %d",cost);
	}
}

int display(){
	int i;
	
	printf("\n freq_vector = ");
	for(i = 0 ; i < 10 ; i++)
		printf("%d : %d, ",i,freq_vector[i]);
	
	printf("\n");
}