#include <stdio.h>

int main() {
    int a ;
    int even = 0, odd =0 ,positive =0 , negative =0;
    scanf("%d" , &a);

    for(int i = 0; i < a; i++){
        int x;
        scanf("%d" , &x);

        if(x % 2 == 0){
            even ++;
        }
        else{
            odd++;
        }

        if(x > 0){
            positive++;
        }
        else if(x < 0){
            negative++;
        }
    }

    printf("Even: %d\n" , even);
    printf("Odd: %d\n" , odd);
    printf("Positive: %d\n" , positive);
    printf("Negative: %d\n" , negative);
    
    return 0;
}