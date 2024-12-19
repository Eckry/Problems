#include <bits/stdc++.h>

using namespace std;

#define optimize()              \
  cin.tie(0);                   \
  cin.sync_with_stdio(0);       \
  ios_base::sync_with_stdio(0); \
  cout.tie(0);

void solve()
{
  int n, q;
  cin >> n >> q;
  string s;
  cin >> s;

  map<char, int> letters = {
      {'a', 1},
      {'b', 2},
      {'c', 3},
      {'d', 4},
      {'e', 5},
      {'f', 6},
      {'g', 7},
      {'h', 8},
      {'i', 9},
      {'j', 10},
      {'k', 11},
      {'l', 12},
      {'m', 13},
      {'n', 14},
      {'o', 15},
      {'p', 16},
      {'q', 17},
      {'r', 18},
      {'s', 19},
      {'t', 20},
      {'u', 21},
      {'v', 22},
      {'w', 23},
      {'x', 24},
      {'y', 25},
      {'z', 26},
  };

  vector<long long int> dp(n + 1, 0);
  for (int i = 1; i <= n; i++)
  {
    dp[i] = dp[i - 1] + letters[s[i - 1]];
  }

  for (int i = 0; i < q; i++)
  {
    int l, r;
    cin >> l >> r;
    cout << dp[r] - dp[l - 1] << "\n";
  }
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