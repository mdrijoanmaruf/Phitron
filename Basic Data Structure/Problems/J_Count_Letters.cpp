// #include <bits/stdc++.h>
// using namespace std;

// int main() {
//     string s;
//     cin >> s;

//     vector<char> c(26 , 'a');
//     vector<int> n(26 , 0);

//     int size = s.size();


//     for(int i = 0; i < 26; i++){
//         c[i] = c[i] + i;
//     }
    
    
//     for(int i = 0; i < s.size(); i++){
//         int count = 0;
//         for(int j = 0; j < s.size(); j++){
//             if(s[i] == s[j]){
//                 // n[s[i]-'a']++;
//                 count++;
//             }
//         }
//         n[s[i]-'a'] = count;
//     }

//     for(int i = 0; i < 26; i++){
//         if(n[i] != 0){
//             cout << c[i] << " : " << n[i] << endl;
//         }
//     }
//     return 0;
// }


#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    vector<int> freq(26, 0);

    for(char ch : s){
        freq[ch - 'a']++;
    }

    for(int i = 0; i < 26; i++){
        if(freq[i] > 0){
            cout << char('a' + i) << " : " << freq[i] << endl;
        }
    }

    return 0;
}
