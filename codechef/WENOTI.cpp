#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve() {
  ll n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  int first = 0;
  while (first < n && s[first] == 'I')
    first++;
  if (first == n) {
    cout << n * k - 1LL << "\n";
    return;
  }

  if (s[0] == 'I')
    s[0] = s[first];
  for (int i = 1; i < n; i++) {
    if (s[i] == 'I') {
      s[i] = s[i - 1];
    }
  }
  ll ans = 0;
  for (int i = 1; i < n; i++) {
    if (s[i] == s[i - 1])
      ans++;
  }
  ans *= k;
  if (s[0] == s[n - 1]) {
    ans += k - 1;
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--)
    solve();
}
