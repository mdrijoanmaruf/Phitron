#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    

    while(n--){
        int x;
        string s;
        cin >> x >> s;

        int total = 0;

        vector<int> arr(26 , 0);
        for(int i = 0; i < x; i++){
            char ch = s[i];
            char charToIndex = ch - 'A';

            if(arr[charToIndex] == 0){
                total += 2;
                arr[charToIndex] = 1;
            } else{

                total+= 1;
            }
        }

        cout << total << endl;




    }
    return 0;
}