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

  int f = a[0];
  int l = a[n - 1];

  int fc = 0;
  int lc = 0;

  for (int i = 0; a[i] == f; fc++, i++)
    ;
  for (int i = n - 1; a[i] == l; lc++, i--)
    ;
  int ans;
  if (f == l)
  {
    ans = n - fc - lc;
  }
  else if (fc > lc)
  {
    ans = n - fc;
  }
  else if (lc >= fc)
  {
    ans = n - lc;
  }

  cout << max(ans, 0) << "\n";
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