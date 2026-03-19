#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  int cnt = n;
  for (int i = n - 1; i >= 0; i -= 2) {
    a[i] = cnt;
    cnt--;
  }
  cnt = 1;
  for (int i = n - 2; i >= 0; i -= 2) {
    a[i] = cnt;
    cnt++;
  }
  for (auto c : a) {
    cout << c << " ";
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
