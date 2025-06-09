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
  ll n;
  cin >> n;
  vector<ll> a(n);
  for (auto &c : a)
    cin >> c;

  ll k = 0;
  ll diff = a[1] - a[0];
  for (int i = 1; i < n; i++)
  {
    if (a[i] - a[i - 1] != diff)
    {
      cout << "NO" << "\n";
      return;
    }
  }

  if (diff >= 0)
  {
    for (int i = 0; i < n; i++)
    {
      a[i] -= diff * (i + 1);
    }
  }
  else
  {
    for (int i = 0; i < n; i++)
    {
      a[i] += diff * (n - i);
    }
  }

  for (int i = 0; i < n; i++)
  {
    if (a[i] < 0 || a[i] % (n + 1) != 0)
    {
      cout << "NO" << "\n";
      return;
    }
  }
  cout << "YES" << "\n";
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