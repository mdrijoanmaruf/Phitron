#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int count = 0;

    vector<int> v1(n);

    // for(int i = 0; i < v1.size(); i++){
    //     cin >> v1[i];
    // }

    for(int &x : v1){
        cin >> x;
    }
    for(int i = 0; i < v1.size(); i++){
        for(int j = 0; j < v1.size(); j++){
            if(v1[i] + 1 == v1[j] ){
                count++;
                break;
            }
        }
    }

    cout << count << endl;

    
    return 0;
}   