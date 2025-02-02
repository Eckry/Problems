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
  ll n, a, b;
  cin >> n >> a >> b;

  vector<ll> c(n);
  for (auto &it : c)
    cin >> it;

  ll gcd = __gcd(a, b);
  sort(c.begin(), c.end());
  ll mx = c[n - 1];
  ll mn = INT_MAX;
  for (int i = 0; i < n; i++)
  {
    ll sm = (mx - c[i]) / gcd;
    c[i] += sm * gcd;
    mx = max(c[i], mx);
    mn = min(c[i], mn);
  }
  sort(c.begin(), c.end());
  ll res = c[n - 1] - c[0];
  for (int i = 1; i < n; i++)
  {
    res = min(res, c[i - 1] + gcd - c[i]);
  }
  cout << res << "\n";
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