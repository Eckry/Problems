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
  ll n, m;
  cin >> n >> m;

  ll l = max(n - m, 0LL);
  ll r = n + m;
  ll ans = n;
  for (int i = 31; i >= 0; i--)
  {
    if((l & (1 << i)) || (r & (1 << i)) || (l >> (i + 1)) != (r >> (i + 1))){
      ans |= (1 << i);
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