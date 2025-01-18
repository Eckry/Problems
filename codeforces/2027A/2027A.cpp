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
  int mxH = 0;
  int mxW = 0;
  while (n--)
  {
    int w, h;
    cin >> w >> h;

    mxH = max(mxH, h);
    mxW = max(mxW, w);
  }

  cout << mxH * 2 + mxW * 2 << "\n";
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