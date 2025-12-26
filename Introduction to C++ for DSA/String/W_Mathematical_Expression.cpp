#include <bits/stdc++.h>
using namespace std;

int main() {
    int a , b , c;
    char sign , equal;

    cin >> a >> sign >> b >> equal >> c;

    if(sign == '+') {
        if(a + b == c) {
            cout << "Yes" << endl;
        } else {
            cout << a + b << endl;
        }
    } else if(sign == '-') {
        if(a - b == c) {
            cout << "Yes" << endl;
        } else {
            cout << a - b << endl;
        }
    } else if(sign == '*') {
        if(a * b == c) {
            cout << "Yes" << endl;
        } else {
            cout << a * b << endl;
        }
    }
    return 0;
}