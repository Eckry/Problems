#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (auto &c : a)
    cin >> c;

  vector<int> mx(n + 1, 0);
  for (auto c : a)
    mx[c]++;
  int mex = 0;
  while (mex < n + 1 && mx[mex]) {
    mex++;
  }
  cout << min(k - 1, mex) << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--)
    solve();
}
