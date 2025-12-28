#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve() {
  ll n, h;
  cin >> n >> h;
  vector<ll> a(n);
  for (auto &c : a)
    cin >> c;

  sort(a.begin(), a.end());
  int cnt = 0;
  // int two = 0;
  // int tree = 0;
  int ans = 0;
  ll ori = h;
  vector<int> op = {2, 2, 3};
  int j = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] < h) {
      h += a[i] / 2;
    } else {
      while (j < 3 && a[i] >= h * op[j]) {
        h *= op[j];
        j++;
      }
      if (j == 3)
        break;
      h *= op[j];
      h += a[i] / 2;
      j++;
    }
    cnt++;
  }
  ans = max(cnt, ans);
  op = {2, 3, 2};
  j = 0;
  h = ori;
  cnt = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] < h) {
      h += a[i] / 2;
    } else {
      while (j < 3 && a[i] >= h * op[j]) {
        h *= op[j];
        j++;
      }
      if (j == 3)
        break;
      h *= op[j];
      h += a[i] / 2;
      j++;
    }

    cnt++;
  }
  ans = max(cnt, ans);
  op = {3, 2, 2};
  j = 0;
  h = ori;
  cnt = 0;
  for (int i = 0; i < n; i++) {
    // cout << i << " " << h << "\n";
    if (a[i] < h) {
      h += a[i] / 2;
    } else {
      while (j < 3 && a[i] >= h * op[j]) {
        h *= op[j];
        j++;
      }
      if (j == 3)
        break;
      h *= op[j];
      h += a[i] / 2;
      j++;
    }

    cnt++;
  }
  // cout << cnt << "\n";
  ans = max(cnt, ans);
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
