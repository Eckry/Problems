#include <bits/stdc++.h>

using namespace std;

#define ll long long

int check(string &s, int m) {
  int n = s.size();
  int j = 0;
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] != s[j])
      cnt++;
    if (cnt >= 2)
      break;
    j = (j + 1) % m;
  }
  if (cnt <= 1)
    return 1;

  cnt = 0;
  j = n - m;

  for (int i = 0; i < n; i++) {
    // cout << s[n - j] << " ";
    if (s[i] != s[j])
      cnt++;
    if (cnt >= 2)
      return 0;
    j = (j + 1);
    if (j >= n)
      j = n - m;
  }
  // cout << "\n";
  return 1;
}

void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;

  vector<int> div;
  for (int i = 1; i * i <= n; i++) {
    if (n % i == 0) {
      div.push_back(i);
      div.push_back(n / i);
    }
  }
  sort(div.begin(), div.end());
  // for (auto d : div) {
  //   cout << d << " ";
  // }
  // cout << "\n";
  for (auto d : div) {
    // cout << d << " ";
    if (check(s, d)) {
      cout << d << "\n";
      return;
    }
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
