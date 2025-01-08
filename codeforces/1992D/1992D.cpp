#include <bits/stdc++.h>

using namespace std;

#define optimize()              \
  cin.tie(0);                   \
  cin.sync_with_stdio(0);       \
  ios_base::sync_with_stdio(0); \
  cout.tie(0);

void solve()
{
  string s;
  int n;
  int m;
  int k;
  cin >> n >> m >> k;
  cin >> s;

  int idx = 0;

  while (idx < n)
  {
    if (idx < n)
      while (s[idx] == 'L')
        idx++;

    int nl = -1;
    int lc = -1;
    int water = 0;
    int start = idx;

    while (idx < n && s[idx] != 'L')
    {
      if (s[idx] == 'C')
        lc = idx;
      if (s[idx] == 'W')
        water++;
      idx++;
    }
    int distance = idx - start + 1;
    if (idx >= n)
    {
      distance = n - start + 1;
      if (lc - start + 1 >= m)
      {
        cout << "NO" << "\n";
        return;
      }
      else if (m + k >= distance)
      {
        cout << "YES" << "\n";
        return;
      }
      else
      {
        cout << "NO" << "\n";
        return;
      }
    }

    if (lc - start + 1 >= m)
    {
      cout << "NO" << "\n";
      return;
    }
    else if (m + k >= distance && m < distance)
    {
      k -= distance - m;
      if (k < 0)
        k = 0;
    }
    else if(m + k < distance)
    {
      cout << "NO" << "\n";
      return;
    }
  }
  cout << "YES" << "\n";
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