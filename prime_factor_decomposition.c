#include<stdio.h>
void prime_factor_decomposition(int num){
    int i = 0; // prime factor
    int count = 0; // numbers of that prime factor
    int temp = num; // reserve the original number

    for(i = 2; i < num / 2; i++){
        // record the times of prime factor
        while(temp % i == 0){
            count++;
            temp = temp / i;
        }
        if(count > 0){
            printf("%d^%d", i, count);
            if(temp != 1){
                printf(" * ");
            }
        }
        count = 0;
    }
}


int main(void){
    int number = 0; // input number
    printf("Please enter the number:");
    scanf("%d", &number);
    prime_factor_decomposition(number);
    return 0;
}
