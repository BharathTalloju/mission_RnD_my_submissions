#include <stdio.h>
#include <stdlib.h>

void sort(char *s,int start,int last);
int str_length(char*);
int strchr(char *s,char c);

int strchr(char *s,char c){
	int i;
	
	for(i = 0 ; s[i] != '\0' ; i++){
		if(s[i] == c)return i;
	}
	return -1;
}
//nlogn
int is_anagram(char* a,char *b){
	int len1,len2;
	int i;
	
	len1 = str_length(a);
	len2 = str_length(b);
	
	sort(a,0,len1-1);
	sort(b,0,len2-1);
	printf("\nAfter sort a = %s, b = %s",a,b);
	
	if(len1 != len2)return 0;
	else{
		for(i = 0 ; i<len1 ; i++){
			if(a[i] == b[i]);
			else return 0;
		}
	}
	if(i == len2)return 1;
	
}


void swap(char *s,int i,int j){
	char temp = s[i];
	printf("\nSwapping %d and %d in %s",i,j,s);
	s[i] = s[j];
	s[j] = temp;
}

int str_length(char* s){
	int len;
	
	for(len =0 ;s[len] != '\0' ; len++);
	//printf("\nLength of %s = %d",s,len);
	return len;
}

void sort(char *s,int start,int last){
	int i,j,pivot;
	pivot = s[start];
	i = start+1;
	j = last;
	if(start<last){
	while(i<j){
		while((s[i] < pivot) && (i<last))i++;
		while((s[j] >= pivot ))j--;
		if(i<j){
			swap(s,i,j);
 		}
	}
			swap(s,j,start);
			sort(s,j+1,last);
			sort(s,start,j-1);
		}
	}


int main(){
	char a[50],b[50];
	scanf("%s %s",a,b);
	printf("%d",is_anagram(a,b));
}