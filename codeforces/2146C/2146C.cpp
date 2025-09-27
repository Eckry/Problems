#include <bits/stdc++.h>

using namespace std;

#define ll long long

#define optimize()                                                             \
  cin.tie(0);                                                                  \
  cin.sync_with_stdio(0);                                                      \
  ios_base::sync_with_stdio(0);                                                \
  cout.tie(0);

void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  int zeros = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == '1') {
      if (zeros == 1) {
        cout << "NO" << "\n";
        return;
      }
      zeros = 0;
    }
    if (s[i] == '0')
      zeros++;
  }

  if (zeros == 1) {
    cout << "NO" << "\n";
    return;
  }
  zeros = 0;
  vector<int> ans(n, 0);
  for (int i = 0; i < n; i++) {
    if (s[i] == '1') {
      if (zeros) {
        int cnt = i - zeros + 1;
        for (int j = i - zeros; j < i - 1; j++) {
          ans[j] = cnt + 1;
          cnt++;
        }
        ans[i - 1] = i - zeros + 1;
        zeros = 0;
      }
        ans[i] = i + 1;
    }
    if (s[i] == '0')
      zeros++;
  }
  if (zeros) {
    int cnt = n - zeros + 1;
    for (int j = n - zeros; j < n - 1; j++) {
      ans[j] = cnt + 1;
      cnt++;
    }
    ans[n - 1] = n - zeros + 1;
    zeros = 0;
  }
  cout << "YES" << "\n";
  for (auto c : ans)
    cout << c << " ";
  cout << "\n";
}

int main() {
  optimize();
  int T;
  cin >> T;
  while (T--)
    solve();
}
