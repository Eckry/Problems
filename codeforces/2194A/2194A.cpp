#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve() {
  int n, w;
  cin >> n >> w;
  cout << n - n / w << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--)
    solve();
}
