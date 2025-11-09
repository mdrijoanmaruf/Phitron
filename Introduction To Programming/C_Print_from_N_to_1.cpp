#include <iostream>
using namespace std;

void printCount(int n, int c = 0){
    if(c == n){
        return;
    }
    printCount(n ,c+1);
    if(c == 0){
        cout << c+1;
    } else{
        cout << c+1 << " ";
    }
}

int main() {
    int n;
    cin >> n;
    printCount(n);
    return 0;
}