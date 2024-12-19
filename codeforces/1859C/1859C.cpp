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

  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++)
  {
    a[i] = i;
  }

  int ans INT_MIN;
  for (int i = 1; i <= n; i++)
  {
    int sum = 0;
    int mx = INT_MIN;
    for (int k = 1; k <= n; k++)
    {
      sum += a[k] * k;
      mx = max(mx, a[k] * k);
    }
    ans = max(sum - mx, ans);

    int j = n - i;
    while (j < n)
    {
      int temp = a[j];
      a[j] = a[j + 1];
      a[j + 1] = temp;
      j++;
    }
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