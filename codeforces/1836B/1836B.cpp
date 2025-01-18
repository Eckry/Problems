#include <bits/stdc++.h>

using namespace std;

#define optimize()              \
  cin.tie(0);                   \
  cin.sync_with_stdio(0);       \
  ios_base::sync_with_stdio(0); \
  cout.tie(0);

void solve()
{
  long long n, k, g;
  cin >> n >> k >> g;

  long long st = min((g - 1) / 2 * n, k * g);

  long long r = (k * g - st) % g;

  if (r > 0)
  {
    st -= (g - 1) / 2;
    long long l = ((g - 1) / 2 + r) % g;

    if (l * 2 < g)
    {
      st += l;
    }
    else
    {
      st -= g - l;
    }
  }
  cout << st << "\n";
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