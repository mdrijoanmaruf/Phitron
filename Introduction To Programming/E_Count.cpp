#include <iostream>
using namespace std;

int main() {
    string s;
    getline(cin, s);

    int sum = 0;

    for(int i = 0; s[i] != '\0'; i++){
        sum = sum + s[i] - '0';
    }


    cout << sum << endl;
    return 0;
}