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
  vector<int> ids;
  // 2 3 4 8
  for (int i = 1; i <= n; i++)
  {
    if (a[i - 1] < i)
      ids.push_back(i);
  }
  ll ans = 0;
  int m = ids.size();
  for (int i = 0; i < m; i++)
  {
    ll temp = a[ids[i] - 1];
    int lower = lower_bound(ids.begin(), ids.end(), temp) - ids.begin();
    
    ans += lower;
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