#include <bits/stdc++.h>
using namespace std;

int main() {

    int n;
    cin >> n;

    vector<long long> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    vector<int> silent(n + 1, 0);
    for (int i = 2; i <= n - 1; i++) {
        if (a[i] < a[i - 1] && a[i] < a[i + 1]) {
            silent[i] = 1;
        }
    }

    vector<int> pref(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        pref[i] = pref[i - 1] + silent[i];
    }

    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;

        int left = max(l, 2);
        int right = min(r, n - 1);

        if (left > right) {
            cout << 0 << endl;
        } else {
            cout << pref[right] - pref[left - 1] << endl;
        }
    }

    return 0;
}
