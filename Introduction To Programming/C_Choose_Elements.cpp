#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    long long arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    
    sort(arr, arr + n, greater<long long>());

    long long maxSum = 0;
    for(int i = 0; i < k && arr[i] > 0; i++){ // only add positive elements
        maxSum += arr[i];
    }

    cout << maxSum << endl;
    
    return 0;
}
