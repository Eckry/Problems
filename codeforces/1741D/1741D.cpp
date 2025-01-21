#include <bits/stdc++.h>

using namespace std;

#define optimize()              \
  cin.tie(0);                   \
  cin.sync_with_stdio(0);       \
  ios_base::sync_with_stdio(0); \
  cout.tie(0);

vector<int> p;
int ans;

void dfs(int l, int r)
{
  int mid = (l + r + 1) / 2;
  if (p[mid] < p[mid - 1])
  {
    for (int i = l; i < mid; i++)
    {
      int temp = p[i];
      p[i] = p[i + (r - l + 1) / 2];
      p[i + (r - l + 1) / 2] = temp;
    }
    ans++;
  }

  if (mid == r || mid == l)
    return;
  dfs(l, mid - 1);
  dfs(mid, r);
}

void solve()
{
  int m;
  cin >> m;
  ans = 0;
  p = vector<int>(m);
  for (auto &c : p)
    cin >> c;

  if (m == 1)
  {
    cout << 0 << "\n";
    return;
  }

  dfs(0, m - 1);
  for (int i = 0; i < m - 1; i++)
  {
    if (p[i] > p[i + 1])
    {
      cout << -1 << "\n";
      return;
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