#include <iostream>
using namespace std;

int main() {
    string s1 , s2;
    cin >> s1 , s2;

    for(int i = 0; i < s1.length(); i++){
        if(s1[i] > s2[i]){
            cout << s1 << endl;
            return 0;
        }
        else if(s1[i] < s2[i]){
            cout << s2 << endl;
            return 0;
        }
        else if(s1[i] == s2[i]){
            continue;
        }
    }

    
    return 0;
}