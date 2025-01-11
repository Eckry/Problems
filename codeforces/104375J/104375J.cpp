#include <bits/stdc++.h>

using namespace std;

#define optimize()              \
  cin.tie(0);                   \
  cin.sync_with_stdio(0);       \
  ios_base::sync_with_stdio(0); \
  cout.tie(0);

const long long MOD = 1e9 + 7;

void solve()
{
  long long N, Q;
  cin >> N >> Q;

  vector<long long> sm(N + 1, 0);
  vector<long long> sqsm(N + 1, 0);
  vector<long long> A(N);

  for (auto &c : A)
  {
    cin >> c;
  }

  for (int i = 1; i <= N; i++)
  {
    sm[i] = (sm[i - 1] + A[i - 1]) % MOD;
    sqsm[i] = (sqsm[i - 1] + (A[i - 1] * A[i - 1]) % MOD) % MOD;
  }

  while (Q--)
  {
    long long L, R;
    cin >> L >> R;

    long long range_sum = (sm[R] - sm[L - 1] + MOD) % MOD;
    long long range_sq_sum = (sqsm[R] - sqsm[L - 1] + MOD) % MOD;

    long long total_energy = ((range_sum * range_sum) % MOD - range_sq_sum + MOD) % MOD;

    if (total_energy % 2 == 0)
    {
      total_energy /= 2;
    }
    else
    {
      total_energy = (total_energy + MOD) / 2;
    }

    cout << total_energy % MOD << "\n";
  }
}

int main()
{
  optimize();
  int T = 1;
  while (T--)
    solve();
}