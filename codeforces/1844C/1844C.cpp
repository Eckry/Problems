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
  vector<ll> c(n);
  for (auto &it : c)
    cin >> it;

  bool flg = 1;
  ll mx = -INT_MAX;
  for (int i = 0; i < n; i++)
  {
    if (c[i] >= 0)
      flg = 0;
    mx = max(c[i], mx);
  }

  if (flg)
  {
    cout << mx << "\n";
    return;
  }

  ll sm1 = 0;
  ll sm2 = 0;
  for (int i = 0; i < n; i++)
  {
    if (i & 1)
    {
      sm1 += max(0LL, c[i]);
    }
    else
    {
      sm2 += max(0LL, c[i]);
    }
  }
  cout << max(sm1, sm2) << "\n";
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