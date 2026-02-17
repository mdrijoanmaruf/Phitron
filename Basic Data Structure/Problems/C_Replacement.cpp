#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> v1(n);

    for(int i = 0; i < v1.size(); i++){
        cin >> v1[i];
    }

    for(int i = 0; i < v1.size(); i++){
        if(v1[i] > 0){
            v1[i] = 1;
        }
        else if(v1[i] < 0){
            v1[i] = 2;
        }
    }

    for(int i = 0; i < v1.size(); i++){
        cout << v1[i] << " ";
    }
    return 0;
}   