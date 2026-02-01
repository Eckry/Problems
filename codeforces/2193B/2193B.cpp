#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &c : a)
    cin >> c;

  int p = n;
  int start = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] == p) {
      p--;
      start++;
      continue;
    }
    break;
  }
  if (p == 0) {
    for (auto c : a) {
      cout << c << " ";
    }
    cout << "\n";
    return;
  }
  int j = 0;
  for (int i = 0; i < n; i++) {
    if (p == a[i]) {
      j = i;
      break;
    }
  }
  // cout << j << " " << start << "\n";

  for (int i = start; i <= (j + start) / 2; i++) {
    swap(a[i], a[j - i + start]);
  }
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
