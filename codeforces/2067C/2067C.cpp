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

  ll x = n;
  bool ok = 0;
  while (x)
  {
    int last = x % 10;
    if (last == 7)
      ok = 1;
    x /= 10;
  }

  if (ok)
  {
    cout << 0 << "\n";
    return;
  }

  ll now = 9;
  int ans = 9;

  while (now <= 9999999999)
  {

    int cnt = 0;
    for (int i = 0; i < 9; i++)
    {
      ll x = n + now * (i + 1);
      cnt++;
      bool ok = 0;
      while (x)
      {
        int last = x % 10;
        if (last == 7)
        {
          ok = 1;
          break;
        }
        x /= 10;
      }
      if (ok)
        break;
    }

    ans = min(ans, cnt);
    now = now * 10 + 9;
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