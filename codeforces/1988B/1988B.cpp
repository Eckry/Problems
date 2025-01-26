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
  vector<int> cnt(2, 0);
  bool flg = 0;
  for (int i = 0; i < n; i++)
  {
    if (s[i] == '1')
    {
      flg = 0;
      cnt[1]++;
    }
    if (s[i] == '0' && !flg)
    {
      flg = 1;
      cnt[0]++;
    }
  }
  if (cnt[0] >= cnt[1])
    cout << "NO" << "\n";
  else
    cout << "YES" << "\n";
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