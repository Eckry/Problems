#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve() {
  ll n;
  cin >> n;
  vector<ll> a(n);
  for (auto &c : a)
    cin >> c;

  vector<ll> ans(n);
  for (ll i = 1; i < n - 1; i++) {
    ll left = a[i] - a[i - 1];
    ll right = a[i + 1] - a[i];
    ll dif = right - left;
    dif >>= 1;
    ans[i] = dif;
  }
  ll acc = 0;
  for (ll i = 1; i < n - 1; i++) {
    acc += ans[i] * (n - i - 1);
  }
  // cout << acc << "\n";
  acc = a[n - 1] - acc;
  acc /= (n - 1);
  ans[0] = acc;
  acc = 0;
  for (ll i = 1; i < n - 1; i++) {
    acc += ans[i] * (i);
  }
  // cout << acc << "\n";
  acc = a[0] - acc;
  acc /= (n - 1);
  ans[n - 1] = acc;
  for (auto c : ans) {
    cout << c << " ";
  }
  cout << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--)
    solve();
}
