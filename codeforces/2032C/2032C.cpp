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

  sort(a.begin(), a.end());

  int ans = n;
  int l = 0;
  for (int r = 2; r < n; r++)
  {
    while (l + 1 < r && a[l] + a[l + 1] <= a[r])
      l++;
    ans = min(ans, n - (r - l + 1));
  }
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