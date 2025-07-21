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
    vector<int> seen(1601, 0);
    int n;
    cin >> n;
    vector<int> ans(1, -1);
    vector<vector<int>> g(n, vector<int>(n));

    for (auto &c : g)
        for (auto &d : c)
            cin >> d;
    for (int i = 0; i < n; i++)
    {
        ans.push_back(g[0][i]);
        seen[g[0][i]] = 1;
    }
    for (int i = 1; i < n; i++)
    {
        ans.push_back(g[i][n - 1]);
        seen[g[i][n - 1]] = 1;
    }

    for (int i = 1; i <= n * 2; i++)
    {
        if (!seen[i])
        {
            ans[0] = i;
            break;
        }
    }
    for (auto c : ans)
        cout << c << " ";
    cout << " \n";
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