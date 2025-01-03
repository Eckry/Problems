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
  long long int row = 0;
  long long int cur = 0;
  long long int ans = 0;
  for (int i = 0; i < n; i++)
  {
    int b;
    cin >> b;
    if (b == 1)
      row++;
    else
    {
      cur += row;
      row = 0;
    }
    ans = max(ans, row + (cur ? cur / 2 + 1 : 0));
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