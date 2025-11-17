#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve() {
  int n, a;
  cin >> n >> a;
  vector<int> v(n);
  for (auto &c : v)
    cin >> c;

  int grea = 0;
  int less = 0;
  for (int i = 0; i < n; i++) {
    if (v[i] < a) {
      less++;
    } else if (v[i] > a) {
      grea++;
    }
  }
  if (grea >= less) {
    cout << a + 1 << "\n";
  } else {
    cout << a - 1 << "\n";
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
