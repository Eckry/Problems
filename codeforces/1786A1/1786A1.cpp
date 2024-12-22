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
  n--;
  long long int a = 1, b = 0;
  long long int i = 5;
  bool turn = 1;
  while (i < n)
  {
    if (turn)
    {
      turn = 0;
      b += i;
    }
    else
    {
      a += i;
      turn = 1;
    }
    n -= i;
    i += 4;
  }

  if (turn)
  {
    b += max(n, 0LL);
  }
  else
  {
    a += max(n, 0LL);
  }

  cout << a << " " << b << "\n";
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