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
  vector<ll> b(n - 1);
  for (auto &c : b)
    cin >> c;

  vector<ll> a(n);
  for (int i = 0; i < n; i++)
  {
    if (i == 0)
    {
      a[i] = b[i];
      continue;
    }
    if (i == n - 1)
    {
      a[i] = b[i - 1];
      continue;
    }
    a[i] = b[i] | b[i - 1];
  }

  for (int i = 0; i < n - 1; i++)
  {
    if ((a[i] & a[i + 1]) != b[i])
    {
      cout << -1 << "\n";
      return;
    }
  }
  for (auto c : a)
    cout << c << " ";
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