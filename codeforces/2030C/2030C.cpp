#include <bits/stdc++.h>

using namespace std;

#define optimize()              \
  cin.tie(0);                   \
  cin.sync_with_stdio(0);       \
  ios_base::sync_with_stdio(0); \
  cout.tie(0);

void solve()
{
  int l;
  cin >> l;

  string s;
  cin >> s;

  if (s[0] == '1' || s[l - 1] == '1')
  {
    cout << "YES" << endl;
    return;
  }
  for (int i = 0; i < l - 1; i++)
  {
    if (s[i] == '1' && s[i + 1] == '1')
    {
      cout << "YES" << endl;
      return;
    }
  }
  cout << "NO" << endl;
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