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
  int n, m, p, q;
  cin >> n >> m >> p >> q;

  if (n % p == 0 && (n / p) * q != m)
  {
    cout << "NO" << "\n";
  }
  else
  {
    cout << "YES" << "\n";
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