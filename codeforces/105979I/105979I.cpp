#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve() {
  ll x, k;
  cin >> x >> k;

  ll first = x;
  ll second = x;
  if (k <= x) {
    cout << 1 << "\n";
    return;
  }

  int lastvalue = first;
  int cnt = 1;
  while (true) {
    cnt++;
    lastvalue = first + second;
    if (lastvalue >= k) {
      cout << cnt << "\n";
      return;
    }
    first = second;
    second = lastvalue;
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
