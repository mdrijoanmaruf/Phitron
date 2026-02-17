
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> v1(n);
    vector<int> v2(n);
    vector<int> v3(n+n);

    for(int i = 0; i < v1.size(); i++){
        cin >> v1[i];
    }
    for(int i = 0; i < v1.size(); i++){
        cin >> v2[i];
    }

    v3 = v2;
    
    for(int i = 0; i < v1.size(); i++){
        v3.push_back(v1[i]);
    }
    for(int i = 0; i < v3.size(); i++){
        cout << v3[i] << " ";
    }
    return 0;
}