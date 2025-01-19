#include <bits/stdc++.h>

using namespace std;

#define optimize()              \
  cin.tie(0);                   \
  cin.sync_with_stdio(0);       \
  ios_base::sync_with_stdio(0); \
  cout.tie(0);

void solve()
{
  vector<int> a(5);
  cin >> a[0] >> a[1] >> a[3] >> a[4];

  a[2] = a[0] + a[1];
  int ans = INT_MIN;
  int cnt1 = 0;
  for (int i = 2; i < 5; i++)
  {
    if (a[i - 1] + a[i - 2] == a[i])
      cnt1++;
  }

  a[2] = a[3] - a[1];
  int cnt2 = 0;
  for (int i = 2; i < 5; i++)
  {
    if (a[i - 1] + a[i - 2] == a[i])
      cnt2++;
  }

  a[2] = a[4] - a[3];
  int cnt3 = 0;
  for (int i = 2; i < 5; i++)
  {
    if (a[i - 1] + a[i - 2] == a[i])
      cnt3++;
  }

  ans = max(max(cnt1, cnt2), cnt3);

  cout
      << ans << "\n";
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