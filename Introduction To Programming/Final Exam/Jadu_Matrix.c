#include <stdio.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int arr[n][m];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {

            if (i == j) {
                if (arr[i][j] != 1) {
                    printf("NO\n");
                    return 0;
                }
            }
            else if (i == m - j - 1) {
                if (arr[i][m - 1 - i] != 1) {
                    printf("NO\n");
                    return 0;
                }
            } 
            else {
                if (arr[i][j] != 0) {
                    printf("NO\n");
                    return 0;
                }
            }
        }
    }

    printf("YES\n");
    return 0;
}
