#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  iota(a.begin(), a.end(), 1);
  sort(a.begin(), a.end(), [&](int x, int y) {
    if (__gcd(x, n) != __gcd(y, n)) {
      return __gcd(x, n) > __gcd(y, n);
    } else {
      return x < y;
    }
  });
  for (auto c : a)
    cout << c << " ";
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
