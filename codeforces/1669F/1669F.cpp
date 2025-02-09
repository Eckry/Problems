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
  vector<int> w(n);
  for (auto &c : w)
    cin >> c;

  vector<ll> alice(n);
  vector<ll> bob(n);

  ll sm = 0;
  map<ll, ll> mp;
  for (int i = n - 1; i >= 0; i--)
  {
    sm += w[i];
    mp[sm] = n - i;
  }
  sm = 0;
  ll ans = 0;
  for (int i = 0; i < n; i++)
  {
    sm += w[i];
    if (mp.count(sm))
    {
      if (mp[sm] < n - i)
        ans = max(ans, i + 1 + mp[sm]);
    }
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