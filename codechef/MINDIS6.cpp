#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (auto &c : a)
    cin >> c;

  vector<int> freq(n + 1, 0);
  int ans = 1;
  for (int i = 0; i < n; i++) {
    if (a[i] == a[0])
      continue;

    if (freq[a[i]] == 0)
      ans++;
    freq[a[i]]++;
  }
  // cout << ans << "\n";
  // for (int i = 0; i <= n; i++) {
  //   cout << freq[i] << " ";
  // }
  // cout << "\n";
  sort(freq.begin(), freq.end());
  for (int i = 0; i <= n; i++) {
    if (freq[i] && k >= freq[i]) {
      k -= freq[i];
      ans--;
    }
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
