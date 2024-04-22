#include <bits/stdc++.h>

using namespace std;

#define optimize()              \
  cin.tie(0);                   \
  cin.sync_with_stdio(0);       \
  ios_base::sync_with_stdio(0); \
  cout.tie(0);

void solve()
{
  int n, k, x;
  cin >> n >> k >> x;
  vector<int> numb(n);
  int maxSum = 0;
  for (int i = 0; i < n; i++)
  {
    cin >> numb[i];
  }

  sort(numb.begin(), numb.end());

  for (int i = 0; i < n; i++)
  {
    if (i < n - x)
      maxSum += numb[i];
    else
      maxSum -= numb[i];
  }

  int newMax = maxSum;

  for (int i = n - 1; i >= n - k; i--)
  {
    if (i - x >= 0)
    {
      newMax = newMax + numb[i] - 2 * numb[i - x];
    }
    else
    {
      newMax = newMax + numb[i];
    }
    newMax = newMax;
    maxSum = max(newMax, maxSum);
  }

  cout << maxSum << endl;
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