#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define optimize()              \
  cin.tie(0);                   \
  cin.sync_with_stdio(0);       \
  ios_base::sync_with_stdio(0); \
  cout.tie(0);

vector<vector<ll>> adj;
vector<ll> dp;
vector<ll> a;

void dfs(ll n, ll p, ll par, ll mx, ll mn, vector<ll> &sm)
{
  if (par & 1)
  {
    sm.push_back(sm[sm.size() - 1] - a[n]);
    mn = min(sm[(ll)sm.size() - 1], mn);
    mx = max(sm[(ll)sm.size() - 1], mx);
  }
  else
  {
    sm.push_back(sm[(ll)sm.size() - 1] + a[n]);
    mx = max(sm[(ll)sm.size() - 1], mx);
    mn = min(sm[(ll)sm.size() - 1], mn);
  }
  for (auto v : adj[n])
  {
    if (v == p)
      continue;
    dfs(v, n, par + 1, mx, mn, sm);
  }
  if (par & 1)
  {
    dp[n] = max(-sm[(ll)sm.size() - 1] + mx, -sm[(ll)sm.size() - 1]);
  }
  else
  {
    dp[n] = max(sm[(ll)sm.size() - 1] - mn, sm[(ll)sm.size() - 1]);
  }
  // for (auto c : sm)
  //   cout << c << " ";
  // cout << "   " << n << " " << par << " " << mn << " " << mx;
  // cout << "\n";
  sm.pop_back();
}
void solve()
{
  ll n;
  cin >> n;
  a = vector<ll>(n + 1);
  adj = vector<vector<ll>>(n + 1, vector<ll>());
  dp = vector<ll>(n + 1, -1);
  for (ll i = 1; i <= n; i++)
  {
    cin >> a[i];
  }
  dp[1] = a[1];

  for (ll i = 0; i < n - 1; i++)
  {
    ll u, v;
    cin >> u >> v;

    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  vector<ll> temp = {};
  temp.push_back(0);
  dfs(1, -1, 1, -a[1], -a[1], temp);
  for (ll i = 1; i <= n; i++)
    cout << dp[i] << " ";
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