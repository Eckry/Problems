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
  ll q;
  cin >> q;
  bool aT = 1;
  bool aS = 1;
  ll cntT = 0;
  ll cntS = 0;
  for (ll p = 1; p <= q; p++)
  {
    ll d;
    ll k;
    string s;
    cin >> d >> k >> s;

    if (d == 1)
    {
      for (auto c : s)
      {
        if (c != 'a')
          aS = 0;
        else
          cntS += k;
      }
    }
    else
    {
      for (auto c : s)
      {
        if (c != 'a')
          aT = 0;
        else
          cntT += k;
      }
    }
    if (!aT)
    {
      cout << "YES" << "\n";
    }
    else if (aS && cntS < cntT)
    {
      cout << "YES" << "\n";
    }
    else
      cout << "NO" << "\n";
  }
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