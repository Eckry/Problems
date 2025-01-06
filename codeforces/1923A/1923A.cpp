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
  for (auto &c : a)
    cin >> c;

  bool flg = 0;
  int count = 0;
  int l = 0;
  int r = n - 1;
  while (a[r] == 0 && r >= 0)
    r--;
  while (a[l] == 0 && l < n)
    l++;

  int ans = 0;

  for (int i = l; i <= r; i++)
  {
    if (!a[i])
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