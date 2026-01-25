#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve() {
  int n;
  cin >> n;

  vector<int> a(n);
  vector<int> used(n + 1, 0);
  a[n - 1] = 1;
  for (int i = 1; i < n - 1; i++) {
    used[1 ^ (i + 1)] = 1;
    a[i] = (1 ^ (i + 1));
    // cout << (1 ^ (i + 1)) << "\n";
  }
  used[1] = 1;
  int x = 1;
  while (used[x])
    x++;
  a[0] = x;
  for (auto c : a) {
    cout << c << " ";
  }
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
