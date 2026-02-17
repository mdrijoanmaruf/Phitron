#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<long long> a(n+1);
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    
    const long long MOD = 1000000007LL;
    vector<pair<long long,int>> vp;
    vp.reserve(n);
    for(int i = 1; i <= n; i++) vp.emplace_back(a[i], i);
    
    sort(vp.begin(), vp.end(), [](const pair<long long,int> &x, const pair<long long,int> &y){
        if(x.first != y.first) return x.first < y.first;
        return x.second < y.second;
    });
    
    long long total = 0;
    int i = 0;
    while(i < n) {
        long long val = vp[i].first;
        long long cnt = 0;
        long long prev = 0;
        int j = i;
        while(j < n && vp[j].first == val) {
            int idx = vp[j].second;
            long long left_choices = idx - prev;
            long long right_choices = n - idx + 1;
            cnt = (cnt + (left_choices % MOD) * (right_choices % MOD)) % MOD;
            prev = idx;
            j++;
        }
        long long val_mod = ((val % MOD) + MOD) % MOD;
        total = (total + val_mod * cnt) % MOD;
        i = j;
    }
    
    cout << total << endl;
    return 0;
}