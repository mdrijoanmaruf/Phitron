#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    getline(cin, s);

    for(int i = 0; s[i] != '\\'; i++){
        cout << s[i] ;
    }
    return 0;
}