#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; 
    cin >> n;

    while(n--){
        string s;
        cin >> s;

        int first3 = 0, last3 = 0;

        for(int i = 0; i < 3; i++){
            int digit = s[i] - '0';
            first3+= digit;
        }
        for(int i = 3; i < 6; i++){
            int digit = s[i] - '0';
            last3+= digit;
        }

        if(first3 == last3){
            cout << "YES" << endl;
        } else{
            cout << "NO" << endl;
        }
    }

    return 0;
}