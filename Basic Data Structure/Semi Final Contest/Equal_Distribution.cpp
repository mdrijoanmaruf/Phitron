#include <bits/stdc++.h>
using namespace std;

int main() {
    long long s, c;
    cin >> s >> c;

    if (s == 0) {
        cout << 0 << " " << c << endl;
        return 0;
    }

    long long x = c / s;
    long long y = c - s * x;

    cout << x << " " << y << endl;

    return 0;
}
