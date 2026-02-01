#include <bits/stdc++.h>

using namespace std;

#define ll long long
const ll INF = 10000000000000LL;

vector<vector<ll>> p(300001, vector<ll>());

void solve() {
  ll n;
  cin >> n;
  vector<ll> a(n);
  for (auto &c : a)
    cin >> c;

  vector<ll> f(n + 1, 0);
  vector<ll> op(n + 1, INF);
  for (int i = 0; i < n; i++) {
    op[a[i]] = 1;
    f[a[i]]++;
  }
  op[1] = 0;
  for (int i = 1; i <= n; i++) {
    int x = i;
    if (x == 1) {
      if (f[x]) {
        cout << 1 << " ";
      } else {
        cout << -1 << " ";
      }
      continue;
    }
    ll ans = INF;
    if (f[x]) {
      ans = 1;
    }
    for (auto c : p[x]) {
      if (f[c]) {

        ans = min(ans, 1LL + op[x / c]);
      }
    }
    if (ans == INF)
      cout << -1 << " ";
    else {
      op[x] = ans;
      cout << ans << " ";
    }
  }
  cout << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  for (int i = 2; i <= 300000; i++) {
    for (int j = i; j <= 300000; j += i) {
      p[j].push_back(i);
    }
  }
  int T;
  cin >> T;
  while (T--)
    solve();
}
