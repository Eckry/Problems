#include <bits/stdc++.h>

using namespace std;

#define optimize()              \
  cin.tie(0);                   \
  cin.sync_with_stdio(0);       \
  ios_base::sync_with_stdio(0); \
  cout.tie(0);

void solve()
{
  int n, a, b;
  cin >> n >> a >> b;
  int d = max(b, a) - min(a, b) + 1;

  if (d & 1)
  {
    cout << "YES" << "\n";
  }
  else
    cout << "NO" << "\n";
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