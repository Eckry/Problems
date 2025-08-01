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
    vector<int> p(n);
    for (auto &c : p)
        cin >> c;

    vector<ll> f(n, 0);
    f[0] = 1;
    f[1] = 1;
    if (p[0] > p[1])
        f[1] += 2;
    else f[1]++;

    for (int i = 2; i < n; i++)
    {
        if (p[i - 2] > p[i - 1] && p[i - 1] > p[i])
        {
            f[i] = f[i - 1] + i + 1;
        }
        else if (p[i - 2] > p[i - 1] && p[i - 1] < p[i])
        {
            f[i] = f[i - 2] + i + 1;
        }
        else if (p[i - 2] < p[i - 1] && p[i - 1] > p[i])
        {
            f[i] = f[i - 1] + i + 1;
        }
        else if (p[i - 2] < p[i - 1] && p[i - 2] > p[i])
        {
            f[i] = max(f[i - 1] + i + 1, f[i - 2] + i + 1);
        }
    }
    ll ans = 0;
    for (auto c : f)
    {
        ans += c;
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