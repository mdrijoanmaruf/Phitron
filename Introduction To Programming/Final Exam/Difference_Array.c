#include <stdio.h>
#include <stdlib.h>

void selectionSort(int arr[], int n) {
    for(int j = 0; j < n; j++) {
        int max = j;
        for(int i = j; i < n; i++) {
            if(arr[i] < arr[max]) {
                max = i;
            }
        }
        int temp = arr[j];
        arr[j] = arr[max];
        arr[max] = temp;
    }
}

int main() {
    int t;
    scanf("%d", &t);

    for(int i = 0; i < t; i++) {
        int n;
        scanf("%d", &n);

        int arr[n];
        for(int j = 0; j < n; j++) {
            scanf("%d", &arr[j]);
        }

        int arr2[n];
        for(int j = 0; j < n; j++) {
            arr2[j] = arr[j];
        }

        selectionSort(arr2, n);

        for(int j = 0; j < n; j++) {
            printf("%d ", abs(arr2[j] - arr[j]));
        }
        printf("\n");
    }

    return 0;
}
