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

  map<char, int> map = {
      {'A', 0},
      {'B', 0},
      {'C', 0},
      {'D', 0},
      {'E', 0},
      {'F', 0},
      {'G', 0},
  };

  for (int i = 0; i < n; i++)
  {
    map[s[i]]++;
  }

  int count = 0;
  for (auto i : map)
  {
    if (m > i.second)
    {
      count += m - i.second;
    }
  }

  cout << count << "\n";
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