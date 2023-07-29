#include<stdio.h>
#include<stdlib.h>

void freqTrans(char* s){
    int len = strlen(s);
    if(len < 2){
        printf("Too short!");
    }
    else{
        int frequency[26][26] = {0};
        int max = 0;
        char from = s[0];
        char to = s[1];
        int max_from = 0;
        int max_to = 0;

        // convert char to number and save them to the frequency
        // (a, b)===>(0, 1)
        for(int i = 0; i < len; i++){
            from = s[i] - 97;
            to = s[i + 1] - 97;
            frequency[from][to]++;
        }

        // find the max and print out
        for(int i = 0; i < 26; i++){
            for(int j = 0; j < 26; j++){
                if(frequency[i][j] > max){
                    max = frequency[i][j];
                    max_from = i;
                    max_to = j;
                }
            }
        }
        char final_from = max_from + 97;
        char final_to = max_to + 97;
        printf("%c -> %c, Frequency: %d\n", final_from, final_to, max);
    }
}

int main(void){
    freqTrans("abbab");
    freqTrans("abbacacacc");
    return 0;
}
