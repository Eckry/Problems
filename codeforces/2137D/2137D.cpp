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
    vector<int> b(n);
    for (auto &c : b)
        cin >> c;

    map<int, pair<int, int>> mp;
    map<int, int> appear;
    vector<int> ans;
    int used = 1;
    for (int i = 0; i < n; i++)
    {
        if (!mp.count(b[i]))
        {
            mp[b[i]] = make_pair(used, b[i]);
            used++;
        }
        if (mp[b[i]].second == 0)
        {
            mp[b[i]] = make_pair(used, b[i]);
            used++;
        }
        int x = mp[b[i]].first;
        ans.push_back(x);
        appear[x]++;
        mp[b[i]].second--;
    }

    for (int i = 0; i < n; i++)
    {
        if (appear[ans[i]] == b[i])
            continue;
        cout << -1 << "\n";
        return;
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