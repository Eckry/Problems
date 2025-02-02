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
  int n;
  cin >> n;
  vector<ll> a(n);
  for (auto &c : a)
    cin >> c;

  vector<ll> sm(n, 0);
  sm[0] = a[0];
  for (int i = 1; i < n; i++)
  {
    sm[i] = sm[i - 1] + a[i];
  }
  if (sm[n - 1] != 0)
  {
    cout << "NO" << "\n";
    return;
  }

  for (int i = 0; i < n; i++)
  {
    if (sm[i] < 0)
    {
      cout << "NO" << "\n";
      return;
    }
  }

  bool flg = 0;

  for (int i = 0; i < n; i++)
  {
    if (sm[i] != 0 && flg)
    {
      cout << "NO" << "\n";
      return;
    }
    if (sm[i] == 0)
    {
      flg = 1;
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