#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve() {
  int n;
  cin >> n;
  vector<ll> a(n);
  for (auto &c : a)
    cin >> c;

  map<int, vector<int>> mp;
  for (int i = 0; i < n; i++) {
    mp[a[i]].push_back(i);
  }
  vector<int> pointleft(n);
  vector<int> pointright(n);
  for (int i = 0; i < n; i++) {
    pointright[i] = (i + 1) % n;
    pointleft[i] = (i - 1 + n) % n;
  }
  ll ans = 0;
  vector<int> checked(n, 0);
  for (auto [val, idx] : mp) {
    // cout << "Checking: " << val << "\n";
    for (auto i : idx) {
      if (checked[i])
        continue;
      int right = pointright[i];
      // cout << "i " << i << "\n";
      // cout << "Right\n";
      while (right != i && a[right] <= val) {
        ans += val;
        pointright[i] = pointright[right];
        // cout << "right: " << right << "\n";
        checked[right] = 1;
        right = pointright[right];
        pointleft[right] = i;
        // cout << "Pointers updated: \n";
        // for (auto xd : pointright) {
        //   cout << xd << " ";
        // }
        // cout << "\n";
        // for (auto xd : pointleft) {
        //   cout << xd << " ";
        // }
        // cout << "Current ans: " << ans << "\n";
      }
      int left = pointleft[i];
      // cout << "Left\n";
      while (left != i && a[left] <= val) {
        ans += val;
        pointleft[i] = pointleft[left];
        checked[left] = 1;
        left = pointleft[left];
        pointright[left] = i;

        // cout << "Pointers updated: \n";
        // for (auto xd : pointleft) {
        //   cout << xd << " ";
        // }
        // cout << "Current ans: " << ans << "\n";
      }
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
