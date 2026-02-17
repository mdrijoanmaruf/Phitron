#include <bits/stdc++.h>
using namespace std;

int main() {
    long long t;
    cin >> t;
    
    while(t--) {
        long long n, m;
        cin >> n >> m;
        
        vector<long long> a(n), b(m);
        
        for(long long i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        for(long long i = 0; i < m; i++) {
            cin >> b[i];
        }
        
        long long k;
        cin >> k;
        
        long long count = 0;
        for(long long i = 0; i < n; i++) {
            for(long long j = 0; j < m; j++) {
                if(a[i] + b[j] == k) {
                    count++;
                }
            }
        }
        
        cout << count << endl;
    }
    
    
    return 0;
}
