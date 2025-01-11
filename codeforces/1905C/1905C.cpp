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
  cin >> n;
  string s;
  cin >> s;

  map<char, vector<int>> m;

  string mx = "";

  for (int i = 0; i < n; i++)
  {
    m[s[i]].push_back(i);
  }

  vector<char> p;

  int i = 0;
  for (auto c : m)
    p.push_back(c.first);

  vector<int> indexes;

  int idx = -1;
  for (int i = p.size() - 1; i >= 0; i--)
  {
    for (int j = 0; j < m[p[i]].size(); j++)
    {
      if (m[p[i]][j] < idx)
        continue;
      mx += p[i];
      idx = m[p[i]][j];
      indexes.push_back(m[p[i]][j]);
    }
  }
  bool flg = 0;
  for (int i = 0; i < n - 1; i++)
  {
    if (s[i] > s[i + 1])
    {
      flg = 1;
    }
  }

  if (!flg)
  {
    cout << 0 << "\n";
    return;
  }

  int j = 0;
  int k = mx.size() - 1;

  flg = 0;
  for (int i = 0; i < n; i++)
  {
    if (i == indexes[j])
    {
      s[i] = mx[k];
      k--;
      j++;
    }
  }
  flg = 0;
  for (int i = 0; i < n - 1; i++)
  {
    if (s[i] > s[i + 1])
    {
      flg = 1;
      break;
    }
  }

  int ans = mx.size() - m[mx[0]].size();

  if (!flg)
  {
    cout << ans << "\n";
  }
  else
    cout << -1 << "\n";
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