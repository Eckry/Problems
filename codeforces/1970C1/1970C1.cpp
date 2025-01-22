#include <bits/stdc++.h>
 
using namespace std;
 
#define optimize()              \
  cin.tie(0);                   \
  cin.sync_with_stdio(0);       \
  ios_base::sync_with_stdio(0); \
  cout.tie(0);
 
vector<vector<int>> g;
int x;
void dfs(int p, int n, vector<vector<int>> &distance)
{
  if (x != n && g[n].size() == 1)
  {
    distance[n].push_back(0);
    return;
  }
  for (auto c : g[n])
  {
    if (c != p)
    {
      dfs(n, c, distance);
      distance[n].push_back(distance[c][0] + 1);
    }
  }
}
 
void solve()
{
  int n, t;
  cin >> n;
  cin >> t;
  g = vector<vector<int>>(n + 1, vector<int>());
  vector<vector<int>> distance(n + 1, vector<int>());
 
  for (int i = 0; i < n - 1; i++)
  {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  cin >> x;
 
  dfs(-1, x, distance);
 
  // for (int i = 1; i <= n; i++)
  // {
  //   for (auto d : distance[i])
  //     cout << i << " " << d << "\n";
  // }
  // cout << "\n";
  if (distance[x].size() == 2)
  {
    if (distance[x][0] % 2 == 0 && distance[x][1] % 2 == 0)
      cout << "Hermione" << "\n";
    else
      cout << "Ron" << "\n";
  }
  else
  {
    if (distance[x][0] % 2 == 0)
    {
      cout << "Hermione" << "\n";
    }
    else
      cout << "Ron" << "\n";
  }
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