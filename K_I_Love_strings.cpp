#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        string s1, s2;
        cin >> s1 >> s2;

        size_t i = 0, j = 0;
        string result;

        while (i < s1.size() && j < s2.size())
        {
            result.push_back(s1[i++]);
            result.push_back(s2[j++]);
        }

        while (i < s1.size())
        {
            result.push_back(s1[i++]);
        }
        while (j < s2.size())
        {
            result.push_back(s2[j++]);
        }
        cout << result << endl;
    }

    return 0;
}