#include <bits/stdc++.h>

using namespace std;

#define ll long long

#define optimize()                                                             \
  cin.tie(0);                                                                  \
  cin.sync_with_stdio(0);                                                      \
  ios_base::sync_with_stdio(0);                                                \
  cout.tie(0);

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &c : a)
    cin >> c;
  int zeros = 0;
  int ones = 0;
  for (auto c : a) {
    if (c == 0)
      zeros++;
    if (c == -1)
      ones++;
  }

  cout << zeros + (ones & 1) * 2 << "\n";
}

int main() {
  optimize() int T;
  cin >> T;
  while (T--)
    solve();
}
