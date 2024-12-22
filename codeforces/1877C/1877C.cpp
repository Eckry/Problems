#include <bits/stdc++.h>

using namespace std;

#define optimize()              \
  cin.tie(0);                   \
  cin.sync_with_stdio(0);       \
  ios_base::sync_with_stdio(0); \
  cout.tie(0);

void solve()
{

  long long int n, m, k;
  cin >> n >> m >> k;

  if (k == 1)
  {
    cout << 1 << "\n";
  }
  else if (k == 2 && m <= n)
  {
    cout << m << "\n";
  }
  else if (k == 2)
  {
    cout << n + m / n - 1 << "\n";
  }
  else if (k == 3 && m <= n)
  {
    cout << 0 << "\n";
  }
  else if (k == 3)
  {
    cout << m - n - m / n + 1 << "\n";
  }
  else
  {
    cout << 0 << "\n";
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