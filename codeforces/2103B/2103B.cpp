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
  int n;
  cin >> n;
  string s;
  cin >> s;

  s = "0" + s;
  int ans = 0;
  int cur = s[0];
  for (int i = 1; i <= n; i++)
  {
    int dig = s[i];
    if (cur != dig)
      ans++;
    cur = dig;
  }

  if (ans >= 3)
  {
    cout << ans - 2 + n << "\n";
  }
  else if (ans == 2)
  {
    cout << ans - 1 + n << "\n";
  }
  else
  {
    cout << n + ans << "\n";
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