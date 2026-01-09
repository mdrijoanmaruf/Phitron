#include <bits/stdc++.h>
using namespace std;

int main() {
    stack<int> st;

    int n;
    cin >>  n;

    while(n--){
        int x;
        cin >> x;
        st.push(x);
    }

    while(true){
        if(st.empty()){
            break;
        }
        cout << st.top() << endl;
        st.pop();
        
    }
    return 0;
}