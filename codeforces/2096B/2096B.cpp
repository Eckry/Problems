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

  vector<ll> l(n);
  vector<ll> r(n);
  for (auto &c : l)
    cin >> c;
  for (auto &c : r)
    cin >> c;

  ll ans = 0;
  vector<ll> left;
  for (int i = 0; i < n; i++)
  {
    left.push_back(min(l[i], r[i]));
    ans += max(l[i], r[i]);
  }

  sort(left.begin(), left.end());
  int idx = n - 1;
  for (int i = n - 1; i >= 0 && k; i--)
  {
    k--;
    idx = i;
    ans += left[i];
  }

  cout << ans - left[idx] + 1 << "\n";
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