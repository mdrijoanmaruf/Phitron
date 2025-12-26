#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> v1(n);

    for(int i = 0; i < v1.size(); i++){
        cin >> v1[i];
        // cout << v1[i] << " ";
    }
    for(int i = 0; i < n/2 ; i++){
        swap(v1[i] , v1[v1.size() - i - 1]);
    }
    for(int i = 0; i < v1.size(); i++){
        cout << v1[i] << " ";
    }
    return 0;
}