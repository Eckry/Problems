#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define optimize()              \
  cin.tie(0);                   \
  cin.sync_with_stdio(0);       \
  ios_base::sync_with_stdio(0); \
  cout.tie(0);

vector<vector<int>> edg;
vector<int> cats;
vector<int> visited;
int ans = 0;
int m;
void dfs(int p, int n, int k)
{
  if (k > m)
    return;
  if (edg[n].size() == 1 && n != 1)
    ans++;
  else
    for (auto v : edg[n])
      if (p != v)
        dfs(n, v, k * cats[v] + cats[v]);
}

void solve()
{
  int n;
  cin >> n >> m;
  cats = vector<int>(n + 1);
  visited = vector<int>(n + 1, 0);
  ans = 0;
  for (int i = 1; i <= n; i++)
    cin >> cats[i];

  edg = vector<vector<int>>(n + 1, vector<int>());
  for (int i = 0; i < n - 1; i++)
  {
    int u, v;
    cin >> u >> v;
    edg[u].push_back(v);
    edg[v].push_back(u);
  }
  dfs(-1, 1, cats[1]);
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