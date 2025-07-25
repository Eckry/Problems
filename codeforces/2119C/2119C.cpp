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
    ll n, l, r, k;
    cin >> n >> l >> r >> k;

    if (n & 1)
    {
        cout << l << "\n";
        return;
    }

    string s1 = "";
    while (r)
    {
        if (r & 1)
            s1 = '1' + s1;
        else
            s1 = '0' + s1;
        r >>= 1;
    }
    string s2 = "";
    ll temp = l;
    if (n == 2)
    {
        cout << -1 << "\n";
        return;
    }
    while (temp)
    {
        if (temp & 1)
            s2 = '1' + s2;
        else
            s2 = '0' + s2;
        temp >>= 1;
    }
    if (s1.size() == s2.size())
    {
        cout << -1 << "\n";
        return;
    }

    if (k <= n - 2)
    {
        cout << l << "\n";
        return;
    }

    ll ans = (1LL << s2.size());
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