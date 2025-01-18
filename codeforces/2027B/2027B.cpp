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
  vector<long long> a(n);
  for (auto &c : a)
    cin >> c;

  int ans = INT_MAX;

  for (int i = 0; i < n; i++)
  {
    int cnt = i;
    for (int j = i + 1; j < n; j++)
    {
      if (a[i] < a[j])
      {
        cnt++;
      }
    }
    ans = min(ans, cnt);
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