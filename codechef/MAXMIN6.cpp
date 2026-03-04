#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve() {
  ll n;
  cin >> n;
  vector<ll> a(n);
  for (auto &c : a)
    cin >> c;

  set<ll> st;
  for (int i = 0; i < n; i++) {
    st.insert(a[i]);
  }
  ll ans = LONG_LONG_MAX;
  for (int i = 0; i < 100000; i++) {
    ll mn = *st.begin();
    ll mx = *prev(st.end());
    ans = min(ans, mx - mn);
    st.erase(st.begin());
    st.insert(mn * 2);
    if (mn * 2 > 1e18)
      break;
  }
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
