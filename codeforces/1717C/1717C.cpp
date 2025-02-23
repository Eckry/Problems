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
  vector<ll> b(n);
  for (auto &c : a)
    cin >> c;
  for (auto &c : b)
    cin >> c;

  for (int i = 0; i < n; i++)
  {
    if (a[i] > b[i])
    {
      cout << "NO" << "\n";
      return;
    }
  }

  for (int i = 0; i < n - 1; i++)
  {
    if (a[i] != b[i] && b[i] - 1 > b[i + 1])
    {
      cout << "NO" << "\n";
      return;
    }
  }
  if (a[n - 1] != b[n - 1] && b[n - 1] - 1 > b[0])
  {
    cout << "NO" << "\n";
    return;
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