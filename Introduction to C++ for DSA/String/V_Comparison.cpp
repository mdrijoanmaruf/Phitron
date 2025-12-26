#include <bits/stdc++.h>
using namespace std;

int main() {
    int a ;
    char c;
    int b;

    cin >> a ;
    cin >> c;
    cin >> b;

    if(c == '>') {
        if(a > b) {
            cout << "Right" << endl;
        } else {
            cout << "Wrong" << endl;
        }
    } else if(c == '<') {
        if(a < b) {
            cout << "Right" << endl;
        } else {
            cout << "Wrong" << endl;
        }
    } else if(c == '=') {
        if(a == b) {
            cout << "Right" << endl;
        } else {
            cout << "Wrong" << endl;
        }
    }
    return 0;
}