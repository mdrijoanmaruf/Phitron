#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--){
        int size;
        cin >> size;
        string s;
        cin >> s;

        int count = 0;
        for(char c : s){
            if(c == '1'){
                count++;
            }
        }

        int ans = 0;
        for(char c : s){
            if(c == '1'){
                ans = ans + count - 1;
            } else {
                ans = ans + count + 1;
            }
        }

        cout << ans << endl;
    }
    return 0;
}