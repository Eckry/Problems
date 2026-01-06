#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve() {
  ll n;
  cin >> n;
  vector<ll> a(n);
  vector<ll> b(n);
  for (auto &c : a)
    cin >> c;
  for (auto &c : b)
    cin >> c;

  vector<ll> pref(n + 1, 0);
  vector<ll> ans(n + 1, 0);
  vector<ll> sm(n + 1, 0);
  for (int i = 1; i <= n; i++) {
    sm[i] = sm[i - 1] + b[i - 1];
  }

  for (int i = 0; i < n; i++) {
    int j = lower_bound(sm.begin(), sm.end(), a[i] + sm[i]) - sm.begin();
    pref[i] += 1;
    pref[j - 1] -= 1;
    a[i] -= sm[j - 1] - sm[i];
    ans[j - 1] += a[i];
  }
  for (int i = 1; i < n; i++) {
    pref[i] += pref[i - 1];
  }
  for (int i = 0; i < n; i++) {
    ans[i] += pref[i] * b[i];
  }
  for (int i = 0; i < n; i++) {
    cout << ans[i] << " ";
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
