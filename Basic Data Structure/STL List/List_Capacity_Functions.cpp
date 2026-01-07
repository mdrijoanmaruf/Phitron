#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> v = {10, 20, 30, 40};

    list<int> l2(v.begin(), v.end());

    for(int it : l2){
        cout << it << endl;
    }
    return 0;
}