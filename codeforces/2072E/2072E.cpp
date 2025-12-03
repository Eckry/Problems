#include <bits/stdc++.h>

using namespace std;

#define ll long long

vector<pair<ll, ll>> generate(ll x, ll y, ll k) {
  ll n = 0;
  vector<pair<ll, ll>> ans;
  while ((n + 1) * (n) <= 2 * k) {
    n++;
    ans.push_back({x + n, y});
  }
  return ans;
}

void solve() {
  ll k;
  cin >> k;
  vector<pair<ll, ll>> ans;
  ll x = 0;
  ll y = 0;
  while (k > 0) {
    vector<pair<ll, ll>> gen = generate(x, y, k);
    for (auto lol : gen)
      ans.push_back(lol);
    ll n = gen.size();
    k -= n * (n - 1) / 2;
    x += n + 1;
    y++;
  }
  cout << ans.size() << "\n";
  for (auto [l, r] : ans) {
    cout << l << " " << r << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--)
    solve();
}
