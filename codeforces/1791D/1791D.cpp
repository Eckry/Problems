#include <bits/stdc++.h>

using namespace std;

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

  map<char, int> m;
  map<char, int> p;

  vector<int> dp(n);
  int l = 0;
  for (int i = 0; i < n; i++)
  {
    if (m[s[i]])
    {
      dp[i] = l;
    }
    else
    {
      l++;
      m[s[i]]++;
      dp[i] = l;
    }
  }

  vector<int> dp2(n);
  int r = 0;
  for (int i = n - 1; i >= 0; i--)
  {
    if (p[s[i]])
    {
      dp2[i] = r;
    }
    else
    {
      r++;
      p[s[i]]++;
      dp2[i] = r;
    }
  }

  int mx = INT_MIN;
  for (int i = 0; i < n - 1; i++)
  {
    mx = max(mx, dp[i] + dp2[i + 1]);
  }
  cout << mx << "\n";

  // for (auto c : dp)
  //   cout << c << " ";
  // cout << "\n";
  // for (auto c : dp2)
  //   cout << c << " ";
  // cout << "\n";
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