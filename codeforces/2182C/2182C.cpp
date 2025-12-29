#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  vector<int> b(n);
  vector<int> c(n);
  for (auto &it : a)
    cin >> it;
  for (auto &it : b)
    cin >> it;
  for (auto &it : c)
    cin >> it;

  set<int> st;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (a[i] >= b[j]) {
        st.insert((j - i + n) % n);
      }
    }
  }
  // for (auto c : st) {
  //   cout << c << " ";
  // }
  // cout << "\n";
  set<int> st2;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (b[i] >= c[j]) {
        st2.insert((j - i + n) % n);
      }
    }
  }
  // for (auto c : st2) {
  //   cout << c << " ";
  // }
  // cout << "\n";
  cout << 1LL * (n - st2.size()) * (n - st.size()) * n << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--)
    solve();
}
