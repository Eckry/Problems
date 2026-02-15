#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve() {
  int n;
  cin >> n;
  vector<int> a(n + 1);
  vector<int> ok(n + 1, 0);
  for (int i = 0; i < n; i++) {
    cin >> a[i + 1];
  }

  for (int i = 1; i <= n; i++) {
    if (ok[i])
      continue;
    set<int> st;
    for (int j = i; j <= n; j *= 2) {
      st.insert(j);
      ok[j] = 1;
    }

    for (int j = i; j <= n; j *= 2) {
      st.erase(a[j]);
    }
    if (st.size() != 0) {
      cout << "NO\n";
      return;
    }
  }
  cout << "YES\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--)
    solve();
}
