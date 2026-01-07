#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    for(int i = 0; i < s.size(); i++){
        char ch = s[i];
        bool check = true;
        for(int j = 0; j < s.size(); j++){
            if(i == j){
                continue;
            }
            else if(s[i] == s[j]){
                check = false;
                break;
            }
        }

        if(check){
            cout << ch << endl;
            return 0;
        }
    }

    cout << -1 << endl;
    return 0;
}