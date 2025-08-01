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
    vector<ll> a(n);
    for (auto &c : a)
        cin >> c;
    ll mn = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[mn] > a[i])
            mn = i;
    }
    ll g = 0;
    for (int i = 0; i < n; i++)
    {
        if (i == mn)
            continue;
        if (a[i] % a[mn] == 0)
        {
            g = __gcd(g, a[i]);
        }
    }
    if (g == a[mn])
        cout << "YES" << "\n";
    else
        cout << "NO" << "\n";
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