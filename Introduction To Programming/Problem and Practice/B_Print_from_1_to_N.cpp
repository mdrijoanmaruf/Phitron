#include <iostream>
using namespace std;

void printCount(int n, int c = 0){
    if(c == n){
        return;
    }
    cout << c+1 << endl;
    printCount(n ,c+1);
}

int main() {
    int n;
    cin >> n;
    printCount(n);
    return 0;
}