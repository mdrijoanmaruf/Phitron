#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int line = 5;
    int w = n;
    int loop = line + 1 + n / 2;

    for(int i = 0; i < loop; i++) {
        for(int j = 0; j < loop - 1 - i; j++) {
            printf(" ");
        }
        for(int j = 0; j < i + 1; j++) {
            printf("*");
        }
        for(int j = 0; j < i; j++) {
            printf("*");
        }
        printf("\n");
    }

    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            printf(" ");
        }
        for(int j = 0; j < w; j++) {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}
