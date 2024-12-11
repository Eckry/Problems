#include <bits/stdc++.h>

using namespace std;

#define optimize()              \
  cin.tie(0);                   \
  cin.sync_with_stdio(0);       \
  ios_base::sync_with_stdio(0); \
  cout.tie(0);
// 8 10 9 = 17
// 8 20 19 = 27
void solve()
{
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];

  if (k == 1)
  {
    cout << (n - 2) / 2 + (n - 2) % 2 << endl;
    return;
  }

  int ans = 0;

  for (int i = 1; i < n - 1; i++)
  {
    if (a[i - 1] + a[i + 1] >= a[i])
      continue;
    ans++;
    i++;
  }
  cout << ans << endl;
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