#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n;
    cin >> n;
    vector<long long> arr(n);

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    vector<long long> prefixSum(n);
    prefixSum[0] = arr[0];
    for(int i = 1; i < n; i++){
        prefixSum[i] = prefixSum[i - 1] + arr[i];
    }

    reverse(prefixSum.begin() , prefixSum.end());

    for(int i = 0; i < n; i++){
        cout << prefixSum[i] << " ";
    }
    return 0;
}