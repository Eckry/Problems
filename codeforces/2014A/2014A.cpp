#include <bits/stdc++.h>

using namespace std;

#define optimize()              \
  cin.tie(0);                   \
  cin.sync_with_stdio(0);       \
  ios_base::sync_with_stdio(0); \
  cout.tie(0);

void solve()
{
  int n, k;
  cin >> n >> k;

  int robin = 0;
  int ans = 0;
  for (int i = 0; i < n; i++)
  {
    int x;
    cin >> x;
    if (x >= k)
      robin += x;
    if (x == 0 && robin)
    {
      robin--;
      ans++;
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