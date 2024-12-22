#include <bits/stdc++.h>

using namespace std;

#define optimize()              \
  cin.tie(0);                   \
  cin.sync_with_stdio(0);       \
  ios_base::sync_with_stdio(0); \
  cout.tie(0);

void solve()
{
  string a;
  string b;
  cin >> a >> b;

  int n = a.size();
  int m = b.size();

  int sum = INT_MIN;

  for (int i = 0; i < m; i++)
  {
    int j = i;
    for (auto c : a)
    {
      if (c == b[j])
        j++;
    }

    sum = max(sum, j - i);
  }

  cout << n + m - sum << "\n";
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