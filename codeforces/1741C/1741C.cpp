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

  long long sm = 0;
  int mx = -1;
  for (int i = 0; i < n; i++)
  {
    mx = max(mx, a[i]);
    sm += a[i];
  }

  int mn = INT_MAX;
  for (long long val = sm; val >= mx; val--)
  {
    long long ob = 0;
    int mxlen = -1;
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
      cnt++;
      ob += a[i];
      if (ob > val)
      {
        if (mxlen == -1)
          val = ob - a[i] + 1;
        mxlen = INT_MAX;
        break;
      }
      if (ob == val)
      {
        mxlen = max(cnt, mxlen);
        ob = 0;
        cnt = 0;
      }
    }
    if (ob == 0)
      mn = min(mn, mxlen);
  }
  if (mn == INT_MAX)
  {
    cout << n << "\n";
  }
  else
    cout << mn << "\n";
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