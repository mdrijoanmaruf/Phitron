#include <iostream>
using namespace std;

void rec(int n , int c = 0){
    if(c == n){
        return;
    }
    cout << "I love Recursion" <<  endl;
    rec(n , c+1);
}

int main() {
    int n;
    cin >> n;

    rec(n);
    return 0;
}