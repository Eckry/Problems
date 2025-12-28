#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &c : a)
    cin >> c;

  vector<int> freq(n + 1, 0);
  sort(a.begin(), a.end());
  for (auto c : a) {
    freq[c]++;
  }
  int best = n - 1;
  int x = a[0];
  for (int i = 0; i < n; i++) {
    if (best >= a[i]) {
      best = n - i - 1;
      x = a[i];
    }
  }
  if (x > best) {
    cout << -1 << "\n";
  } else
    cout << best << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--)
    solve();
}
