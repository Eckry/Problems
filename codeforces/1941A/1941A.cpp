#include <bits/stdc++.h>

using namespace std;

#define optimize()              \
  cin.tie(0);                   \
  cin.sync_with_stdio(0);       \
  ios_base::sync_with_stdio(0); \
  cout.tie(0);

void solve()
{
  int n, m, k;
  cin >> n >> m >> k;

  vector<int> b(n);
  vector<int> c(m);
  for (auto &d : b)
    cin >> d;
  for (auto &d : c)
    cin >> d;

  sort(c.begin(), c.end());

  int count = 0;

  for (int i = 0; i < n; i++)
  {
    int l = b[i];
    int limit = upper_bound(c.begin(), c.end(), k - l) - c.begin();
    count += limit;
  }

  cout << count << "\n";
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