#include <bits/stdc++.h>

using namespace std;

#define optimize()              \
  cin.tie(0);                   \
  cin.sync_with_stdio(0);       \
  ios_base::sync_with_stdio(0); \
  cout.tie(0);

void solve()
{
  int n;
  cin >> n;
  vector<long long> a(n);
  for (auto &c : a)
    cin >> c;

  long long odd = 0;
  long long even = 0;
  for (int i = 0; i < n; i++)
  {
    if (a[i] & 1)
    {
      odd++;
    }
    else
    {
      even++;
    }
  }

  long long ans = 0;
  if (odd == 0 && even)
    ans = 1;
  else if (odd == 1 && even)
    ans = 2;
  else if (odd > 1 && even == 0)
    ans += odd - 1;
  else if (odd && even)
  {
    ans += odd + 1;
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