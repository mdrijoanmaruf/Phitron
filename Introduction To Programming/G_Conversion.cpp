#include <iostream>
using namespace std;

int main() {
    string s;
    getline(cin, s);

    for (int i = 0; i < s.length(); i++) {  
        if (s[i] >= 'a' && s[i] <= 'z') {
            s[i] = s[i] - 32;               
        } 
        else if (s[i] >= 'A' && s[i] <= 'Z') {
            s[i] = s[i] + 32;               
        } 
        else if (s[i] == ',') {
            s[i] = ' ';                    
        }
    }

    cout << s << endl;
    return 0;
}
