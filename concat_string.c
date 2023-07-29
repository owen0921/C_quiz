#include<stdio.h>
#include<stdlib.h>

void concat(char* str1, char* str2){
    int len1 = 0;
    int len2 = 0;
    int index = 0;

    while(str1[index] != '\0'){
        index++;
        len1++;
    }

    index = 0;
    while(str2[index] != '\0'){
        index++;
        len2++;
    }

    char* out = malloc(sizeof(char) * (len1 + len2));

    for(int i = 0; i < len1; i++){
        out[i] = str1[i];
    }

    int j = len1;
    for(int i = 0; i < len2; i++){
        out[j] = str2[i];
        j++;
    }

    for(int i = 0; i < len1 + len2; i++){
        printf("%c", out[i]);
    }
    free(out);
}
int main(void){
    char str1[] = "hand";
    char str2[] = "some";
    concat(str1, str2);
    return 0;
}

