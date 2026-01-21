#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &c : a)
    cin >> c;

  int i = n - 1;
  while (i >= 0 && a[i] == i + 1) {
    i--;
  }
  if (i == -1)
    cout << 0 << "\n";
  else
    cout << a[i] << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--)
    solve();
}
