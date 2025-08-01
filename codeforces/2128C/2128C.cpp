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
    vector<ll> b(n);
    for (auto &c : b)
        cin >> c;

    int mn = 0;
    int secondmn = 0;
    int seen = 0;
    for (int i = 0; i < n; i++)
    {
        if (b[mn] > b[i])
        {
            secondmn = mn;
            mn = i;
        }
        if (b[i] == 2 && seen)
        {
            cout << "NO" << "\n";
            return;
        }
        if (b[i] == 1)
        {
            seen = 1;
            continue;
        }
        ll l = (b[i] - 1) / 2;
        ll r = (b[i] + 1) / 2 + (b[i] % 2 == 0);
        if (r > b[mn])
        {
            if (i != mn)
            {
                cout << "NO" << "\n";
                return;
            }
            if (r > b[secondmn])
            {
                cout << "NO" << "\n";
                return;
            }
        }
    }
    cout << "YES" << "\n";
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