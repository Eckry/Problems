#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &c : a)
    cin >> c;

  sort(a.begin(), a.end(), greater<>());
  if (n == 1) {
    cout << a[0] << "\n";
    return;
  }
  cout << a[0] << " " << a[n - 1] << " ";
  for (int i = 1; i < n - 1; i++) {
    cout << a[i] << " ";
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
