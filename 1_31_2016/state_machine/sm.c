#include <stdio.h>
#include <stdlib.h>
//#include "merge_records.c"

int str_equal(char *str1, char *str2);
void clean_stdin(void);
int start_state();
int parse_command(char* command);
void read_word(char *command, int *command_reader, char *word);

void clean_stdin(void)
{
    int c;
    do {
        c = getchar();
    } while (c != '\n' && c != EOF);
}

int str_equal(char *str1, char *str2){
    int i = 0;

    while(str1[i] != '\0' && str2[i] != '\0'){
        if(str1[i] != str2[i]){
            return 0;
        }
        i++;
    }
    return 1;

}

int start_state(){
    int flag = 1; 
    char command[500];

    while(flag){
        clean_stdin();
        scanf("%[^\n]s", command);
        printf("\nCommand: %s",command);
        if(!parse_command(command)){
            printf("\nInvalid Syntax");
        }

    }
}

int parse_command(char* command){
    int result = 0;
    int choice;
    char word[20];
    int command_reader = 0;

    read_word(command, &command_reader, word);

    if(str_equal(word, "merge")){
        char f1[50], f2[50];
       printf("\nMerge Records");
       return 1;
    }
    else if(str_equal(word, "display")){
        printf("\nDisplay records");
        return 1;
    }
    else if(str_equal(word, "Create")){
        printf("\nCreate a new record");
        return 1;
    }
    else if(str_equal(word, "select")){
        return 1;
    }
    return 0;

}

void read_word(char *command, int *command_reader, char *word){
    int word_writer = 0;
    
    while(command[*command_reader] != ' ' & command[*command_reader] != '\0'){
        word[word_writer] = command[*command_reader];
        word_writer++;
        *command_reader = *command_reader + 1;
    }word[word_writer] = '\0';
}

int main(){
    start_state();
}
