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
  int n, m, k;
  cin >> n >> m >> k;
  if (abs(n - m) > k)
  {
    cout << -1 << "\n";
    return;
  }
  if (k > n && k > m)
  {
    cout << -1 << "\n";
    return;
  }
  string ans = "";
  if (n >= m)
  {
    while (k--)
    {
      n--;
      ans += '0';
    }
    while (n > 0 && m > 0)
    {
      n--;
      ans += '1';
      m--;
      ans += '0';
    }

    while (n > 0)
    {
      n--;
      ans += '0';
    }

    while (m > 0)
    {
      m--;
      ans += '1';
    }
  }
  else
  {
    while (k--)
    {
      m--;
      ans += '1';
    }
    while (n > 0 && m > 0)
    {
      n--;
      ans += '0';
      m--;
      ans += '1';
    }

    while (n > 0)
    {
      n--;
      ans += '0';
    }

    while (m > 0)
    {
      m--;
      ans += '1';
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