#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve() {
  ll a, b;
  cin >> a >> b;

  ll power = (1 << (32 - __builtin_clz(a)));
  if (power <= b) {
    cout << -1 << "\n";
    return;
  }
  vector<int> ans;
  for (int i = 0; i <= 32; i++) {
    if (b & (1 << i)) {
      if (a & (1 << i)) {
        continue;
      }
      ans.push_back(1 << i);
      a = a ^ (1 << i);
    }
  }
  for (int i = 32; i >= 0; i--) {
    if (!(b & (1 << i))) {
      if (a & (1 << i)) {
        a = a ^ (1 << i);
        ans.push_back(1 << i);
      }
    }
  }
  cout << ans.size() << "\n";

  for (auto c : ans)
    cout << c << " ";
  if (ans.size() != 0)
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
