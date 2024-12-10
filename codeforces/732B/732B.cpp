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

  vector<int> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];

  int walks = 0;

  for (int i = 0; i < n - 1; i++)
  {
    int sum = a[i] + a[i + 1];
    if (sum >= k)
      continue;
    else
    {
      int diff = k - sum;
      a[i + 1] += diff;
      walks += diff;
    }
  }

  cout << walks << endl;
  for (int i = 0; i < n; i++)
    cout << a[i] << " ";
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