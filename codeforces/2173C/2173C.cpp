#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve() {
  ll n, k;
  cin >> n >> k;
  set<ll> st;
  map<ll, ll> mp;
  for (int i = 0; i < n; i++) {
    ll x;
    cin >> x;
    st.insert(x);
    mp[x]++;
  }
  vector<ll> ans;

  for (auto it = st.begin(); it != st.end();) {
    ll x = *it;
    ans.push_back(x);
    for (int i = x * 2; i <= k; i += x) {
      if (!mp[i]) {
        cout << -1 << "\n";
        return;
      }
      auto t = st.find(i);
      if (t != st.end()) {
        st.erase(t);
      }
    }
    it++;
  }
  cout << ans.size() << "\n";
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
