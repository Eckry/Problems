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
    vector<int> s(n);
    for (auto &c : s)
        cin >> c;

    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 0)
            ans++;
        ans += s[i];
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