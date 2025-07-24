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
    ll n, k, x;
    cin >> n >> k >> x;
    vector<ll> a(n);
    for (auto &c : a)
        cin >> c;

    reverse(a.begin(), a.end());

    ll sm = 0;
    ll i = 0;
    while (i < n && sm < x)
    {
        sm += a[i];
        i++;
        if (sm >= x)
        {
            cout << n * k - i + 1 << "\n";
            return;
        }
    }
    if (i != n)
    {
        cout << n * k - i + 1 << "\n";
        return;
    }

    if (sm * k < x)
    {
        cout << 0 << "\n";
        return;
    }

    ll p = x / sm;

    sm *= p;
    i *= p;

    for (ll j = 0; j < n; j++)
    {
        if (sm >= x)
            break;
        sm += a[j];
        i++;
    }
    cout << n * k - i + 1 << "\n";
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