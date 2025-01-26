#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define optimize()              \
  cin.tie(0);                   \
  cin.sync_with_stdio(0);       \
  ios_base::sync_with_stdio(0); \
  cout.tie(0);

vector<ll> c;
vector<vector<ll>> edg;
vector<ll> vis;

ll dfs(ll n)
{
  if (vis[n])
    return c[n];
  vis[n] = 1;
  if (edg[n].size() == 0)
    return c[n];
  else
  {
    ll sm = 0;
    for (auto v : edg[n])
    {
      sm += dfs(v);
    }
    c[n] = min(sm, c[n]);
    return c[n];
  }
}

void solve()
{
  ll n, k;
  cin >> n >> k;
  c = vector<ll>(n + 1, 0);
  vis = vector<ll>(n + 1, 0);
  for (int i = 1; i <= n; i++)
    cin >> c[i];
  for (int i = 0; i < k; i++)
  {
    ll v;
    cin >> v;
    c[v] = 0;
  }

  vector<ll> reach;
  edg = vector<vector<ll>>(n + 1, vector<ll>());

  for (int i = 1; i <= n; i++)
  {
    ll m;
    cin >> m;
    if (m != 0)
      reach.push_back(i);
    for (int j = 1; j <= m; j++)
    {
      ll u;
      cin >> u;
      edg[i].push_back(u);
    }
  }

  for (int i = 0; i < reach.size(); i++)
  {
    if (!vis[reach[i]])
      dfs(reach[i]);
  }

  for (int i = 1; i <= n; i++)
  {
    cout << c[i] << " ";
  }
  cout << "\n";
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