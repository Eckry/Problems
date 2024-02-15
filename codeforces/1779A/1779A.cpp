#include <bits/stdc++.h>

using namespace std;

#define optimize()              \
  cin.tie(0);                   \
  cin.sync_with_stdio(0);       \
  ios_base::sync_with_stdio(0); \
  cout.tie(0);

int solve()
{
  int n;
  cin >> n;
  string lamps;
  cin >> lamps;
  for (int i = 1; i < n; i++)
  {
    if (lamps[i - 1] == 'R' && lamps[i] == 'L')
      return 0;
    if (lamps[i - 1] == 'L' && lamps[i] == 'R')
      return i;
  }
  return -1;
}

int main(void)
{
  optimize()

  int T;
  cin >> T;
  while (T--)
    cout << solve() << endl;
}