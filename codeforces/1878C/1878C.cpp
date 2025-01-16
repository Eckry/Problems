#include <bits/stdc++.h>

using namespace std;

#define optimize()              \
  cin.tie(0);                   \
  cin.sync_with_stdio(0);       \
  ios_base::sync_with_stdio(0); \
  cout.tie(0);

void solve()
{
  long long n, k, x;
  cin >> n >> k >> x;

  long long sm = (k + 1) * k / 2;
  long long diff = n - k;
  long long mxsm = n * (n + 1) / 2 - diff * (diff + 1) / 2;
  if (sm > x || mxsm < x)
    cout << "NO" << "\n";
  else
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