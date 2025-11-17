#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

#define ll long long

int k, n;

void solve() {
  cin >> n >> k;
  vector<int> a(n), mp(n + 1, 0), p(n + 1, 0);
  for (auto &c : a)
    cin >> c;
  for (int i = 0; i < n; i++) {
    mp[a[i]]++;
  }

  for (int i = 1; i <= n; i++) {
    p[i] = p[i - 1] + mp[i];
  }

  for (int i = n; i >= 0; i--) {

    int good = n - p[min(4 * i - 1, n)];
    good += mp[i];
    if (i * 2 <= n)
      good += mp[i * 2];
    if (i * 3 <= n)
      good += mp[i * 3];
    if (n - good <= k) {
      cout << i << "\n";
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
