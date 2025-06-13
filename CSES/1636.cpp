#include <bits/stdc++.h>

using namespace std;

void solve()
{
  int MOD = 1e9 + 7;
  int n, x;
  cin >> n >> x;
  vector<int> c(n);
  for (auto &d : c)
    cin >> d;

  vector<vector<int>> amount(n + 1, vector<int>(x + 1, 0));
  amount[0][0] = 1;
  for (int i = 1; i <= n; i++)
  {
    for (int j = 0; j <= x; j++)
    {
      amount[i][j] = amount[i - 1][j];
      if (j - c[i - 1] >= 0)
      {
        amount[i][j] = (amount[i][j] + amount[i][j - c[i - 1]]) % MOD;
      }
    }
  }
  // for(auto c : amount) {
  //   for(auto d : c) cout <<d << " ";
  //   cout << "\n";
  // }
  cout << amount[n][x];
}

int main(void)
{
  solve();
}
