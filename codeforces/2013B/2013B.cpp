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

  if (n == 2)
  {
    cout << a[n - 1] - a[0] << "\n";
    return;
  }

  long long sm = a[n - 2];

  for (int i = n - 3; i >= 0; i--)
  {
    sm -= a[i];
  }

  cout << a[n - 1] - sm << "\n";
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