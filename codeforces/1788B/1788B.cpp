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
  if ((n / 2) % 10 == 9)
  {
    ll x = n;
    bool flg = 0;
    ll i = 0;
    ll a = 0, b = 0;
    while (x)
    {
      ll l = x % 10;
      if (l & 1)
      {
        if (flg)
        {
          flg = 0;
          a += ((l + 1) / 2) * pow(10, i);
          b += (l / 2) * pow(10, i);
        }
        else
        {
          a += (l / 2) * pow(10, i);
          b += ((l + 1) / 2) * pow(10, i);
          flg = 1;
        }
      }
      else
      {
        a += (l / 2) * pow(10, i);
        b += (l / 2) * pow(10, i);
      }
      x /= 10;
      i++;
    }
    cout << a << " " << b << "\n";
  }
  else
    cout << n / 2 << " " << (n + 1) / 2 << "\n";
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