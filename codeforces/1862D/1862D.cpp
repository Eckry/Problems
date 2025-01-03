#include <bits/stdc++.h>

using namespace std;

#define optimize()              \
  cin.tie(0);                   \
  cin.sync_with_stdio(0);       \
  ios_base::sync_with_stdio(0); \
  cout.tie(0);

void solve()
{
  long long int n;
  cin >> n;

  if (n == 1)
  {
    cout << 2 << "\n";
    return;
  }

  long long int l = 1;
  long long int r = 6e9;

  while (l != r)
  {
    long long int mid = (l + r + 1) / 2;
    long long int op = mid * (mid + 1) / 2;

    if (op == n)
    {
      r = mid;
      break;
    }

    if (op > n)
    {
      r = mid - 1;
    }
    else
    {
      l = mid;
    }
  }
  long long int op = r * (r + 1) / 2;
  if (op == n)
  {
    cout << r + 1 << "\n";
  }
  else
  {
    cout << r + 1 + n - op << "\n";
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