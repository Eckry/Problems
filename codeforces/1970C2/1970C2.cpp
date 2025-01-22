#include <bits/stdc++.h>

using namespace std;

#define optimize()              \
  cin.tie(0);                   \
  cin.sync_with_stdio(0);       \
  ios_base::sync_with_stdio(0); \
  cout.tie(0);

vector<vector<int>> g;
int x;
void dfs(int p, int n, vector<int> &distance)
{
  if (x != n && g[n].size() == 1)
  {
    distance[n] = 0;
  }
  else
  {
    bool flg = 1;
    for (auto c : g[n])
    {
      if (c != p)
      {

        dfs(n, c, distance);
        if (!distance[c])
        {
          flg = 0;
        }
      }
    }
    if (!flg)
    {
      distance[n] = 1;
    }
    else
      distance[n] = 0;
  }
}

void solve()
{
  int n, t;
  cin >> n;
  cin >> t;
  g = vector<vector<int>>(n + 1, vector<int>());
  vector<int> distance(n + 1, -1);

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
  //   cout << distance[i] << " ";
  // }
  // cout << "\n";

  if (distance[x])
  {
    cout << "Ron" << "\n";
  }
  else
    cout << "Hermione" << "\n";
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