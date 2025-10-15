#include <bits/stdc++.h>

using namespace std;

#define ll long long

const ll MOD = 1e9 + 7;

void solve() {
  int n, m;
  cin >> n >> m;
  string s, t;
  cin >> s >> t;
  if (m > n) {
    cout << 0 << "\n";
    return;
  }
  vector<vector<ll>> preff(n + 1, vector<ll>(m + 1, 0));
  preff[0][0] = 1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= m; j++) {
      preff[i + 1][j] = (preff[i + 1][j] + preff[i][j]) % MOD;
      if (j < m && s[i] == t[j]) {
        preff[i + 1][j + 1] = (preff[i + 1][j + 1] + preff[i][j]) % MOD;
      }
    }
  }
  vector<vector<ll>> suff(n + 1, vector<ll>(m + 1, 0));
  suff[n][m] = 1;
  for (int i = n - 1; i >= 0; i--) {
    for (int j = m; j >= 0; j--) {
      suff[i][j] = (suff[i][j] + suff[i + 1][j]) % MOD;
      if (j < m && s[i] == t[j]) {
        suff[i][j] = (suff[i][j] + suff[i + 1][j + 1]) % MOD;
      }
    }
  }
  // for (int i = 0; i <= n; i++) {
  //   for (int j = 0; j <= m; j++) {
  //     cout << preff[i][j] << " ";
  //   }
  //   cout << "\n";
  // }
  // cout << "\n";
  // for (int i = 0; i <= n; i++) {
  //   for (int j = 0; j <= m; j++) {
  //     cout << suff[i][j] << " ";
  //   }
  //   cout << "\n";
  // }
  ll orig = preff[n][m] % MOD;
  ll partialans = 0;
  for (int i = 0; i < n; i++) {
    ll newsm = 0;
    ll repeated = 0;
    for (int j = 0; j < m; j++) {
      ll A = (preff[i][j] * suff[i + 1][j + 1]) % MOD;
      newsm = (newsm + A) % MOD;
      if (t[j] == s[i]) {
        repeated = (repeated + A) % MOD;
      }
    }

    ll term1 = (25 * orig) % MOD;
    term1 = (term1 + newsm) % MOD;
    ll minus = (repeated * 26) % MOD;
    partialans = (partialans + term1 - minus + MOD) % MOD;
  }
  cout << (orig + partialans) % MOD << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  int T;
  T = 1;
  while (T--)
    solve();
}
