#include <bits/stdc++.h>

using namespace std;

#define ll long long

#define optimize()                \
    cin.tie(0);                   \
    cin.sync_with_stdio(0);       \
    ios_base::sync_with_stdio(0); \
    cout.tie(0);

void solve() {
  ll n, k; cin >> n >> k;
  vector<ll> a(n);
  for(auto &c : a) cin >> c;
  vector<ll> b(k);
  for(auto &c : b) cin >> c;

  sort(a.begin(), a.end(), greater<>());
  sort(b.begin(), b.end());

  ll cnt = 0;
  ll idx = 0;
  ll ans = 0;
  for(int i = 0 ;i<n;i++) {
    ans += a[i];
    cnt++;
    if(idx < k && cnt == b[idx]){
      cnt = 0;
      ans -= a[i];
      idx++;
    }
  }
  cout << ans << "\n";
}

int main() {
  optimize()
  int T;
  cin >> T;
  while(T--) solve();
}
