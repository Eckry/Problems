#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &c : a)
    cin >> c;

  sort(a.begin(), a.end());
  int cnt = 0;
  int sm = 0;
  for (int i = 0; i < n; i++) {
    if (a[i]) {
      sm += a[i];
      cnt++;
    }
  }

  int turns = n;
  int i = 0;
  int ans = 0;
  while (i < n && !a[i])
    i++;
  while (i < n && sm - cnt < turns - 1) {
    turns--;
    sm--;
    a[i]--;
    if (!a[i]) {
      cnt--;
      i++;
    }
  }
  if (sm - cnt >= turns - 1) {
    ans = cnt;
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
