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
  char c;
  cin >> n >> c;
  string s;
  cin >> s;
  vector<int> g;
  vector<int> lc;

  if (c == 'g')
  {
    cout << 0 << "\n";
    return;
  }

  for (int i = 0; i < n; i++)
  {
    if (s[i] == 'g')
      g.push_back(i);
    if (s[i] == c)
      lc.push_back(i);
  }

  sort(g.begin(), g.end());
  sort(lc.begin(), lc.end());

  int i = 0;
  int j = 0;
  int ans = 0;
  bool flg = 1;
  while (j < lc.size())
  {
    if (lc[j] < g[i])
    {
      ans = max(ans, g[i] - lc[j]);
      j++;
    }
    else
    {
      while (lc[j] > g[i] && flg)
      {
        if (i == g.size() - 1)
        {
          flg = 0;
          i = 0;
        }
        else
          i++;
      }
      if (lc[j] < g[i])
        ans = max(ans, g[i] - lc[j]);
      else
        ans = max(ans, n - lc[j] + g[i]);
      j++;
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