#include <bits/stdc++.h>

using namespace std;

#define optimize()              \
  cin.tie(0);                   \
  cin.sync_with_stdio(0);       \
  ios_base::sync_with_stdio(0); \
  cout.tie(0);

void solve()
{
  string s;
  cin >> s;

  if (s == "abc")
    cout << "YES" << endl;
  if (s == "acb")
    cout << "YES" << endl;
  if (s == "bac")
    cout << "YES" << endl;
  if (s == "bca")
    cout << "NO" << endl;
  if (s == "cab")
    cout << "NO" << endl;
  if (s == "cba")
    cout << "YES" << endl;
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