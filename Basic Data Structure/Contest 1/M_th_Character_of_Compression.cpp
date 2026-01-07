#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    int x;
    cin >> x;

    string s2;

    for(int i = 0; i < s.size(); i++){
        char ch = s[i];

        if(isalpha(ch)){
            int repeat = 1;

            if(i + 1 < s.size() && isdigit(s[i + 1])){
                repeat = s[i + 1] - '0';
                i++; 
            }

            for(int j = 0; j < repeat; j++){
                s2.push_back(ch);
            }
        }
    }

    cout << s2[x - 1] << endl;
    return 0;
}
