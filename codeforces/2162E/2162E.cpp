#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (auto &c : a)
    cin >> c;

  map<int, int> mp;
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    if (!mp.count(a[i])) {
      cnt++;
    }
    mp[a[i]] = 1;
  }
  if (cnt == n) {
    for (int i = 0; i < k; i++) {
      cout << a[i] << " ";
    }
    cout << "\n";
    return;
  }

  int x = -1;
  int y = -1;
  if (cnt < n - 1) {
    int cnt2 = 0;
    for (int i = 1; i <= n; i++) {
      if (!mp.count(i)) {
        cout << i << " ";
        if (x == -1)
          x = i;
        y = i;
        k--;
        cnt2++;
        if (cnt2 == 2)
          break;
      }
      if (!k) {
        cout << "\n";
        return;
      }
    }
    if (!k) {
      cout << "\n";
      return;
    }

    for (int i = 1; i <= n; i++) {
      if (x != i && y != i) {
        k--;
        cout << i << " ";
      }
      if (!k) {
        cout << "\n";
        return;
      }
    }
    cout << "\n";
    return;
  }

  x = 0;
  for (int i = 1; i <= n; i++) {
    if (!mp.count(i)) {
      k--;
      cout << i << " ";
      x = i;
      if (!k) {
        cout << "\n";
        return;
      }
      break;
    }
  }
  if (!k) {
    cout << "\n";
    return;
  }

  vector<int> numbers;
  numbers.push_back(x);
  if (a[n - 1] != a[n - 2]) {
    numbers.push_back(a[n - 2]);
    numbers.push_back(a[n - 1]);
  } else {
    numbers.push_back(a[n - 3]);
    numbers.push_back(a[n - 1]);
  }
  for (int i = 0; i < k; i++) {
    cout << numbers[(i + 1) % 3] << " ";
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
