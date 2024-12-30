#include <bits/stdc++.h>

using namespace std;

#define optimize()              \
  cin.tie(0);                   \
  cin.sync_with_stdio(0);       \
  ios_base::sync_with_stdio(0); \
  cout.tie(0);

void solve()
{
  long long int n;
  int m;
  int q;
  cin >> n >> m >> q;

  long long int x1, x2;
  cin >> x1;
  cin >> x2;

  long long int d;
  cin >> d;

  long long int l = min(x1, x2);
  long long int r = max(x1, x2);
  if (d < l)
  {
    cout << l - 1 << "\n";
    return;
  }
  if (d > r)
  {
    cout << n - r << "\n";
    return;
  }

  long long int mid = (x1 + x2) / 2;
  long long int ans = mid - l;
  cout << ans << "\n";
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