#include <bits/stdc++.h>

using namespace std;

#define optimize()              \
  cin.tie(0);                   \
  cin.sync_with_stdio(0);       \
  ios_base::sync_with_stdio(0); \
  cout.tie(0);

void solve()
{
  long long int k, l1, r1, l2, r2;

  cin >> k >> l1 >> r1 >> l2 >> r2;

  long long int count = 0;

  int i = 0;
  while (i <= 32)
  {
    long long int interval;
    long long int minLimit;
    long long int maxLimit = r2 / pow(k, i);
    minLimit = (l2 + pow(k, i) - 1) / pow(k, i);
    interval = min(r1, maxLimit) - max(l1, minLimit) + 1;
    interval = max(interval, 0LL);
    count += interval;
    i++;
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