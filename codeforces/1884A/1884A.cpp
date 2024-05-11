#include <bits/stdc++.h>

using namespace std;

#define optimize()              \
  cin.tie(0);                   \
  cin.sync_with_stdio(0);       \
  ios_base::sync_with_stdio(0); \
  cout.tie(0);

#define MAX 100

void solve()
{
  int x, k;
  cin >> x >> k;
  string x2;

  x2 = to_string(x);

  int sum = 0;
  for (auto it : x2)
  {
    sum += it - '0';
  }

  while (sum % k != 0)
  {
    sum = 0;
    x++;
    x2 = to_string(x);
    for (auto it : x2)
    {
      sum += it - '0';
    }
  }

  cout << x << endl;
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