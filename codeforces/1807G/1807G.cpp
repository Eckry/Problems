#include <bits/stdc++.h>

using namespace std;

#define optimize()              \
  cin.tie(0);                   \
  cin.sync_with_stdio(0);       \
  ios_base::sync_with_stdio(0); \
  cout.tie(0);

void solve()
{
  long long int n;
  cin >> n;
  vector<long long int> a(n);
  for (long long int i = 0; i < n; i++)
    cin >> a[i];
  sort(a.begin(), a.end());

  if (a[0] != 1)
  {
    cout << "NO" << endl;
    return;
  }

  vector<long long int> obj;
  obj.push_back(1);

  vector<int> dp(5005, 0);
  dp[1] = 1;
  for (long long int i = 1; i < n; i++)
  {
    if (!dp[a[i]])
    {
      cout << "NO" << endl;
      return;
    }

    for (int j = 5000; j >= a[i]; j--)
    { 
      dp[j] |= dp[j - a[i]]; 
    }
  }

  cout << "YES" << endl;
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