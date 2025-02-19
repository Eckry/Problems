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
  if (n == 1 || n == 3)
  {
    cout << -1 << "\n";
    return;
  }

  string ans = "";
  if (n & 1)
  {
    for (int i = 0; i < n - 5; i++)
    {
      ans += '3';
    }
    ans += "36366";
  }
  else
  {
    for (int i = 0; i < n - 2; i++)
    {
      ans += '3';
    }
    ans += "66";
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