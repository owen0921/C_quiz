#include<stdio.h>
#include<stdlib.h>

void indexOf(char* s, char* sub, int len){
    int index = 0;
	for(int i = 0; i < len; i++){
		if(sub[0] == s[i]){
			index = i + 1;
		}
		if(sub[1] != s[index]){
            index = 0;
		}
	}
	if(!index){
		printf("Not found.\n");
	}
	else{
		printf("It is at %d\n",index);
	}
	return 0;
}

int main(void){
    char test1[] = "Hello. It is me.";
    char test2[] = "Hello. It is me again.";
    int len = 0;
    int index = 0;
    char sub1[] = "is";
    char sub2[] = "ME";

    while(test1[index] != '\0'){
        index++;
        len++;
    }
    indexOf(test1, sub1, len);

    index = 0;
    len = 0;

    while(test1[index] != '\0'){
        index++;
        len++;
    }
    indexOf(test2, sub2, len);

    return 0;
}
