#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve() {
  int n, c;
  cin >> n >> c;
  vector<int> a(n);
  for (auto &it : a)
    cin >> it;
  string s;
  cin >> s;

  ll coins = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == '0') {
      coins += a[i];
    }
  }
  if (coins < c) {
    cout << coins << "\n";
    return;
  }
  ll newcoins = coins - c;
  for (int i = 0; i < n; i++) {
    if (s[i] == '1') {
      newcoins += a[i];
    }
  }
  cout << max(newcoins, coins) << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--)
    solve();
}
