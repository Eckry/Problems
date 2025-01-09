#include <bits/stdc++.h>

using namespace std;

#define optimize()              \
  cin.tie(0);                   \
  cin.sync_with_stdio(0);       \
  ios_base::sync_with_stdio(0); \
  cout.tie(0);

void solve()
{
  int n;
  cin >> n;
  string s;
  cin >> s;

  vector<int> p(2);
  p[0] = 0;
  p[1] = 0;

  for (int i = 0; i < n - 1; i++)
  {
    p[s[i] - '0'] = i + 1;
    if (s[i] == '0')
    {
      cout << p[1] + 1 << " ";
    }
    else
      cout << p[0] + 1 << " ";
  }
  cout << "\n";
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