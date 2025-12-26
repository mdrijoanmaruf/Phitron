#include <iostream>
#include <string>

using namespace std;

int printVowels(string s , int c = 0 , int count = 0){
    if(s[c] == '\0'){
        return count;
    }

    string v = "aeiouAEIOU";

    for(int i = 0; v[i] != '\0'; i++){
        if(s[c] == v[i]){
            count++;
            break;
        }
    }


    return printVowels(s , c+1 , count);
    
}

int main() {
    string s;
    getline(cin , s);

    cout << printVowels(s) << endl;
    return 0;
}