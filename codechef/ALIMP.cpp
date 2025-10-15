#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve() {
  int n;
  cin >> n;

  vector<int> a(n + 1, 0);
  int p = n - 1;
  int start = n;
  int i = 1;
  while (p--) {
    if (i & 1) {
      start = start - n + i;
      i++;
    } else {
      start = start + n - i;
      i++;
    }
  }
  cout << start << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--)
    solve();
}
