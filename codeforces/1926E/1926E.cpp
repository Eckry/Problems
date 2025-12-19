#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve() {
  ll n, k;
  cin >> n >> k;
  if (k <= (n + 1) / 2) {
    cout << (k - 1) * 2 + 1 << "\n";
    return;
  }
  vector<ll> power(33, 1);
  for (ll i = 0; i <= 32; i++) {
    power[i] = (1LL << i);
  }
  ll i = 1;
  while ((n - power[i - 1] + power[i]) / (power[i]) < k) {
    k -= (n - power[i - 1] + power[i]) / (power[i]);
    i++;
  }
  ll cnt = power[i - 1];
  k--;
  while (k--) {
    cnt += power[i];
  }
  cout << cnt << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--)
    solve();
}
