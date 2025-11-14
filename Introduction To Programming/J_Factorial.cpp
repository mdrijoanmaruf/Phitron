#include <iostream>
using namespace std;

long long fact(int n ){
    if(n == 1){
        return 1;
    }

    long long mul = fact(n - 1);
    return mul * n;
}

int main() {
    int n;
    cin >> n;

    cout << fact(n) << endl;
    return 0;
}