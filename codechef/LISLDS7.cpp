#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve() {
  int n;
  cin >> n;
  vector<int> f(n);
  for (auto &c : f)
    cin >> c;
  int twos = 0;
  int ones = 0;
  for (int i = 0; i < n; i++) {
    if (f[i] >= 2)
      twos += 1;
    if (f[i] < 2)
      ones += 1;
  }
  cout << twos + ((ones + 1) / 2) << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--)
    solve();
}
