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




