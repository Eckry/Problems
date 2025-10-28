#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve() {
  string s;
  cin >> s;
  int n;
  cin >> n;
  int m = s.size();
  while (n--) {
    string t;
    cin >> t;
    if (t.size() < s.size()) {
      cout << "No" << "\n";
      continue;
    }
    int flg = 0;
    for (int i = 0; i < t.size(); i++) {
      if (s[i % m] != t[i]) {
        flg = 1;
        break;
      }
    }
    if (flg || t.size() % m) {
      cout << "No" << "\n";
      continue;
    }
    cout << "Yes" << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  int T;
  T = 1;
  while (T--)
    solve();
}
