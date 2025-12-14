#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve() {
  ll n;
  cin >> n;
  vector<ll> a(n);
  for (auto &c : a)
    cin >> c;
  vector<ll> b(n - 1);
  for (int i = 0; i < n - 1; i++) {
    b[i] = __gcd(a[i], a[i + 1]);
  }
  int idx = -1;
  for (int i = 0; i < n - 2; i++) {
    if (b[i] > b[i + 1]) {
      idx = i;
      break;
    }
  }
  if (idx == -1) {
    cout << "YES" << "\n";
    return;
  }
  // for (int i = 0; i < n - 1; i++) {
  //   cout << b[i] << " ";
  // }
  // cout << "\n";

  // cout << idx << "\n";
  vector<ll> op1 = a;
  vector<ll> op2 = a;
  vector<ll> op3 = a;
  op1.erase(op1.begin() + idx);
  if (idx < n - 1) {
    op2.erase(op2.begin() + idx + 1);
  }
  if (idx < n - 2) {
    op3.erase(op3.begin() + idx + 2);
  }
  // for (int i = 0; i < n - 1; i++) {
  //   cout << op3[i] << " ";
  // }
  // cout << "\n";
  ll prev = -1;
  int ok = 1;
  for (int i = 0; i < n - 2; i++) {
    ll g = __gcd(op1[i], op1[i + 1]);
    if (prev > g) {
      ok = 0;
      break;
    }
    prev = g;
  }
  if (ok) {
    cout << "YES" << "\n";
    return;
  }
  prev = -1;
  ok = 1;
  for (int i = 0; i < n - 2; i++) {
    ll g = __gcd(op2[i], op2[i + 1]);
    if (prev > g) {
      ok = 0;
      break;
    }
    prev = g;
  }
  if (ok) {
    cout << "YES" << "\n";
    return;
  }
  prev = -1;
  ok = 1;
  for (int i = 0; i < n - 2; i++) {
    ll g = __gcd(op3[i], op3[i + 1]);
    // cout << op3[i] << " ";
    if (prev > g) {
      ok = 0;
      break;
    }
    prev = g;
  }
  // cout << "\n";
  if (ok) {
    cout << "YES" << "\n";
    return;
  }
  cout << "NO\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--)
    solve();
}
