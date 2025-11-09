#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int maxNum = -1000000000;  
    bool check = false;        

    for (int i = 0; i < n; i++) {
        int x = arr[i];
        check = false;  // reset for each number

        // Only check perfect square if number is non-negative
        if (x >= 0) {
            for (int j = 0; j * j <= x; j++) {
                if (j * j == x) {
                    check = true;  // it's a perfect square
                    break;
                }
            }
        }

        // If not a perfect square, update max
        if (!check && x > maxNum) {
            maxNum = x;
        }
    }

    cout << maxNum << endl;
    return 0;
}
