#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &c : a)
    cin >> c;

  int two = 0;
  int three = 0;
  int one = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] == 1)
      one++;
    if (a[i] == 2)
      two++;
    if (a[i] == 3)
      three++;
  }
  cout << max(0, min(one, three) + max(two - 1, 0)) << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--)
    solve();
}
