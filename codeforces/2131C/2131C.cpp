#include <bits/stdc++.h>

using namespace std;

#define ll long long

#define optimize()                                                             \
  cin.tie(0);                                                                  \
  cin.sync_with_stdio(0);                                                      \
  ios_base::sync_with_stdio(0);                                                \
  cout.tie(0);

void solve() {
  ll n, k;
  cin >> n >> k;
  vector<ll> s(n);
  vector<ll> t(n);
  for (auto &c : s)
    cin >> c;
  for (auto &c : t)
    cin >> c;
  for (int i = 0; i < n; i++) {
    s[i] = min(s[i] % k, (k - s[i] % k));
    t[i] = min(t[i] % k, (k - t[i] % k));
  }
  sort(s.begin(), s.end());
  sort(t.begin(), t.end());
  for (int i = 0; i < n; i++) {
    if (s[i] != t[i]) {
      cout << "NO" << "\n";
      return;
    }
  }
  cout << "YES" << "\n";
}

int main() {
  int T;
  cin >> T;
  while (T--)
    solve();
}
