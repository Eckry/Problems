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
  int n, m;
  cin >> n >> m;
  vector<string> s(n);
  for (auto &c : s)
    cin >> c;

  int mx = -1;
  int start = 0;
  int end = n - 1;
  for (int i = 0; i < m; i++)
  {
    int st = 0;
    for (int j = 0; j < n; j++)
    {
      st = j;
      if (s[j][i] == '#')
        break;
    }
    int cnt = 0;
    int ed = 0;
    for (int j = st; j < n; j++)
    {
      if (s[j][i] == '.')
        break;
      ed = j;
      cnt++;
    }
    if (mx < cnt)
    {
      mx = cnt;
      start = st;
      end = ed;
    }
  }

  cout << (start + end) / 2 + 1 << " ";

  mx = -1;
  start = 0;
  end = m - 1;
  for (int i = 0; i < n; i++)
  {
    int st = 0;
    for (int j = 0; j < m; j++)
    {
      st = j;
      if (s[i][j] == '#')
        break;
    }
    int cnt = 0;
    int ed = 0;
    for (int j = st; j < m; j++)
    {
      if (s[i][j] == '.')
        break;
      ed = j;
      cnt++;
    }
    if (mx < cnt)
    {
      mx = cnt;
      start = st;
      end = ed;
    }
  }

  cout << (start + end) / 2 + 1 << "\n";
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