#include <bits/stdc++.h>

using namespace std;

#define ll long long

#define optimize()                \
    cin.tie(0);                   \
    cin.sync_with_stdio(0);       \
    ios_base::sync_with_stdio(0); \
    cout.tie(0);

vector<vector<int>> g(5001, vector<int>(5001));

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &c : a)
        cin >> c;
    int k = 0, m = 0;
    for (int i = 0; i < n; i++)
    {
        k = g[k][a[i]];
    }
    vector<int> f(5001, 10000);
    for (int i = 0; i < n; i++)
    {
        a[i] /= k;
        m = max(a[i], m);
        f[a[i]] = 0;
    }

    for (int x = m; x >= 1; x--)
    {
        for (int i = 0; i < n; i++)
        {
            f[g[a[i]][x]] = min(f[g[a[i]][x]], f[x] + 1);
        }
    }

    int ans = max(f[1] - 1, 0);
    for (int i = 0; i < n; i++)
        if (a[i] != 1)
            ans++;
    cout << ans << "\n";
}

int main(void)
{
    optimize();
    int T;
    cin >> T;

    for (int i = 0; i < 5001; i++)
        g[i][i] = g[0][i] = g[i][0] = i;

    for (int i = 1; i < 5001; i++)
    {
        for (int j = 1; j < 5001; j++)
        {
            g[i][j] = g[j][i] = g[j][i % j];
        }
    }
    // T = 1;
    while (T--)
        solve();
}