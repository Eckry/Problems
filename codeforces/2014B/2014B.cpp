#include <bits/stdc++.h>

using namespace std;

#define optimize()              \
  cin.tie(0);                   \
  cin.sync_with_stdio(0);       \
  ios_base::sync_with_stdio(0); \
  cout.tie(0);

void solve()
{
  long long int n, k;
  cin >> n >> k;

  if (n % 2 == 0)
  {
    if ((k / 2) % 2 == 0)
    {
      cout << "YES" << "\n";
      return;
    }
    else
    {
      cout << "NO" << "\n";
      return;
    }
  }
  else
  {
    if (((k + 1) / 2) % 2 == 0)
    {
      cout << "YES" << "\n";
      return;
    }
    else
    {
      cout << "NO" << "\n";
      return;
    }
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