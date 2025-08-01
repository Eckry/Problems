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
    vector<vector<ll>> a(n, vector<ll>(2));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cin >> a[i][j];
        }
    }
    vector<ll> ans;
    for (int i = 0; i < n; i++)
    {
        int flg = 0;
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                continue;
            if (a[i][0] >= a[j][0] && a[j][1] >= a[i][1])
            {
                flg = 1;
                break;
            }
        }

        if (!flg)
            ans.push_back(i + 1);
    }
    cout << ans.size() << "\n";
    for (auto c : ans)
    {
        cout << c << " ";
    }
    cout << "\n";
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
