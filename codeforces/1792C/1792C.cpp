#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    a[i]--;
  }

  vector<int> pos(n);
  for (int i = 0; i < n; i++) {
    pos[a[i]] = i;
  }
  int ans = n / 2;
  for (int i = (n + 1) / 2; i < n; i++) {
    int x = i;
    int y = n - 1 - x;
    if (pos[x] < pos[y] || pos[x] < pos[x - 1] || pos[y] > pos[y + 1]) {
      cout << ans << "\n";
      return;
    }
    ans--;
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
