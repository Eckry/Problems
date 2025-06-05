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
  int n;
  cin >> n;
  string s;
  cin >> s;

  if (s[0] == 'A' && s[n - 1] == 'A')
  {
    cout << "Alice" << "\n";
    return;
  }

  if (s[n - 2] == 'A' && s[n - 1] == 'A')
  {
    cout << "Alice" << "\n";
    return;
  }

  int flg = 0;
  for (int i = 0; i < n - 1; i++)
  {
    if (s[i] == 'B')
      flg = 1;
  }

  if (!flg && s[n - 1] == 'B')
  {
    cout << "Alice" << "\n";
    return;
  }
  cout << "Bob" << "\n";
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