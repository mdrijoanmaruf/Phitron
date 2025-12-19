#include <iostream>
using namespace std;

int main() {
    string s;
    getline(cin , s);

    // cout << s[0] << endl;
    cout << s.back() << endl;
    cout << s[s.size() - 1] << endl;
    cout << s.front() << endl;
    return 0;
}