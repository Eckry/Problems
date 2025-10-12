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
  vector<int> a(n);
  for (auto &c : a)
    cin >> c;

  if (n == 1) {
    if (a[0] == 1) {
      cout << 2 << "\n";
      return;
    }
    cout << 0 << "\n";
    return;
  }

  for (int i = 0; i < n; i++)
    a[i]--;

  int flg = 0;
  for (int i = 0; i < n - 1; i++) {
    if (a[i] != a[i + 1])
      flg = 1;
    if (abs(a[i] - a[i + 1]) >= 2) {
      cout << 0 << "\n";
      return;
    }
  }

  if (!flg) {
    int x = a[0] + 1;
    int pairs = x - 1;
    if (pairs * 2 == n) {
      cout << 1 << "\n";
      return;
    }

    if (pairs * 2 + 1 == n) {
      cout << 2 << "\n";
      return;
    }

    if (pairs * 2 + 2 == n) {
      cout << 1 << "\n";
      return;
    }

    cout << 0 << "\n";

    return;
  }

  vector<char> ans(n, 'x');
  for (int i = 0; i < n - 1; i++) {
    if (a[i] == a[i + 1] + 1) {
      ans[i] = 'L';
      ans[i + 1] = 'L';
    }
    if (a[i] + 1 == a[i + 1]) {
      ans[i] = 'R';
      ans[i + 1] = 'R';
    }
  }

  for (int i = 0; i < n - 1; i++) {
    if (a[i] == a[i + 1]) {
      if (ans[i] == 'R')
        ans[i + 1] = 'L';
      if (ans[i] == 'L')
        ans[i + 1] = 'R';
      if (ans[i + 1] == 'R')
        ans[i] = 'L';
      if (ans[i + 1] == 'L')
        ans[i] = 'R';
    }
  }

  for (int i = n - 2; i >= 0; i--) {
    if (a[i] == a[i + 1]) {
      if (ans[i] == 'R')
        ans[i + 1] = 'L';
      if (ans[i] == 'L')
        ans[i + 1] = 'R';
      if (ans[i + 1] == 'R')
        ans[i] = 'L';
      if (ans[i + 1] == 'L')
        ans[i] = 'R';
    }
  }

  vector<int> suffR(n + 1, 0);
  vector<int> suffL(n + 1, 0);
  vector<int> preffR(n + 1, 0);
  vector<int> preffL(n + 1, 0);
  for (int i = 1; i <= n; i++) {
    preffR[i] = preffR[i - 1];
    preffL[i] = preffL[i - 1];
    if (ans[i - 1] == 'R')
      preffR[i]++;
    if (ans[i - 1] == 'L')
      preffL[i]++;
  }
  // for (auto c : ans)
  //   cout << c << " ";
  // cout << "\n";
  // for(auto c : preffR) cout << c << " ";
  // cout << "\n";
  //
  // for(auto c : preffL) cout << c << " ";
  // cout << "\n";

  for (int i = 0; i < n; i++) {
    // cout << preffR[i] << " " << preffL[n] - preffL[i + 1] << " as\n";
    // cout << a[i] << "\n";
    if (a[i] == preffR[i] + (preffL[n] - preffL[i + 1]))
      continue;
    cout << 0 << "\n";
    return;
  }
  cout << 1 << "\n";
}

int main() {
  optimize();
  int T;
  cin >> T;
  while (T--)
    solve();
}
