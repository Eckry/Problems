#include <bits/stdc++.h>

using namespace std;

#define optimize()              \
  cin.tie(0);                   \
  cin.sync_with_stdio(0);       \
  ios_base::sync_with_stdio(0); \
  cout.tie(0);

void solve()
{
  int n, m;
  cin >> n >> m;
  vector<long long> a(n);
  for (auto &c : a)
    cin >> c;
  vector<long long> ans(n + 1);
  vector<long long> ans2(n + 1);
  ans[0] = 0;
  ans2[n - 1] = 0;
  for (int i = 1; i < n; i++)
  {
    ans[i] = ans[i - 1] + max(a[i - 1] - a[i], 0LL);
  }

  for (int i = n - 2; i >= 0; i--)
  {
    ans2[i] = ans2[i + 1] + max(a[i + 1] - a[i], 0LL);
  }

  while (m--)
  {
    int s, t;
    cin >> s >> t;
    t--;
    s--;
    if (s < t)
    {
      cout << ans[t] - ans[s] << "\n";
    }
    else
      cout << ans2[t] - ans2[s] << "\n";
  }
}

int main(void)
{
  optimize();
  int T;
  T = 1;
  while (T--)
    solve();
}