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
    int n;
    cin >> n;
    vector<int> d(n);
    vector<int> s(n);
    for (int i = 0; i < n; i++)
    {
        cin >> d[i] >> s[i];
    }
    int ans = 300;
    for (int i = 0; i < n; i++)
    {
        ans = min(ans, d[i] + (s[i] - 1) / 2);
    }
    cout << ans << "\n";
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