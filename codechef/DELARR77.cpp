#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  vector<int> c(n);
  for (auto &d : a)
    cin >> d;
  for (auto &d : c)
    cin >> d;

  int mn = 1000000000;
  int idx = 0;
  int end = n - 1;
  int ans = 0;
  vector<int> suf(n + 1, 0);
  for (int i = n - 1; i >= 0; i--) {
    suf[i] = suf[i + 1] + a[i];
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= end; j++) {
      // cout << i << "\n";
      if (mn > c[j]) {
        mn = c[j];
        idx = j;
      }
    }
    int op = (suf[idx] - suf[end + 1]) * c[idx];
    // cout << op << " " << idx << "\n";
    ans += op;
    end = idx - 1;
    mn = 1000000000;

    if (end < 0)
      break;
  }
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
