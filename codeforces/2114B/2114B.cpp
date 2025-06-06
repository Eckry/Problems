#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define optimize()              \
  cin.tie(0);                   \
  cin.sync_with_stdio(0);       \
  ios_base::sync_with_stdio(0); \
  cout.tie(0);

void solve()
{
  int n, k;
  cin >> n >> k;

  string s;
  cin >> s;

  int ones = 0;
  int zeros = 0;
  for (auto c : s)
  {
    if (c == '1')
      ones++;
    else
      zeros++;
  }

  int sum = ones / 2 + zeros / 2;

  if (k > sum)
  {
    cout << "NO" << "\n";
    return;
  }

  while (ones > zeros && k > 0)
  {
    k -= 1;
    ones -= 2;
  }
  while (zeros > ones && k > 0)
  {
    k -= 1;
    zeros -= 2;
  }

  if (k > 0)
  {
    int last = 1;
    if (zeros > ones)
      last = 0;
    while (k > 0)
    {
      k--;
      if (last)
      {
        last = 0;
        ones -= 2;
      }
      else
      {
        last = 1;
        zeros -= 2;
      }
    }
  }
  if (zeros == ones)
  {
    cout << "YES" << "\n";
  }
  else
    cout << "NO" << "\n";
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