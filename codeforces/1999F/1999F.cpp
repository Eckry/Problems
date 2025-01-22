#include <bits/stdc++.h>

using namespace std;

#define optimize()              \
  cin.tie(0);                   \
  cin.sync_with_stdio(0);       \
  ios_base::sync_with_stdio(0); \
  cout.tie(0);

const int N = 2e5 + 5, MOD = 1e9 + 7;
int64_t fact[N];
int64_t pw(int64_t a, int64_t b)
{
  int64_t r = 1;
  while (b > 0)
  {
    if (b & 1)
      r = (r * a) % MOD;
    b /= 2;
    a = (a * a) % MOD;
  }
  return r;
}
int64_t nCr(int64_t n, int64_t k)
{
  if (n < k)
    return 0LL;
  return (fact[n] * pw((fact[n - k] * fact[k]) % MOD, MOD - 2)) % MOD;
}

void solve()
{
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (auto &c : a)
    cin >> c;
  vector<int> cnt(2, 0);

  for (int i = 0; i < n; i++)
  {
    cnt[a[i]]++;
  }

  if (cnt[0] <= k / 2)
  {
    cout << nCr(n, k) << "\n";
    return;
  }

  int64_t ans = 0;
  for (int i = (k + 1) / 2; i <= k; i++)
  {
    if (cnt[1] < i)
      break;
    if (i == k)
    {
      ans += (nCr(cnt[1], i)) % MOD;
    }
    else
      ans += (nCr(cnt[1], i) * nCr(cnt[0], k - i)) % MOD;
    ans %= MOD;
  }

  cout << ans << "\n";
}

int main(void)
{
  optimize();
  fact[0] = 1;
  for (int64_t i = 1; i < N; ++i)
    fact[i] = (fact[i - 1] * i) % MOD;
  int T;
  cin >> T;
  // T = 1;
  while (T--)
    solve();
}