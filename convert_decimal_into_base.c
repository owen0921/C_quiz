#include<stdio.h>
#include<stdlib.h>

void convert_decimal(int base, int num){
    int result[20] = {0}; // 把每回合的餘數存起來
    int i = 0;
    while(num > 0){
        result[i] = num % base;
        num = num / base;
        i++;
    }
    i--;

    printf("Output:");
    for(;i >= 0; i--){
        printf("%d", result[i]);
    }
}

int main(void){
    int base = 0;
    int num = 0;
    printf("Input base number:");
    scanf("%d", &base);
    printf("Input number:");
    scanf("%d", &num);
    convert_decimal(base, num);
    return 0;
}
