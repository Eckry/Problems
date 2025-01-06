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
  for (int i = 1; i <= n; i++)
  {
    for (int j = n; j > i; j--)
      cout << j << " ";
    cout << 1 << " ";
    for (int j = i; j > 1; j--)
      cout << j << " ";
    cout << "\n";
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