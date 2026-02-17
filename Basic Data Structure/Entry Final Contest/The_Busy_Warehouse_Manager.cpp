#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    long long q;
    cin >> q;
    
    vector<pair<long long,long long>> inventory; // {product_id, count}
    inventory.reserve(1024);
    
    while(q--) {
        long long type;
        cin >> type;
        
        if(type == 1) {
            long long x;
            cin >> x;
            bool found = false;
            for(auto &p : inventory) {
                if(p.first == x) { p.second++; found = true; break; }
            }
            if(!found) inventory.emplace_back(x, 1LL);
        }
        else {
            if(inventory.empty()) {
                cout << "empty" << '\n';
            }
            else {
                long long max_count = 0LL;
                long long max_product = -1;
                long long idx = -1;
                for(int i = 0; i < (int)inventory.size(); ++i) {
                    long long prod = inventory[i].first;
                    long long cnt = inventory[i].second;
                    if(cnt > max_count || (cnt == max_count && prod > max_product)) {
                        max_count = cnt;
                        max_product = prod;
                        idx = i;
                    }
                }
                cout << max_product << '\n';
                if(idx != -1) {
                    inventory[idx] = inventory.back();
                    inventory.pop_back();
                }
            }
        }
    }
    
    return 0;
} 