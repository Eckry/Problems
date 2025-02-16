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
  string ans = "I hate ";
  for (int i = 0; i < n - 1; i++)
  {
    ans += "that I ";
    if (i & 1)
      ans += "hate ";
    else
      ans += "love ";
  }
  ans += "it";
  cout << ans << "\n";
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