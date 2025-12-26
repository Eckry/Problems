#include <bits/stdc++.h>

using namespace std;

#define ll long long

void check(ll n) {
  while (n) {
    cout << (n % 2) << "";
    n >>= 1;
  }
  cout << "\n";
}

void solve() {
  ll n, k;
  cin >> n >> k;

  if (k & 1) {
    for (int i = 0; i < k; i++) {
      cout << n << " ";
    }
    cout << "\n";
    return;
  } else {
    ll as = 0;
    for (ll i = 0; i < k - 2; i++) {
      as ^= n;
      cout << n << " ";
    }
    ll bits = 31 - __builtin_clz(n);
    ll xors = 0;
    ll cnt = 0;
    for (ll i = bits - 1; i >= 0; i--) {
      if ((1LL << i) & n) {
        cnt++;
      }
      if (cnt >= 1)
        xors |= (1LL << i);
    }
    ll temp = n;
    n ^= xors;
    as ^= n;
    as ^= xors;
    cout << xors << " ";
    cout << n << "\n";
    check(temp);
    check(n);
    check(xors);
    if (as == temp) {
      cout << "FINE\n";
    }
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
