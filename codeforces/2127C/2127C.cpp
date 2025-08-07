#include <algorithm>
#include <bits/stdc++.h>
#include <functional>

using namespace std;

#define ll long long

#define optimize()                                                             \
  cin.tie(0);                                                                  \
  cin.sync_with_stdio(0);                                                      \
  ios_base::sync_with_stdio(0);                                                \
  cout.tie(0);

void solve() {
  ll n, k;
  cin >> n >> k;
  vector<ll> a(n);
  vector<ll> b(n);
  for (auto &c : a)
    cin >> c;
  for (auto &c : b)
    cin >> c;
  for (int i = 0; i < n; i++) {
    if (b[i] < a[i]) {
      ll temp = a[i];
      a[i] = b[i];
      b[i] = temp;
    }
  }
  vector<int> idx(n);
  iota(idx.begin(), idx.end(), 0);
  sort(idx.begin(), idx.end(), [&](int x, int y) { return a[x] < a[y]; });
  ll inc = __LONG_LONG_MAX__;
  for (int m = 0; m < n - 1; m++) {
    int i = idx[m];
    int j = idx[m + 1];
    if (b[i] > a[j]) {
      inc = 0;
      break;
    }
    ll initial = abs(a[i] - b[i]) + abs(a[j] - b[j]);
    ll newinitial = abs(a[i] - b[j]) + abs(a[j] - b[i]);
    inc = min(inc, abs(initial - newinitial));
  }
  ll score = 0;
  for (int i = 0; i < n; i++) {
    score += abs(a[i] - b[i]);
  }
  cout << score + inc << "\n";
}

int main() {
  int T;
  cin >> T;
  while (T--)
    solve();
}
