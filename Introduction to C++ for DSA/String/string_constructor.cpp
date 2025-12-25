#include <bits/stdc++.h>
using namespace std;


int main() {
    string s = "Hello";
    // string s2("Hello" , 2);
    // string s3(s , 2);
    // string s4(5, 'A');
    // cout << s4 << endl;

    sort(s.begin() , s.end() , greater<char>());
    cout << s << endl;
    return 0;
}