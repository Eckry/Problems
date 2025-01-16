#include <bits/stdc++.h>

using namespace std;

#define optimize()              \
  cin.tie(0);                   \
  cin.sync_with_stdio(0);       \
  ios_base::sync_with_stdio(0); \
  cout.tie(0);

void solve()
{
  int n, m;
  cin >> n >> m;

  string s;
  cin >> s;

  vector<int> ind(m);
  for (auto &c : ind)
    cin >> c;

  string c;
  cin >> c;

  sort(c.begin(), c.end());
  sort(ind.begin(), ind.end());
  map<int, int> mp;
  int cnt = 0;

  vector<int> newA;
  for (int i = 0; i < m; i++)
  {
    if (!mp[ind[i]])
    {
      newA.push_back(ind[i]);
      cnt++;
    }
    mp[ind[i]]++;
  }

  for (int i = cnt - 1; i >= 0; i--)
  {
    s[newA[i] - 1] = c[i];
  }

  cout << s << "\n";
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