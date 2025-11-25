#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve() {
  ll n, m;
  cin >> n >> m;

  vector<ll> a(n);
  vector<ll> b(m);
  vector<ll> c(m);
  for (auto &it : a)
    cin >> it;
  for (auto &it : b)
    cin >> it;
  for (auto &it : c)
    cin >> it;

  vector<ll> idx(m);
  iota(idx.begin(), idx.end(), 0);
  sort(idx.begin(), idx.end(), [&](ll x, ll y) { return b[x] < b[y]; });
  multiset<ll> st(a.begin(), a.end());

  ll ans = 0;
  for (ll i = 0; i < m; i++) {
    if (c[idx[i]] == 0)
      continue;
    auto sword = st.lower_bound(b[idx[i]]);
    if (sword == st.end())
      continue;
    ll x = max(*sword, c[idx[i]]);
    c[idx[i]] = -1;
    ans++;
    st.erase(sword);
    st.insert(x);
  }
  for (ll i = 0; i < m; i++) {
    if (c[idx[i]] == -1)
      continue;
    auto sword = st.lower_bound(b[idx[i]]);
    if (sword == st.end())
      continue;
    ans++;
    st.erase(sword);
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
