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

  vector<int> q(n + 2, 0);
  int mn = 1001;
  for (auto c : a)
  {
    q[c]++;
    mn = min(c, mn);
  }
  for (int i = mn; i <= n; i++)
  {
    if (q[i] == 0)
      continue;
    if (q[i] >= 2)
    {
      q[i + 1] += q[i] - 2;
      q[i] = 2;
    }
    else
    {
      cout << "NO" << "\n";
      return;
    }
  }
  cout << "YES" << "\n";
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