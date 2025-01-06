#include <bits/stdc++.h>

using namespace std;

#define optimize()              \
  cin.tie(0);                   \
  cin.sync_with_stdio(0);       \
  ios_base::sync_with_stdio(0); \
  cout.tie(0);

void solve()
{
  int n, r, b;
  cin >> n >> r >> b;

  string ans = "";

  while (r > 0)
  {
    int s = (r + b) / (b + 1);
    if (s == 0)
      break;
    int j = s;
    while (j--)
    {
      ans += "R";
    }
    r -= s;
    if (b != 0)
    {
      ans += "B";
      b--;
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