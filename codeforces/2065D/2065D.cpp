#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define optimize()              \
  cin.tie(0);                   \
  cin.sync_with_stdio(0);       \
  ios_base::sync_with_stdio(0); \
  cout.tie(0);

void solve()
{
  ll n, m;
  cin >> n >> m;

  vector<vector<ll>> a(n, vector<ll>(m));
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      cin >> a[i][j];

  vector<ll> score(n, 0);
  for (int i = 0; i < n; i++)
  {
    ll sm = 0;
    for (int j = 0; j < m; j++)
    {
      sm += a[i][j];
    }
    score[i] = sm;
  }
  vector<ll> idx(n);
  iota(idx.begin(), idx.end(), 0);
  sort(idx.begin(), idx.end(), [&](ll a, ll b)
       { return score[a] > score[b]; });

  ll ans = 0;
  ll sm = 0;
  for (int i = 0; i < n; i++)
  {
    int k = idx[i];
    for (int j = 0; j < m; j++)
    {
      sm += a[k][j];
      ans += sm;
    }
  }
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