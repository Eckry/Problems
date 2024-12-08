#include <bits/stdc++.h>

using namespace std;

#define optimize()              \
  cin.tie(0);                   \
  cin.sync_with_stdio(0);       \
  ios_base::sync_with_stdio(0); \
  cout.tie(0);

void solve()
{
  int n, k;
  cin >> n >> k;
  int numbers[n];
  for (int i = 0; i < n; i++)
  {
    cin >> numbers[i];
  }

  for (int i = 0; i < n; i++)
  {
    bool flg = 1;
    for (int j = 0; j < n; j++)
    {
      if (j == i)
        continue;
      if (abs(numbers[i] - numbers[j]) % k == 0)
      {
        flg = 0;
        break;
      }
    }
    if (flg)
    {
      cout << "YES\n"
           << i + 1 << endl;
      return;
    };
  }
  cout << "NO" << endl;
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