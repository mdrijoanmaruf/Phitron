#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--){
        int x, y , z;
        cin >> x >> y >> z;
        int total = x + y + z;

        if(total % 3 == 0 && y <= total/3){
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}