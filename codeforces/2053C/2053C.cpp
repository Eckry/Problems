#include <bits/stdc++.h>

using namespace std;

#define optimize()              \
  cin.tie(0);                   \
  cin.sync_with_stdio(0);       \
  ios_base::sync_with_stdio(0); \
  cout.tie(0);

void solve()
{
  long long int n, k;
  cin >> n >> k;

  long long int m = n + 1;
  long long int count = 0;
  long long int cur = 1;

  while (n >= k)
  {
    if (n & 1)
      count += cur;
    cur *= 2;
    n /= 2;
  }

  cout << m * count / 2 << "\n";
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