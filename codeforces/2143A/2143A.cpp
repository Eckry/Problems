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
  vector<int> p(n);
  for (auto &c : p)
    cin >> c;

  int i = 0;
  while (p[i] != n)
    i++;

  int j = i + 1;
  i--;
  int now = n - 1;
  // cout << i << " " << now << "\n";
  while (now > 0) {
    if (i >= 0 && p[i] == now) {
      i--;
      now--;
    } else if (j < n && p[j] == now) {
      j++;
      now--;
    } else {
      // cout << i << " " << j << "\n";
      cout << "NO" << "\n";
      return;
    }
  }
  cout << "YES" << "\n";
}

int main() {
  optimize();
  int T;
  cin >> T;
  while (T--)
    solve();
}
