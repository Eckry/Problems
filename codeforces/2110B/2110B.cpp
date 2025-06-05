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
  string s;
  cin >> s;
  int n = s.size();
  int cnt = 1;
  for (int i = 1; i < n; i++)
  {
    if (i != n - 1 && cnt == 0)
    {
      cout << "YES" << "\n";
      return;
    }
    if (s[i] == '(')
      cnt++;
    else
      cnt--;
  }
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