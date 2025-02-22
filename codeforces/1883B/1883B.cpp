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
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  vector<int> cnt(26, 0);
  for (auto c : s)
    cnt[c - 'a']++;
  int odd = 0;
  for (auto c : cnt)
  {
    if (c & 1)
      odd++;
  }
  if (max(odd - k, 1) == 1)
    cout << "YES" << "\n";
  else
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