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
    ll a, b;
    cin >> a >> b;
    ll k = 1LL;
    if (a & 1LL)
    {
        if (b & 1LL)
        {
            k = b;
            cout << a * k + 1LL << "\n";
        }
        else
        {
            ll p = b;
            ll cnt = 0LL;
            while (p % 2LL == 0LL)
            {
                cnt++;
                p /= 2LL;
            }
            if (cnt == 1LL)
            {
                cout << -1 << "\n";
            }
            else
            {
                k = b / 2LL;
                cout << a * k + 2LL << " " << "\n";
            }
        }
    }
    else
    {
        ll p = b;
        ll cnt = 0LL;
        while (p % 2LL == 0LL)
        {
            cnt++;
            p /= 2LL;
        }
        if (cnt == 0LL)
        {
            cout << -1 << "\n";
        }
        else
        {
            k = b / 2LL;
            cout << k * a + 2LL << "\n";
        }
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