#include <bits/stdc++.h>

using namespace std;

#define optimize()              \
  cin.tie(0);                   \
  cin.sync_with_stdio(0);       \
  ios_base::sync_with_stdio(0); \
  cout.tie(0);

void solve()
{
  long long n, x, y;
  cin >> n >> x >> y;

  string a;
  string b;
  cin >> a >> b;
  int cnta = 0;
  int cntb = 0;
  for (int i = 0; i < n; i++)
  {
    if (a[i] == '1')
      cnta++;
    if (b[i] == '1')
      cntb++;
  }
  if (abs(cnta - cntb) & 1)
  {
    cout << -1 << "\n";
    return;
  }
  long long ans = 0;
  vector<int> ids;
  for (int i = 0; i < n; i++)
  {
    if (a[i] == '1' && b[i] == '0')
    {
      ids.push_back(i);
    }
    if (a[i] == '0' && b[i] == '1')
      ids.push_back(i);
  }

  int m = ids.size();

  for (int i = 0; i < m / 2; i++)
  {
    if (ids[i + m / 2] - ids[i] != 1)
    {
      ans += y;
    }
    else
    {
      if (2 * y > x)
      {
        ans += x;
      }
      else if (2 * y < x)
      {
        ans += 2 * y;
      }
      else
      {
        ans += x;
      }
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