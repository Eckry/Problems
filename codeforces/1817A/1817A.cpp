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
  int n, q;
  cin >> n >> q;

  vector<ll> a(n);
  for (auto &c : a)
    cin >> c;

  vector<ll> ans(n - 1);
  for (int i = 1; i < n - 1; i++)
  {
    ans[i] = ans[i - 1] + (a[i - 1] >= a[i] && a[i] >= a[i + 1]);
  }

  while (q--)
  {
    ll l, r;
    cin >> l >> r;
    l--;
    r--;
    if (r == l)
      cout << 1 << "\n";
    else
      cout << r - l + 1 - ans[r - 1] + ans[l] << "\n";
  }
}

int main(void)
{
  optimize();
  int T;
  // cin >> T;
  T = 1;
  while (T--)
    solve();
}