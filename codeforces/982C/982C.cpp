#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define optimize()              \
  cin.tie(0);                   \
  cin.sync_with_stdio(0);       \
  ios_base::sync_with_stdio(0); \
  cout.tie(0);

vector<vector<int>> edg;
vector<int> dp;
int ans;
void dfs(int p, int n)
{
  if (p != -1 && edg[n].size() == 1)
  {
    dp[n] = 1;
    return;
  }
  int cnt = 0;
  for (auto v : edg[n])
  {
    if (v == p)
      continue;

    dfs(n, v);
  }
  for (auto v : edg[n])
  {
    if (v == p)
      continue;
    if (dp[v] == 1)
      cnt++;
  }
  if (cnt & 1)
  {
    dp[n] = 0;
    if (p != -1)
      ans++;
  }
  else
  {
    dp[n] = 1;
  }
}

void solve()
{
  int n;
  cin >> n;
  ans = 0;
  dp = vector<int>(n + 1, 0);
  edg = vector<vector<int>>(n + 1, vector<int>());
  for (int i = 0; i < n - 1; i++)
  {
    int u, v;
    cin >> u >> v;
    edg[u].push_back(v);
    edg[v].push_back(u);
  }
  if (n & 1)
  {
    cout << -1 << "\n";
    return;
  }
  dfs(-1, 1);
  cout << ans << "\n";
}

int main(void)
{
  optimize();
  int T;
  // cin >> T;
  T = 1;
  while (T--)
    solve();
}