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
  bool ok = 0;
  for (auto c : s)
  {
    if (c == '1')
    {
      ok = 1;
    }
  }
  if (!ok)
  {
    cout << 0 << "\n";
    return;
  }

  int cnt = 0;
  int start = -1;
  bool seen = 0;
  for (int i = s.size() - 1; i >= 0; i--)
  {
    if (s[i] == '0')
    {
      start = i;
      break;
    }
    if (s[i] == '1')
      seen = 1;
  }
  if (seen)
    cnt = 1;

  bool flg = 0;
  for (int i = start; i >= 0; i--)
  {
    if (s[i] == '1' && !flg)
    {
      cnt += 2;
      flg = 1;
    }
    else if (flg && s[i] == '0')
    {
      flg = 0;
    }
  }
  cout << cnt << "\n";
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