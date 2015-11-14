#include <stdio.h>
#include <stdlib.h>

void strrev(char* s);
void strrev2(char *s,int from,int to);

int main(){
	char s[] = "asdfgh";
	strrev(s);
	printf("%s",s);
	strrev2(s,1,1);
	printf("\n%s",s);
}

void strrev(char* s){
	int i,j;
	char c;
	
	for(i = 0 ; s[i] != '\0' ; i++);
	i--;
	for(j = 0 ;j<i ; i--,j++){
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}

void strrev2(char *s,int from,int to){
	char t;
	
	for( ; from<to ; from++,to--){
		t = s[from];
		s[from] = s[to];
		s[to] = t;
	}
}
