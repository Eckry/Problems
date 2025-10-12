#include <bits/stdc++.h>

using namespace std;

#define ll long long

#define optimize()                                                             \
  cin.tie(0);                                                                  \
  cin.sync_with_stdio(0);                                                      \
  ios_base::sync_with_stdio(0);                                                \
  cout.tie(0);

void solve() {
  ll n;
  cin >> n;
  vector<ll> a(n * 2);
  for (auto &c : a)
    cin >> c;

  vector<ll> oppos(n);
  for (ll i = 0; i < n; i++) {
    oppos[i] = a[2 * n - 1 - i] - a[i];
  }
  vector<ll> even(n);
  for (ll i = 0; i < n; i++) {
    even[i] = a[2 * i + 1] - a[2 * i];
  }
  vector<ll> odd(n - 1);
  for (ll i = 0; i < n - 1; i++) {
    odd[i] = a[2 * i + 2] - a[2 * i + 1];
  }
  vector<ll> evensm(n + 1, 0);
  vector<ll> oddsm(n, 0);
  for (ll i = 1; i <= n; i++) {
    evensm[i] = evensm[i - 1] + even[i - 1];
  }
  for (ll i = 1; i < n; i++) {
    oddsm[i] = oddsm[i - 1] + odd[i - 1];
  }

  // for (auto c : even)
  //   cout << c << " ";
  // cout << "\n";
  // for (auto c : odd)
  //   cout << c << " ";
  // cout << "\n";
  // for (auto c : oddsm)
  //   cout << c << " ";
  // cout << "\n";
  // for (auto c : evensm)
  //   cout << c << " ";
  // cout << "\n";
  // for (auto c : oppos)
  //   cout << c << " ";
  // cout << "\n";
  vector<ll> evenans(n);
  for (int i = 0; i < n; i++) {
    evenans[i] = evensm[n - i] - evensm[i];
  }
  vector<ll> oddans(n);
  for (int i = 0; i < n; i++) {
    oddans[i] = oddsm[n - i - 1] - oddsm[i];
  }

  // for (auto c : oddans)
  //   cout << c << " ";
  // cout << "\n";
  int j = 0;
  int k = 0;
  ll sm = 0;
  for (ll i = 0; i < n; i++) {
    if (i)
      sm += oppos[i - 1];
    ll ans = sm;
    if (i & 1) {
      ans += oddans[k++];
    } else {
      ans += evenans[j++];
    }
    cout << ans << " ";
  }
  cout << "\n";
}

int main() {
  optimize() int T;
  cin >> T;
  while (T--)
    solve();
}
