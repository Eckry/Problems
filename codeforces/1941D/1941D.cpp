#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve() {
  int n, m, x;
  cin >> n >> m >> x;
  set<int> st;
  x--;
  st.insert(x);

  while (m--) {
    int r;
    char c;
    cin >> r >> c;
    set<int> i;
    if (c == '0') {
      for (auto c : st) {
        i.insert((c + r) % n);
      }
    } else if (c == '1') {
      for (auto c : st) {
        i.insert((c - r + n) % n);
      }
    } else {
      for (auto c : st) {
        i.insert((c + r) % n);
        i.insert((c - r + n) % n);
      }
    }
    st = i;
  }
  cout << st.size() << "\n";
  for (auto c : st) {
    cout << c + 1 << " ";
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
