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
  for (auto &c : b)
    cin >> c;

  int alice = 0;
  int bob = 0;
  for (auto c : a)
    alice ^= c;
  for (auto c : b)
    bob ^= c;

  for (int i = 0; i < n; i++) {
    if (alice == bob)
      continue;
    if (a[i] == b[i])
      continue;
    if (i & 1) {
      if (bob > alice)
        continue;
      if (a[i] != b[i]) {
        alice = 0;
        bob = 1;
      }
    } else {
      if (alice > bob)
        continue;
      if (a[i] != b[i]) {
        alice = 1;
        bob = 0;
      }
    }
  }
  if (alice == bob) {
    cout << "Tie\n";
  } else if (alice > bob) {
    cout << "Ajisai\n";
  } else {
    cout << "Mai\n";
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
