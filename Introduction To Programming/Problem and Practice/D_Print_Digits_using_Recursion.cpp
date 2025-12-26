#include <iostream>
using namespace std;

void printSep(long long n) {
    if (n < 10) {
        cout << n << " ";
        return;
    }
    printSep(n / 10);
    cout << n % 10 << " ";
}

int main() {
    int n;
    cin >> n;
    long long arr[n];

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    for(int i = 0; i < n; i++){
        printSep(arr[i]);
        cout << endl;
    }
    return 0;
}