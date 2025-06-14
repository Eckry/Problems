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
  vector<ll> a(n);
  for (auto &c : a)
    cin >> c;

  vector<ll> b(m);
  for (auto &c : b)
    cin >> c;

  ll j = 0;
  for (ll i = 0; i < n && j < m; i++)
  {
    if (a[i] >= b[j])
    {
      j++;
    }
  }
  if (j == m)
  {
    cout << 0 << "\n";
    return;
  }

  vector<ll> prefix;
  vector<ll> suffix;

  j = 0;
  for (ll i = 0; i < n && j < m; i++)
  {
    if (a[i] >= b[j])
    {
      prefix.push_back(i);
      j++;
    }
  }
  while (prefix.size() != m)
    prefix.push_back(n);
  j = m - 1;
  for (ll i = n - 1; i >= 0 && j >= 0; i--)
  {
    if (a[i] >= b[j])
    {
      suffix.push_back(i);
      j--;
    }
  }
  while (suffix.size() != m)
    suffix.push_back(-1);

  reverse(suffix.begin(), suffix.end());
  ll ans = LONG_LONG_MAX;
  for (ll i = 0; i < m; i++)
  {
    if (i == 0)
    {
      ans = min(ans, suffix[i + 1] != -1 ? b[i] : LONG_LONG_MAX);
      continue;
    }
    if (i == m - 1)
    {
      ans = min(ans, prefix[i - 1] != n ? b[i] : LONG_LONG_MAX);
      continue;
    }
    if (suffix[i + 1] > prefix[i - 1])
    {
      ans = min(ans, b[i]);
    }
  }
  if (ans == LONG_LONG_MAX)
  {
    cout << -1 << "\n";
    return;
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