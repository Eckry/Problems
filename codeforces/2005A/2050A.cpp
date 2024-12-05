#include <bits/stdc++.h>

using namespace std;

#define optimize()              \
  cin.tie(0);                   \
  cin.sync_with_stdio(0);       \
  ios_base::sync_with_stdio(0); \
  cout.tie(0);

void solve()
{
  int n, m;
  cin >> n >> m;

  string s[n];

  for (int i = 0; i < n; i++)
  {
    cin >> s[i];
  }

  int sum = 0;
  int i = 0;
  while (sum < m)
  {
    sum += s[i].size();
    if (sum > m || i >= n)
      break;
    i++;
  }

  cout << i << endl;
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