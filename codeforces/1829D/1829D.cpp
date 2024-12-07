#include <bits/stdc++.h>

using namespace std;

#define optimize()              \
  cin.tie(0);                   \
  cin.sync_with_stdio(0);       \
  ios_base::sync_with_stdio(0); \
  cout.tie(0);

bool check(long long int n, long long int m)
{
  if (n == m)
    return 1;
  if (n % 3 != 0)
    return 0;
  long long int x = n / 3;
  long long int a = x * 2;
  long long int b = x;

  return max(check(a, m), check(b, m));
}

void solve()
{
  long long int n, m;
  cin >> n >> m;

  if (n == m)
  {
    cout << "YES" << endl;
    return;
  }

  if (n % 3 != 0)
  {
    cout << "NO" << endl;
    return;
  }

  string res = check(n, m) ? "YES" : "NO";

  cout << res << endl;
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