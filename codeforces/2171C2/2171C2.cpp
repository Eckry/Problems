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
  for (int i = 0; i < n; i++) {
    alice ^= a[i];
  }
  for (int i = 0; i < n; i++) {
    bob ^= b[i];
  }
  for (int i = 0; i < n; i++) {
    if (i & 1) {
      int sim = (alice ^ a[i]) ^ b[i];
      int sim2 = (bob ^ b[i]) ^ a[i];
      if (sim2 > sim) {
        alice = sim;
        bob = sim2;
      }
    } else {
      int sim = (alice ^ a[i]) ^ b[i];
      int sim2 = (bob ^ b[i]) ^ a[i];
      if (sim > sim2) {
        alice = sim;
        bob = sim2;
      }
    }
  }

  if (alice == bob) {
    cout << "Tie\n";
  } else if (alice > bob) {
    cout << "Ajisai\n";
  } else
    cout << "Mai\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--)
    solve();
}
