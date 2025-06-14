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
  int n, k;
  cin >> n >> k;

  vector<ll> a(n);
  for (auto &c : a)
    cin >> c;

  if (k != 1)
  {
    sort(a.begin(), a.end());
    ll ans = 0;
    for (int i = n - 1; i >= n - k - 1; i--)
    {
      ans += a[i];
    }
    cout << ans << "\n";
    return;
  }

  ll mx = a[0] + a[n - 1];
  ll ans = a[0] + a[n - 1];
  for (int i = 1; i < n - 1; i++)
  {
    mx = max(a[0] + a[i], a[n - 1] + a[i]);
    ans = max(mx, ans);
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