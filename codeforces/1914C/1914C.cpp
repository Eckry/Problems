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

  vector<long long> a(n);
  vector<long long> b(n);
  for (auto &c : a)
    cin >> c;
  for (auto &c : b)
    cin >> c;

  long long ans = 0;
  long long sm = 0;
  long long mx = -1;
  for (int i = 0; i < k && i < n; i++)
  {
    sm += a[i];
    mx = max(mx, b[i]);
    ans = max(sm + (k - i - 1) * mx, ans);
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