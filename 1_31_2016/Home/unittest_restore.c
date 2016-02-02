#include <stdio.h>

int main(){
FILE *f_pointer = NULL;
int id,marks;

f_pointer = fopen("backup21.txt","r");
if(!f_pointer){
printf("\nError opening file %s", "backup21.txt");
}

fscanf(f_pointer,"%d",&id);
printf("\n%d read",id);
fscanf(f_pointer,"%d",&marks);
printf("\n%d read marks: ",marks);

while(!feof(f_pointer)){
	fscanf(f_pointer, "%d %d\n",&id, &marks);
	printf("\nRead id: %d marks: %d",id, marks);
}
fclose(f_pointer);
}
