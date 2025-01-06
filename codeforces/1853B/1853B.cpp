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
  long long int k;
  cin >> n >> k;

  long long int ans = 0;

  for (int i = (n + 1) / 2; i <= n; i++)
  {
    long long int a = i;
    long long int b = n;
    bool flg = 1;
    for (int j = 0; j < k - 2; j++)
    {
      long long int temp = a;
      a = b - a;
      b = temp;
      if (a < 0 || b < 0 || b < a)
      {
        flg = 0;
        break;
      }
    }

    if (flg)
      ans++;
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