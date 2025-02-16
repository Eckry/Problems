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
  ll n;
  cin >> n;
  ll k;
  cin >> k;
  vector<ll> a(n);
  for (auto &c : a)
    cin >> c;
  vector<ll> b(n);
  for (auto &c : b)
    cin >> c;

  vector<int> ids(n);
  iota(ids.begin(), ids.end(), 0);

  sort(ids.begin(), ids.end(), [&](int x, int y)
       { return a[x] < a[y]; });

  sort(b.begin(), b.end());
  vector<ll> ans(n);
  for (int i = 0; i < n; i++)
  {
    ans[ids[i]] = b[i];
  }

  for(auto c : ans) cout << c << " ";
  cout << "\n";
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