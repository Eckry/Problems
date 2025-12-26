#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve() {
  ll n, k;
  cin >> n >> k;
  if (k & 1) {
    for (int i = 0; i < k; i++) {
      cout << n << " ";
    }
    cout << "\n";
  } else {

    vector<ll> a(k, 0);
    vector<ll> b;
    ll l = k - 1;
    ll bit = 31 - __builtin_clz(n);
    for (int i = bit; i >= 0; i--) {
      if (n & (1 << i)) {
        if (l >= 0) {
          b.push_back(a[l]);
          l--;
        }
        for (int j = 0; j < (int)b.size() - 1; j++) {
          b[j] |= (1 << i);
        }
        for (int j = 0; j <= l; j++) {
          a[j] |= (1 << i);
        }
      } else {
        for (int j = 0; j < b.size() / 2 * 2; j++) {
          b[j] |= (1 << i);
        }
      }
    }
    for (int i = 0; i <= l; i++) {
      cout << a[i] << " ";
    }
    for (int i = 0; i < b.size(); i++) {
      cout << b[i] << " ";
    }
    cout << "\n";
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
