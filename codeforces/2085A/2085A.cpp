#include <bits/stdc++.h>

using namespace std;

#define ll long long

#define optimize()                \
    cin.tie(0);                   \
    cin.sync_with_stdio(0);       \
    ios_base::sync_with_stdio(0); \
    cout.tie(0);

void solve()
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    char mx = s[0];
    int diff = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] != s[0])
            diff = 1;
        if (mx < s[i])
            mx = s[i];
    }

    if (diff && k >= 1)
        cout << "YES" << "\n";
    else
    {
        string p = s;
        reverse(p.begin(), p.end());

        if (p > s)
        {
            cout << "YES" << "\n";
        }
        else
            cout << "NO" << "\n";
        }
}

int main(void)
{
    optimize();
    int T;
    cin >> T;
    // T = 1;
    while (T--)
        solve();
}