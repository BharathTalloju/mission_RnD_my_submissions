#include <stdio.h>
#include <stdlib.h>

int str_equal(str1, str2){
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
        scanf("%[^\n]s", command);
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
    int word_writer = 0;
    
    while(command[command_reader] != ' '){
        word[word_writer] = command[command_reader];
        word_writer++;
        command_reader++;
    }word[word_writer] = '\0';
    
    if(str_equal(word, "merge")){
        printf("\nMerge selected");
        
    }
    
    
}

