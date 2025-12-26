#include <iostream>
using namespace std;

int main() {
    long long N;
    cin >> N;

    long long count = 0;
    while (N > 1) {
        N /= 2;
        count++;
    }

    cout << count << endl;
    return 0;
}
