#include <bits/stdc++.h>
#include <pthread.h>

using namespace std;

#define ll long long

void solve() {
  ll n, x;
  cin >> n >> x;
  vector<ll> a(n);
  vector<ll> b(n);
  vector<ll> c(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i] >> c[i];
  }

  ll pos = 0;
  for (int i = 0; i < n; i++) {
    pos += a[i] * (b[i] - 1);
  }
  if (pos >= x) {
    cout << 0 << "\n";
    return;
  }

  ll best = -1;
  ll mx = 0;
  for (int i = 0; i < n; i++) {
    ll can = a[i] - c[i] + a[i] * (b[i] - 1);
    if (can > 0 && mx < can) {
      best = i;
      mx = can;
    }
  }
  if (best == -1) {
    cout << -1 << "\n";
    return;
  }
  // cout << pos << "\n";
  ll qnt = a[best] - c[best] + a[best] * (b[best] - 1);
  ll ans = 0;
  ll d = (x - pos) / qnt;
  pos += d * qnt;
  // cout << pos << "\n";
  ans += d;
  if (pos < x)
    ans++;
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
