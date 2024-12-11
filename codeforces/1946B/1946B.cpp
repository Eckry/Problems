#include <bits/stdc++.h>

using namespace std;

#define optimize()              \
  cin.tie(0);                   \
  cin.sync_with_stdio(0);       \
  ios_base::sync_with_stdio(0); \
  cout.tie(0);

const int MOD = 1e9 + 7;
void solve()
{
  long long int n, k;
  cin >> n >> k;

  vector<long long int> a(n);
  for (long long int i = 0; i < n; i++)
    cin >> a[i];

  long long int sum = a[0];
  long long int curr = a[0];

  for (int i = 1; i < n; i++)
  {
    curr = max(a[i], curr + a[i]);
    sum = max(sum, curr);
  }

  long long int original = sum;

  if (sum > 0)
    while (k--)
    {
      sum += sum;
      sum %= MOD;
    }

  long long int ans = 0;
  for (int i = 0; i < n; i++)
    ans += a[i];

  ans += sum - original;

  long long int result = ans % MOD;
  if (ans < 0)
    result = (ans % MOD + MOD) % MOD;

  cout << result << endl;
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