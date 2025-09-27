#include <bits/stdc++.h>

using namespace std;

#define ll long long

#define optimize()                                                             \
  cin.tie(0);                                                                  \
  cin.sync_with_stdio(0);                                                      \
  ios_base::sync_with_stdio(0);                                                \
  cout.tie(0);

void solve(vector<ll> &ans) {
  ll n;
  cin >> n;
  cout << ans[n] << "\n";
}

int main() {
  optimize();
  vector<vector<ll>> m(2024, vector<ll>(2024));
  ll cnt = 2;
  m[0][0] = 1;
  vector<ll> ans(4096576, 0);
  for (int i = 1; i < 2024; i++) {
    for (int j = 0; j <= i; j++) {
      m[i - j][j] += cnt * cnt;
      if (i - j && j) {
        m[i - j][j] -= m[i - j - 1][j - 1];
      }
      if (i - j) {
        m[i - j][j] += m[i - j - 1][j];
      }
      if (j) {
        m[i - j][j] += m[i - j][j - 1];
      }
      cnt++;
    }
  }
  ans[0] = 1LL;
  ans[1] = 1LL;
  cnt = 2LL;
  for (int i = 1; i < 2024; i++) {
    for (int j = 0; j <= i; j++) {
      ans[cnt] = m[i - j][j];
      cnt++;
    }
  }
  int T;
  cin >> T;
  while (T--)
    solve(ans);
}
