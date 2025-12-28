#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &c : a) {
    cin >> c;
  }

  sort(a.begin(), a.end());
  ll sm = 0;
  int cnt = 1;
  for (int i = 0; i < n; i++) {
    if (a[i] < cnt)
      continue;
    sm += max(0, a[i] - cnt);
    cnt++;
  }
  // cout << best << "\n";
  cout << sm << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--)
    solve();
}
