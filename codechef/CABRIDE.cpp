#include <bits/stdc++.h>
#include <pthread.h>

using namespace std;

#define ll long long

#define optimize()                                                             \
  cin.tie(0);                                                                  \
  cin.sync_with_stdio(0);                                                      \
  ios_base::sync_with_stdio(0);                                                \
  cout.tie(0);

void solve() {
  int n;
  cin >> n;
  int ans = 0;
  if (n == 1) {
    cout << 200 << "\n";
    return;
  }
  if (n & 1) {
    n -= 3;
    ans += 300;
  }
  ans += 200 * (n / 2);

  cout << ans << "\n";
}

int main() {
  optimize();
  int T;
  cin >> T;
  while (T--)
    solve();
}
