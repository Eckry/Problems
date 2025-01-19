#include <bits/stdc++.h>

using namespace std;

#define optimize()              \
  cin.tie(0);                   \
  cin.sync_with_stdio(0);       \
  ios_base::sync_with_stdio(0); \
  cout.tie(0);

vector<int> visited;
int id;

void dfs(int a, vector<vector<int>> &G)
{
  visited[a] = id;
  for (auto &c : G[a])
  {
    if (!visited[c])
      dfs(c, G);
  }
}

void solve()
{
  int n, m1, m2;
  cin >> n >> m1 >> m2;
  visited = vector<int>(n + 1);
  vector<pair<int, int>> edges_f(m1);
  vector<pair<int, int>> edges_g(m2);
  vector<vector<int>> g(n + 1, vector<int>());
  vector<vector<int>> f(n + 1, vector<int>());

  id = 1;
  for (auto &[u, v] : edges_f)
  {
    cin >> u >> v;
  }

  for (auto &[u, v] : edges_g)
  {
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  int comps_g = 0;
  for (int i = 1; i <= n; i++)
  {
    if (!visited[i])
    {
      dfs(i, g);
      id++;
      comps_g++;
    }
  }

  int ans = 0;
  for (auto &[u, v] : edges_f)
  {
    if (visited[v] != visited[u])
    {
      ans++;
    }
    else
    {
      f[u].push_back(v);
      f[v].push_back(u);
    }
  }

  int comps_f = 0;
  visited = vector<int>(n + 1);
  for (int i = 1; i <= n; i++)
  {
    if (!visited[i])
    {
      dfs(i, f);
      comps_f++;
    }
  }

  ans += comps_f - comps_g;
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