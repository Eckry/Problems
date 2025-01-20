#include <bits/stdc++.h>

using namespace std;

#define optimize()              \
  cin.tie(0);                   \
  cin.sync_with_stdio(0);       \
  ios_base::sync_with_stdio(0); \
  cout.tie(0);

void solve()
{
  int n;
  cin >> n;
  vector<long long> a(n);
  for (auto &c : a)
    cin >> c;

  long long mn = 0;
  for (int i = 0; i < n; i++)
  {
    if (a[mn] > a[i])
      mn = i;
  }
  if (mn == n - 1)
  {
    cout << n - 1 << "\n";
    return;
  }

  for (int i = mn; i < n - 1; i++)
  {
    if (a[i] > a[i + 1])
    {
      cout << -1 << "\n";
      return;
    }
  }
  cout << mn << "\n";
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