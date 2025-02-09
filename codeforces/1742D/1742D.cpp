#include <bits/stdc++.h>

using namespace std;
#define ll long long
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
  for (auto &c : a)
    cin >> c;
  vector<int> idx(1001, -1);
  for (int i = 0; i < n; i++)
  {
    idx[a[i]] = i + 1;
  }
  int ans = -1;
  for (int i = 1; i <= 1000; i++)
  {
    if (idx[i] == -1)
      continue;
    for (int j = i; j <= 1000; j++)
    {
      if (idx[j] == -1)
        continue;
      if (__gcd(i, j) == 1)
        ans = max(ans, idx[i] + idx[j]);
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