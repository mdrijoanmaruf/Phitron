#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    string s2 = "EGYPT";
    int i = 0, j = 0;

    while(true){
        int pos = s.find(s2);
        if(pos == string::npos){
            break;
        }
        s.replace(pos ,s2.length() , " ");
    }
    cout << s << endl;
    return 0;
}