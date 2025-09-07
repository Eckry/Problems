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
    int k, p;
    cin >> k >> p;
    vector<int> a(p);
    for (auto &c : a)
    {
        cin >> c;
    }
    vector<int> dp(50001, INT_MAX);
    dp[0] = 0;
    for (int i = 0; i < 50001; i++)
    {
        for (int j = 0; j < p; j++)
        {
            if (i - a[j] >= 0)
            {
                dp[i] = min(dp[i], dp[i - a[j]]);
            }
            else
            {
                dp[i] = min(dp[i], abs(i - a[j]));
            }
        }
    }
    while (k--)
    {
        int n;
        cin >> n;
        cout << dp[n] << "\n";
    }
}

int main(void)
{
    optimize();
    int T;
    T = 1;
    while (T--)
        solve();
}