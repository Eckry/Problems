#include <bits/stdc++.h>

using namespace std;

#define optimize()              \
  cin.tie(0);                   \
  cin.sync_with_stdio(0);       \
  ios_base::sync_with_stdio(0); \
  cout.tie(0);

void solve()
{
  vector<long long> a(3);
  cin >> a[0] >> a[1] >> a[2];

  sort(a.begin(), a.end());

  if (a[2] % a[0] != 0)
  {
    cout << "NO" << "\n";
    return;
  }

  if (a[1] % a[0] != 0)
  {
    cout << "NO" << "\n";
    return;
  }

  if (a[2] / a[0] + a[1] / a[0] - 2 > 3)
    cout << "NO" << "\n";
  else
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