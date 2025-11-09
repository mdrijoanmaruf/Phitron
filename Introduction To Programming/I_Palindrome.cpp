#include <iostream>
using namespace std;

int main() {
    string s;
    getline(cin , s);
    int i = 0;
    int j = s.length() - 1;

    while (i < j)
    {
        if(s[i] != s[j]){
            cout << "NO" << endl;
            return 0;
        }
        i++;
        j--;
    }
    cout << "YES" << endl;
    
    
    return 0;
}