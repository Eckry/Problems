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
    int j = 0;
    int k = n - 1;
    string ans = "";
    int flg = 0;
    for (int i = 0; i < n && j <= k; i++)
    {
        if (flg)
        {
            if (p[j] > p[k])
            {
                ans += "L";
                j++;
            }
            else
            {
                ans += "R";
                k--;
            }
            flg = 0;
        }
        else
        {
            if (p[j] < p[k])
            {
                ans += "L";
                j++;
            }
            else
            {
                ans += "R";
                k--;
            }
            flg = 1;
        }
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