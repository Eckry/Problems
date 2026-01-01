#include <bits/stdc++.h>

using namespace std;

#define ll long long
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

typedef __gnu_pbds::tree<int, __gnu_pbds::null_type, less<int>,
                         __gnu_pbds::rb_tree_tag,
                         __gnu_pbds::tree_order_statistics_node_update>
    ordered_set;

void solve() {
  ll n;
  cin >> n;
  vector<pair<ll, ll>> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i].first >> a[i].second;
  }
  sort(a.begin(), a.end());
  ll ans = 0;
  ordered_set st;
  for (int i = 0; i < n; i++) {
    // ans += number of elements greater than a[i].second
    ans += st.size() - st.order_of_key(a[i].second);
    st.insert(a[i].second);
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
