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

  int count = 0;
  int seen = 0;
  for (int i = 0; i < s.size(); i++)
    if (s[i] == '0')
      seen = 1;
    else
    {
      if (seen)
        count++;
      seen = 0;
    }

  if (s[s.size() - 1] == '0')
    count++;
  cout << min(count, 2) << "\n";
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