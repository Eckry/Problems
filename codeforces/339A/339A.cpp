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
  cin >> s;
  map<char, int> count = {
      {'1', 0},
      {'2', 0},
      {'3', 0},
  };

  for (auto it : s)
  {
    if (it == '+')
      continue;
    count[it]++;
  }

  string ans = "";

  for (auto const &[key, val] : count)
  {
    while (count[key])
    {
      count[key]--;
      ans += string(1, key) + "+";
    }
  }

  ans.pop_back();
  cout << ans;
}

int main(void)
{
  optimize();
  int T;
  // cin >> T;
  T = 1;
  while (T--)
    solve();
}