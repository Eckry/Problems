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
  ll target = 1;

  if (k == n)
  {
    for (int i = 1; i < n; i += 2)
    {
      if (a[i] != target)
      {
        cout << target << "\n";
        return;
      }
      target++;
    }
    cout << target << "\n";
    return;
  }
  for (int i = 1; i < n; i++)
  {
    if (a[i] != 1)
    {
      cout << 1 << "\n";
      return;
    }
    if (k - 1 >= n - i)
    {
      break;
    }
  }
  cout << 2 << "\n";
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