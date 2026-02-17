#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        sort(arr.begin(), arr.end());
        if ((arr.front() + arr.back()) % 2 == 0)
        {
            cout << 0 << endl;
            continue;
        }

        int ans = n;

        // Remove from left
        for (int i = 0; i < n; i++)
        {
            if (arr[i] % 2 == arr.back() % 2)
            {
                ans = min(ans, i);
                break;
            }
        }

        // Remove from right
        for (int i = n - 1; i >= 0; i--)
        {
            if (arr[i] % 2 == arr.front() % 2)
            {
                ans = min(ans, n - 1 - i);
                break;
            }
        }

        cout << ans << endl;
    }

    return 0;
}
