#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve() {
  int n;
  cin >> n;
  vector<int> a(2 * n);
  for (auto &c : a)
    cin >> c;

  map<int, int> mp;
  for (int i = 0; i < 2 * n; i++) {
    mp[a[i]]++;
  }
  int one = 0;
  int two = 0;
  int three = 0;
  for (auto [key, value] : mp) {
    if (value & 1) {
      one++;
    } else {
      if ((value / 2) & 1) {
        two++;
      } else {
        three++;
      }
    }
  }
  if (one || three % 2 == 0) {
    cout << one + 2 * two + 2 * three << "\n";
  } else {
    cout << one + 2 * two + 2 * three - 2 << "\n";
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
