#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  vector<int> b(n);
  for (auto &c : a)
    cin >> c;
  for (int i = 0; i < n; i++) {
    if (i & 1) {
      b[i] = 1;
    } else {
      b[i] = 0;
    }
  }
  vector<int> idx(n);
  iota(idx.begin(), idx.end(), 0);
  sort(idx.begin(), idx.end(), [&](int x, int y) { return a[x] < a[y]; });
  for (int i = 0; i < n - 1; i++) {
    int left = idx[i];
    int right = idx[i + 1];
    if (b[left] == b[right]) {
      cout << "NO\n";
      return;
    }
  }
  cout << "YES\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--)
    solve();
}
