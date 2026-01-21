#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;

  int is = 1;
  for (int i = 0; i < n - 1; i++) {
    if (s[i] > s[i + 1]) {
      is = 0;
      break;
    }
  }
  if (is) {
    cout << "Bob\n";
    return;
  }

  vector<int> ones(n, 0);
  vector<int> zeros(n, 0);
  if (s[0] == '1')
    ones[0]++;
  if (s[n - 1] == '0')
    zeros[n - 1]++;
  for (int i = 1; i < n; i++) {
    ones[i] = ones[i - 1];
    if (s[i] == '1') {
      ones[i]++;
    }
  }
  for (int i = n - 2; i >= 0; i--) {
    zeros[i] = zeros[i + 1];
    if (s[i] == '0') {
      zeros[i]++;
    }
  }
  // for (auto c : ones) {
  //   cout << c << " ";
  // }
  // cout << "\n";
  // for (auto c : zeros) {
  //   cout << c << " ";
  // }
  // cout << "\n";
  int ok = 0;
  int idx = 0;
  for (int i = 0; i < n - 1; i++) {
    if (ones[i] == zeros[i + 1]) {
      ok = 1;
      idx = i;
      break;
    }
  }
  if (!ok) {
    cout << "Bob\n";
  } else {
    cout << "Alice\n";
    // cout << idx << "\n";
    cout << ones[idx] + zeros[idx + 1] << "\n";
    for (int i = 0; i <= idx; i++) {
      if (s[i] == '1') {
        cout << i + 1 << " ";
      }
    }
    for (int i = idx + 1; i < n; i++) {
      if (s[i] == '0') {
        cout << i + 1 << " ";
      }
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
