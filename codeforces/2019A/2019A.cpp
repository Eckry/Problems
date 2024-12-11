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
  vector<int> a(n);
  int maxE = 0;
  int maxIdx = 0;
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
    if (maxE <= a[i])
    {
      maxE = a[i];
      maxIdx = i;
    }
  }

  if (n % 2 == 0)
  {
    cout << maxE + n / 2 << endl;
  }
  else
  {
    int max1 = 0, max2 = 0;
    int q1 = n / 2 + 1;
    int q2 = n / 2;
    for (int i = 0; i < n; i++)
    {
      if (i % 2 == 0)
      {
        max1 = max(max1, a[i]);
      }
      else
      {
        max2 = max(max2, a[i]);
      }
    }
    cout << max(max1 + q1, max2 + q2) << endl;
  }
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