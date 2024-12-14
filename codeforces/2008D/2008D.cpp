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
  vector<int> a(n);
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }

  string s;
  cin >> s;
  vector<int> dp(n, 0);
  map<int, int> m;
  for (int i = 0; i < n; i++)
  {
    int count = 0;
    while (!m[a[i]])
    {
      m[a[i]] = 1;
      if (s[i] == '0')
        count++;
      i = a[i] - 1;
    }

    while (m[a[i]] != 2)
    {
      m[a[i]] = 2;
      dp[i] = count;
      i = a[i] - 1;
    }
  }

  for (int i = 0; i < n; i++)
    cout << dp[i] << " ";
  cout << "\n";
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