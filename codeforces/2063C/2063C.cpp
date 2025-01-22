#include <bits/stdc++.h>

using namespace std;

#define optimize()              \
  cin.tie(0);                   \
  cin.sync_with_stdio(0);       \
  ios_base::sync_with_stdio(0); \
  cout.tie(0);

void solve()
{
  int n;
  cin >> n;
  vector<vector<int>> edg(n + 1, vector<int>());
  multiset<int> con;
  for (int i = 0; i < n - 1; i++)
  {
    int u, v;
    cin >> u >> v;
    edg[u].push_back(v);
    edg[v].push_back(u);
  }

  for (int i = 1; i <= n; i++)
    con.insert(edg[i].size());

  int ans = 0;
  for (int i = 1; i <= n; i++)
  {
    int cur = edg[i].size();
    con.erase(con.find(cur));
    for (auto v : edg[i])
    {
      int sz = edg[v].size();
      con.insert(sz - 1);
      con.erase(con.find(sz));
    }

    cur += *con.rbegin();

    for (auto v : edg[i])
    {
      int sz = edg[v].size();
      con.insert(sz);
      con.erase(con.find(sz - 1));
    }
    con.insert(edg[i].size());
    ans = max(cur - 1, ans);
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