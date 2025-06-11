#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

void solve()
{
  int n, x;
  cin >> n >> x;
  vector<int> c(n);
  for (auto &d : c)
    cin >> d;

  vector<int> amount(x + 1, 0);
  amount[0] = 1;
  for (int i = 1; i <= x; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (i - c[j] >= 0)
      {
        amount[i] = (amount[i] + amount[i - c[j]]) % MOD;
      }
    }
  }
  cout << amount[x] << "\n";
}

int main(void)
{
  solve();
}
