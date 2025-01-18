#include <bits/stdc++.h>

using namespace std;

#define optimize()              \
  cin.tie(0);                   \
  cin.sync_with_stdio(0);       \
  ios_base::sync_with_stdio(0); \
  cout.tie(0);

long long mx = INT_MIN;
map<long long, vector<long long>> g;
map<long long, int> visited;

void dfs(long long p)
{
  visited[p] = 1;
  mx = max(mx, p);
  if (g[p].size() == 0)
  {
    return;
  }
  else
  {
    for (auto v : g[p])
    {
      if (!visited[v])
        dfs(v);
    }
  }
}

void solve()
{
  int n;
  cin >> n;
  vector<long long> a(n);
  for (auto &c : a)
    cin >> c;

  g.clear();
  visited.clear();
  mx = INT_MIN;

  for (int i = 1; i < n; i++)
  {
    long long need = a[i] + i;
    g[need].push_back(need + i);
  }

  dfs(n);

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