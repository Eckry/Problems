#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define optimize()              \
  cin.tie(0);                   \
  cin.sync_with_stdio(0);       \
  ios_base::sync_with_stdio(0); \
  cout.tie(0);

vector<int> w;
vector<vector<int>> edg;
vector<bool> vis(1e6, 0);
vector<int> dfn;
vector<int> nfd;
vector<int> low;
int id;
void dfs(int n)
{
  if (vis[n])
    return;
  vis[n] = 1;
  dfn[n] = ++id;
  nfd[id] = n;
  for (auto v : edg[n])
    dfs(v);
  vis[n] = 0;
  low[n] = id;
}
void solve()
{
  int n;
  cin >> n;
  id = 0;
  low = vector<int>(n + 1);
  nfd = vector<int>(n + 1);
  dfn = vector<int>(n + 1);
  w = vector<int>(n + 1);
  edg = vector<vector<int>>(n + 1);
  for (int i = 1; i <= n; i++)
    cin >> w[i];
  for (int i = 0; i < n - 1; i++)
  {
    int u, v;
    cin >> u >> v;
    edg[u].push_back(v);
    edg[v].push_back(u);
  }

  dfs(1);

  vector<int> pre(n + 2, 0);
  vector<int> suff(n + 2, 0);
  for (int i = 1; i <= n; i++)
    pre[i] = max(pre[i - 1], w[nfd[i]]);
  for (int i = n; i > 0; i--)
    suff[i] = max(suff[i + 1], w[nfd[i]]);
  int mx = 0;
  for (int i = 1; i <= n; i++)
  {
    if (max(pre[dfn[i] - 1], suff[low[i] + 1]) > w[i] && w[i] > w[mx])
    {
      mx = i;
    }
  }
  cout << mx << "\n";
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