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
  string ans = string(n, '0');

  if (s[0] == '9')
  {
    int carry = 0;
    for (int i = n - 1; i >= 0; i--)
    {
      int x = s[i] - '0';
      x += carry;
      int sm = 11 - x;
      if (x == 0)
      {
        sm = 1;
        carry = 0;
      }
      if (x == 1)
      {
        sm = 0;
        carry = 0;
      }
      if (x >= 2)
        carry = 1;
      ans[i] += sm;
    }
  }
  else
  {
    for (int i = 0; i < n; i++)
    {
      int x = s[i] - '0';
      ans[i] += (9 - x);
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