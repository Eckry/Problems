#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &c : a)
    cin >> c;

  int even = 0;
  int odd = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] & 1)
      odd++;
    else
      even++;
  }

  if (odd && even) {
    sort(a.begin(), a.end());
    for (auto c : a)
      cout << c << " ";
    cout << "\n";
    return;
  }

  for (auto c : a)
    cout << c << " ";
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
