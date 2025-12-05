#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve() {
  ll n, k, q;
  cin >> n >> k >> q;

  vector<ll> a(k);
  vector<ll> b(k);
  for (auto &c : a)
    cin >> c;
  for (auto &c : b)
    cin >> c;

  while (q--) {
    ll d;
    cin >> d;
    ll right = lower_bound(a.begin(), a.end(), d) - a.begin();
    if (d == a[right]) {
      cout << b[right] << " ";
      continue;
    }
    ll left = right - 1;
    ll timeright = b[right];
    ll distanceright = a[right];
    ll distanceleft;
    ll timeleft;
    if (left == -1) {
      timeleft = 0;
      distanceleft = 0;
    } else {
      timeleft = b[left];
      distanceleft = a[left];
    }
    ll diff = d - distanceleft;

    ll ans = timeleft +
             (diff * (timeright - timeleft)) / (distanceright - distanceleft);
    // cout << distanceleft << " " << distanceright << "\n";
    cout << ans << " ";
    // cout << "\n";
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
