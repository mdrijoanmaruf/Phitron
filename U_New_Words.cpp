#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    transform(s.begin() , s.end() , s.begin() , ::toupper);

    int arr[5] = {0};
    string s2 = "EGYPT";
    
    for(int i = 0; i < 5; i++){
        int count = 0;
        for(int j = 0; j < s.size(); j++){
            if(s2[i] == s[j]){
                count++;
            }
        }
        arr[i] = count;
    }

    int min = 0;
    for(int i = 0; i < 5; i++){
        if(arr[i] < arr[min]){
            min = i;
        }
    }
    
    cout << arr[min] << endl;
    return 0;
}