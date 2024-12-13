#include <bits/stdc++.h>

using namespace std;

#define optimize()              \
  cin.tie(0);                   \
  cin.sync_with_stdio(0);       \
  ios_base::sync_with_stdio(0); \
  cout.tie(0);

void solve()
{
  long long int n, k;
  cin >> n >> k;
  vector<long long int> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  vector<long long int> x(n);
  for (int i = 0; i < n; i++)
    cin >> x[i];

  vector<long long int> diff(n + 1);
  for (int i = 0; i < n; i++)
  {
    diff[abs(x[i])] += a[i];
  }

  long long lft = 0;
  bool ok = true;
  for (int i = 1; i <= n; i++)
  {
    lft += k - diff[i];
    if (lft < 0LL)
      ok = false;
  }

  cout << (ok ? "YES" : "NO") << "\n";
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