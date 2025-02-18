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
  vector<ll> a(n);
  for (auto &c : a)
    cin >> c;
  vector<ll> preff(n + 1, 0);
  vector<ll> suff(n + 1, 0);
  preff[0] = 0;
  suff[n] = 0;
  for (int i = 1; i <= n; i++)
  {
    preff[i] = preff[i - 1] + max(0LL, a[i - 1]);
  }

  for (int i = n - 1; i >= 0; i--)
  {
    suff[i] = suff[i + 1] + abs(min(0LL, a[i]));
  }

  ll ans = 0;
  // for (auto c : preff)
  //   cout << c << " ";
  // cout << "\n";
  // for (auto c : suff)
  //   cout << c << " ";
  // cout << "\n";
  for (int i = 0; i <= n; i++)
  {
    //cout << preff[i] << " " << suff[i] << "\n";
    ans = max(preff[i] + suff[i], ans);
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