#include <iostream>
using namespace std;

long long sumArr(long long arr[], int n, int c = 0, long long sum = 0) {
    if (c == n) {
        return sum;
    }
    sum += arr[c];
    return sumArr(arr, n, c + 1, sum);
}

int main() {
    int n;
    cin >> n;

    long long arr[n];

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    cout << sumArr(arr , n);
    return 0;
}