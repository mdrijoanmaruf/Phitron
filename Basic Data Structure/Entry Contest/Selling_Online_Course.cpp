#include <bits/stdc++.h>
using namespace std;

int main() {
    long long price;
    cin >> price;

    if(price == 0){
        cout << 0 << endl;
        return 0;
    }

    long long ans = (500 + price - 1) / price;
    cout << ans << endl;

    return 0;
}
