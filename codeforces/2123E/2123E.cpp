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
  ll amor = 0;
  int mex = 0;
  for (int i = 0; i < n; i++) {
    freq[a[i]]++;
  }
  vector<int> g(n + 1, 0);
  while (freq[mex])
    mex++;
  for (int i = 0; i < n + 1; i++) {
    if (mex < i) {
      amor += freq[i];
    } else
      amor += max(0, freq[i] - 1);
    if (freq[i] != 0 && mex > i)
      g[freq[i]]++;
  }

  int k = 0;

  ll pref = g[0];
  int i = 0;
  while (i < n) {
    cout << min(pref + 1, pref + 1 + amor - k) << " ";
    i++;
    k++;
    pref += g[i];
  }
  cout << 1 << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--)
    solve();
}
