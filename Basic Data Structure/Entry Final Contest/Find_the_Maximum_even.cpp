#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    vector<long long> even, odd;
    for(int i = 0; i < n; i++) {
        if(arr[i] % 2 == 0) {
            even.push_back(arr[i]);
        } else {
            odd.push_back(arr[i]);
        }
    }
    
    sort(even.begin(), even.end(), greater<long long>());
    sort(odd.begin(), odd.end(), greater<long long>());
    
    long long maxEven = -1;
    
    if(!even.empty()) {
        maxEven = even[0];
    }
    
    if(even.size() >= 2) {
        maxEven = max(maxEven, even[0] + even[1]);
    }
    
    if(odd.size() >= 2) {
        maxEven = max(maxEven, odd[0] + odd[1]);
    }
    
    cout << maxEven << '\n';
    
    return 0;
}