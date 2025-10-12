#include <bits/stdc++.h>

using namespace std;

#define ll long long

#define optimize()                \
    cin.tie(0);                   \
    cin.sync_with_stdio(0);       \
    ios_base::sync_with_stdio(0); \
    cout.tie(0);

void solve() {
  int n; cin >> n;
  vector<ll> a(n);
  for(auto &c : a) cin >> c;
  sort(a.begin(), a.end());

  ll mx = 0;
  for(int i =1;i<n; i+=2) {
    mx = max(mx, a[i] - a[i - 1]);
  }
  cout << mx << "\n";
}

int main() {
  optimize()
  int T;
  cin >> T;
  while(T--) solve();
}
