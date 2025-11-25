#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve() {
  int n, w;
  cin >> n >> w;
  int len = (1 << n);
  vector<int> a(len);
  int cnt = w;
  for (int i = 0; i < len; i++) {
    a[i] = cnt;
    cnt = (cnt) % (len);
    cnt++;
  }
  int len2 = (1 << (n + 1));
  vector<int> sg(len2, 0);
  for (int i = len; i < (len2); i++) {
    sg[i] = a[i - len];
  }
  for (int i = len - 1; i >= 1; i--) {
    if (sg[i << 1 | 1] == w) {
      sg[i] = sg[i << 1 | 1];
    } else if (sg[i << 1] == w) {
      sg[i] = sg[i << 1];
    } else {
      sg[i] = min(sg[i << 1 | 1], sg[i << 1]);
    }
  }
  for (int i = 1; i < len2; i++) {
    cout << sg[i] << " ";
  }
  cout << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--)
    solve();
}
