#include <bits/stdc++.h>

using namespace std;

#define optimize()              \
  cin.tie(0);                   \
  cin.sync_with_stdio(0);       \
  ios_base::sync_with_stdio(0); \
  cout.tie(0);

void solve()
{
  int n, x;
  cin >> n >> x;

  vector<int> a(n);
  vector<int> b(n);
  for (auto &c : a)
    cin >> c;
  for (auto &c : b)
    cin >> c;
  sort(b.begin(), b.end());
  vector<int> idx(n);
  iota(idx.begin(), idx.end(), 0);
  sort(idx.begin(), idx.end(), [&](int l, int r)
       { return a[l] < a[r]; });

  vector<int> ans(n);

  for (int i = 0; i < x; i++)
    ans[idx[n + i - x]] = b[i];

  for (int i = x; i < n; i++)
    ans[idx[i - x]] = b[i];

  for (int i = 0; i < n; i++)
  {
    x -= a[i] > ans[i];
  }

  if (x == 0)
  {
    cout << "YES\n";
    for (auto c : ans)
      cout << c << " ";
    cout << "\n";
  } else {
    cout << "NO\n";
  }
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