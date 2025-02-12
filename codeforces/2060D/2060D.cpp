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

  for (int i = 0; i < n - 1; i++)
  {
    if (a[i] > a[i + 1])
    {
      cout << "NO" << "\n";
      return;
    }
    a[i + 1] -= a[i];
    a[i] = 0;
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