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
    vector<int> ans(n);
    for (int i = 0; i < n; i++)
    {
        ans[i] = n - p[i] + 1;
    }
    for (auto c : ans)
        cout << c << " ";
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