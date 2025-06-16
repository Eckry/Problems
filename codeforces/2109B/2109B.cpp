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
  ll n, m, a, b;
  cin >> n >> m >> a >> b;

  ll ans = 0;

  vector<pair<ll, ll>> pos({make_pair(n, b),
                            make_pair(n, m - b + 1),
                            make_pair(a, m),
                            make_pair(n - a + 1, m)});
  ans = n + m;

  for (auto &[n1, n2] : pos)
  {
    ll res = 0;
    while (n1 != 1)
    {
      res++;
      n1 = (n1 + 1) / 2;
    }
    while (n2 != 1)
    {
      res++;
      n2 = (n2 + 1) / 2;
    }
    ans = min(ans, res);
  }

  cout << ans + 1 << "\n";
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