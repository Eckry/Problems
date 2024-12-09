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

  int p[n];
  for (int i = 0; i < n; i++)
  {
    cin >> p[i];
  }

  int ans = 1;
  int count = 1;

  for (int i = 0; i < n - 1; i++)
  {
    if (p[i] == p[i + 1])
    {
      count++;
    }
    else
    {
      ans = max(ans, count);
      count = 1;
    }
  }
  ans = max(ans, count);
  cout << n - ans << endl;
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