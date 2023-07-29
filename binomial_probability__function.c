#include<stdio.h>
#include<math.h>

int combn(int n, int k){
    if(n == k || k == 0){
        return 1;
    }
    else{
        return combn(n - 1, k) + combn(n - 1, k - 1);
    }
}

double dbinom(int k, int n, float p){
    int c = combn(n, k);
    double prob = pow(p, k) * pow((1 - p), n - k);
	double result = c * prob;
    return result;
}

int main(void){
    int result1 = combn(10, 2);
    printf("%d\n", result1);

    int result2 = combn(100, 95);
    printf("%d\n", result2);

    double result3 = dbinom(5, 10, 0.3);
    printf("%2f\n", result3);

    return 0;
}
