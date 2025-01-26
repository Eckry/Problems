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
  ll lastzero = n - 1;
  ll firstzero = 0;

  while (lastzero > 0 && a[lastzero] == 0)
    lastzero--;
  while (firstzero < n - 1 && a[firstzero] == 1)
    firstzero++;

  ll cnt = 0;
  ll sm = 0;
  ll ans = 0;
  for (int i = 0; i < n; i++)
  {
    if (a[i] == 1)
      cnt++;
    if (a[i] == 0)
      sm += cnt;
  }

  ans = sm;

  a[firstzero] = 1 - a[firstzero];

  cnt = 0;
  sm = 0;
  for (int i = 0; i < n; i++)
  {
    if (a[i] == 1)
      cnt++;
    if (a[i] == 0)
      sm += cnt;
  }
  ans = max(ans, sm);

  a[firstzero] = 1 - a[firstzero];
  a[lastzero] = 1 - a[lastzero];

  cnt = 0;
  sm = 0;
  for (int i = 0; i < n; i++)
  {
    if (a[i] == 1)
      cnt++;
    if (a[i] == 0)
      sm += cnt;
  }
  ans = max(ans, sm);
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