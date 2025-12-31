#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve() {
  ll n;
  cin >> n;
  string s;
  cin >> s;
  ll swaps = 0;
  ll zeros = 0;
  ll ones = 0;
  ll ans = 0;
  queue<ll> q;
  for (ll i = 0; i < n; i++) {
    if (s[i] == '1')
      q.push(i);
  }
  for (ll i = 0; i < n; i++) {
    if (zeros == ones && s[i] == '0' && q.size()) {
      ll idx = q.front();
      s[i] = '1';
      s[idx] = '0';
      swaps += idx - i;
    }
    if (s[i] == '1' && q.size()) {
      q.pop();
      ones++;
    }
    if (s[i] == '0') {
      zeros++;
    }
    if (ones >= zeros) {
      ans++;
    }
  }
  cout << ans << " " << swaps << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--)
    solve();
}
