#include <bits/stdc++.h>

using namespace std;

#define optimize()              \
  cin.tie(0);                   \
  cin.sync_with_stdio(0);       \
  ios_base::sync_with_stdio(0); \
  cout.tie(0);

vector<vector<long long int>> tree;
vector<long long int> ans;

void dfs(long long int u, long long int parent)
{
  if (tree[u].size() == 1 && tree[u][0] == parent)
  {
    ans[u] = 1;
  }
  else
  {
    for (auto v : tree[u])
    {
      if (v != parent)
      {
        dfs(v, u);
        ans[u] += ans[v];
      }
    }
  }
}

void solve()
{
  long long int n;
  cin >> n;

  tree.assign(n + 1, vector<long long int>());
  ans.assign(n + 1, 0);
  for (int i = 0; i < n - 1; i++)
  {
    int u, v;
    cin >> u >> v;
    tree[u].push_back(v);
    tree[v].push_back(u);
  }

  dfs(1, -1);

  long long int q;
  cin >> q;
  for (long long int i = 0; i < q; i++)
  {
    long long int x, y;
    cin >> x >> y;

    cout << ans[x] * ans[y] << "\n";
  }
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