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
  ll n, k;
  cin >> n >> k;
  vector<ll> a(n);
  for (auto &c : a)
    cin >> c;

  sort(a.begin(), a.end(), greater<>());

  ll alice = 0;
  ll bob = 0;

  for (int i = 0; i < n; i++)
  {
    if (i & 1)
      bob += a[i];
    else
      alice += a[i];
  }

  ll res = alice - bob;
  if (res == 0)
  {
    cout << 0 << "\n";
    return;
  }

  if (res < 0)
  {
    cout << max(0LL, abs(res) - k) << "\n";
    return;
  }

  for (int i = 1; i < n; i += 2)
  {
    ll diff = a[i - 1] - a[i];
    if (diff >= k)
    {
      a[i] += k;
      k = 0;
    }
    else
    {
      a[i] += diff;
      k -= diff;
    }
    if (k == 0)
      break;
  }

  alice = 0;
  bob = 0;
  for (int i = 0; i < n; i++)
  {
    if (i & 1)
      bob += a[i];
    else
      alice += a[i];
  }
  cout << max(alice - bob, 0LL) << "\n";
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