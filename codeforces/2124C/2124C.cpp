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

    ll gcd = 0;
    ll __lcm = 1;
    for (int i = n - 1; i >= 0; i--)
    {
        gcd = __gcd(gcd, b[i]);
        __lcm = lcm(__lcm, b[i] / gcd);
    }
    cout << __lcm << "\n";
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