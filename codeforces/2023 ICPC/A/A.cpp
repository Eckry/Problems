#include <bits/stdc++.h>

using namespace std;

#define optimize()              \
  cin.tie(0);                   \
  cin.sync_with_stdio(0);       \
  ios_base::sync_with_stdio(0); \
  cout.tie(0);

void solve()
{
  int N;
  cin >> N;
  map<string, int> names;
  while (N--)
  {
    int X;
    cin >> X;
    string s = "";
    string m;
    while (X--)
    {
      cin >> m;
      s += m[0];
    }
    if (names[s] == 0)
      names[s] = 1;
    else
      names[s] = -1;
  }

  int count = 0;
  for (auto const &[t, k] : names)
  {
    if (k != -1)
      count++;
  }
  cout << count << endl;
}

int main(void)
{
  optimize();
  int T;
  // cin >> T;
  T = 1;
  while (T--)
    solve();
}