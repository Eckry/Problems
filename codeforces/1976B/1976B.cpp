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
  vector<long long> b(n + 1);
  for (auto &c : a)
    cin >> c;
  for (auto &c : b)
    cin >> c;

  long long mn = INT_MAX;
  bool flg = 1;
  long long sm = 0;
  for (int i = 0; i < n; i++)
  {
    long long diff = abs(a[i] - b[i]);
    if (a[i] >= b[i])
    {
      if (flg && a[i] >= b[n] && b[n] >= b[i])
      {
        flg = 0;
      }
    }
    else
    {
      if (flg && a[i] <= b[n] && b[n] <= b[i])
      {
        flg = 0;
      }
    }
    long long diff2 = abs(a[i] - b[n]);
    mn = min(diff2, mn);
    sm += diff;
    a[i] = b[i];
  }

  if (flg)
  {
    for (int i = 0; i < n; i++)
    {
      long long diff = abs(a[i] - b[n]);
      mn = min(diff, mn);
    }

    cout << sm + 1 + mn << "\n";
  }
  else
    cout << sm + 1 << "\n";

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