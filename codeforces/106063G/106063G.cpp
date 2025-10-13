#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve() {
  ll h1, h2, b;
  cin >> h1 >> h2 >> b;

  long double term1 = logl(h2) - logl(h1);
  long double term2 = logl(b - 1) - logl(b);
  cout << (ll)ceil(term1 / term2) << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--)
    solve();
  return 0;
}
