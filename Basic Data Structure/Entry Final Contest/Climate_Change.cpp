#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> a(n);
    
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    long long total_sum = 0;
    for(int i = 0; i < n; i++) {
        total_sum += a[i];
    }
    
    int count = 0;
    long long prefix_sum = 0;
    
    for(int k = 0; k < n - 1; k++) {
        prefix_sum += a[k];
        long long suffix_sum = total_sum - prefix_sum;
        
        if(prefix_sum == suffix_sum) {
            count++;
        }
    }
    
    cout << count << '\n';
    
    return 0;
}