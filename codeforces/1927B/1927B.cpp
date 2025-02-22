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
  vector<int> a(n);
  for (auto &c : a)
    cin >> c;
  vector<int> cnt(26, 0);
  string ans = "";
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < 26; j++)
    {
      if (a[i] == cnt[j])
      {
        ans += char(97 + j);
        cnt[j]++;
        break;
      }
    }
  }
  cout << ans << "\n";
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