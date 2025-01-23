#include <bits/stdc++.h>

using namespace std;
#define ll long long;
#define optimize()              \
  cin.tie(0);                   \
  cin.sync_with_stdio(0);       \
  ios_base::sync_with_stdio(0); \
  cout.tie(0);

void solve()
{
  string s;
  cin >> s;
  int zero = -1;
  int one = -1;
  int n = s.size();
  if (n == 1)
  {
    cout << 1 << "\n";
    return;
  }

  for (int i = 0; i < n; i++)
  {
    if (s[i] == '1')
      one = i;
    if (s[i] == '0' && zero == -1)
      zero = i;
  }

  if (one == -1 && zero == -1)
  {
    cout << n << "\n";
  }
  else if (one == -1)
  {
    cout << zero + 1 << "\n";
  }
  else if (zero == -1)
  {
    cout << n - one << "\n";
  }
  else
  {
    if (one < zero)
    {
      cout << zero - one + 1 << "\n";
      return;
    }
    if (zero < one)
    {
      cout << n - one << "\n";
      return;
    }
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