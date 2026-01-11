#include <bits/stdc++.h>
using namespace std;

class myQueue{
    public:
    list<int> l;
    int sz = 0;

    void push(int val){  
        l.push_back(val);
    }

    void pop(){
        l.pop_back();
    }

    int front(){
        return l.front();
    }

    int back(){
        return l.back();
    }

    int size(){
        return l.size();
    }

    bool empty(){
        return l.empty();
    }


};

int main() {
    myQueue q;
    int n;
    cin >> n;
    while(n--){
        int x;
        cin >> x;
        q.push(x);
    }

    
    return 0;
}