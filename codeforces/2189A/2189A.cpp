#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve() {
  int n, h, l;
  cin >> n >> h >> l;
  vector<int> a(n);
  for (auto &c : a)
    cin >> c;

  if (h > l)
    swap(h, l);

  sort(a.begin(), a.end(), greater<int>());
  int j = n - 1;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (i >= j)
      break;
    if (a[i] > l)
      continue;
    if (a[j] > h)
      break;
    ans++;
    j--;
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
