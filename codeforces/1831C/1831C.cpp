#include <bits/stdc++.h>

using namespace std;

#define optimize()              \
  cin.tie(0);                   \
  cin.sync_with_stdio(0);       \
  ios_base::sync_with_stdio(0); \
  cout.tie(0);

vector<vector<pair<int, int>>> g;
vector<int> ids;
vector<int> dp;
int ans;

void dfs(int u)
{
  for (auto c : g[u])
  {
    if (dp[c.first] == 0)
    {
      dp[c.first] = dp[u] + (c.second <= ids[u]);
      ids[c.first] = c.second;
      ans = max(dp[c.first], ans);
      dfs(c.first);
    }
  }
}

void solve()
{
  int n;
  cin >> n;
  g = vector<vector<pair<int, int>>>(n + 1, vector<pair<int, int>>());
  ids = vector<int>(n + 1, 0);
  dp = vector<int>(n + 1, 0);
  ans = 0;

  dp[1] = 1;
  for (int i = 0; i < n - 1; i++)
  {
    int a, b;
    cin >> a >> b;
    g[a].push_back({b, i + 1});
    g[b].push_back({a, i + 1});
  }

  dfs(1);

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