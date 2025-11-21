#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve() {
  int n, k, m;
  cin >> n >> k >> m;
  string s;
  cin >> s;
  set<char> st;

  string ans;
  for (int i = 0; i < m; i++) {
    if (st.find(s[i]) != st.end())
      continue;
    st.insert(s[i]);
    if (st.size() == k) {
      ans += s[i];
      st.clear();
    }
  }
  if (ans.size() >= n) {
    cout << "YES\n";
    return;
  }

  int i = 0;
  while (ans.size() < n) {
    char c = char(97 + i);
    if (st.find(c) != st.end()) {
      i++;
      continue;
    }
    ans += c;
  }
  cout << "NO\n";
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--)
    solve();
}
