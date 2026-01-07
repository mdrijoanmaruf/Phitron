#include <bits/stdc++.h>
using namespace std;

int main() {
    // list<int> l;
    // cout << l.size() << endl;

    // list<int> l(4, 3);
    list<int> l = {1,2,3,4,5,6};
    // list<int> l2(l);
    int arr[] = {10,20,30,40};
    list<int> l2(arr , arr+4);

    // cout << *l.begin() << endl;
    // cout << *l.end() << endl;

    // for(auto it = l.begin(); it != l.end(); it++){
    //     cout << *it <<endl;
    // }

    for(int v : l2){
        cout << v <<endl;
    }
    return 0;
}