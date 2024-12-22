#include <bits/stdc++.h>

using namespace std;

#define optimize()              \
  cin.tie(0);                   \
  cin.sync_with_stdio(0);       \
  ios_base::sync_with_stdio(0); \
  cout.tie(0);

void solve()
{
  long long int n, a, b, c;

  cin >> n >> a >> b >> c;

  long long int sum = a + b + c;
  long long int r = n % sum;
  long long int div = n / sum;
  if (r == 0)
  {
    cout << div * 3 << "\n";
    return;
  }

  if (r - a <= 0)
  {
    cout << div * 3 + 1 << "\n";
  }
  else if (r - a - b <= 0)
  {
    cout << div * 3 + 2 << "\n";
  }
  else if (r - a - b - c <= 0)
  {
    cout << div * 3 + 3 << "\n";
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