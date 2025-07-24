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
    ll n;
    cin >> n;
    string s;
    cin >> s;

    ll sub = 0;
    ll minus = 0;
    for (auto c : s)
    {
        if (c == '_')
            sub++;
        if (c == '-')
            minus++;
    }

    if (sub == 0 || minus <= 1)
    {
        cout << 0 << "\n";
        return;
    }

    ll ans = 1;
    if (minus & 1)
    {
        minus = minus / 2 * ((minus + 1) / 2);
    }
    else
    {
        minus = (minus / 2) * (minus / 2);
    }

    ans = minus * sub;
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