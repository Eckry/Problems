#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve() {
  int n, x, k;
  cin >> n >> x >> k;
  int op1 = k - x % k;
  if (x + op1 > n)
    op1 = 100000;
  int op2 = x % k;
  // cout << op1 << " " << op2 << "\n";
  cout << min(op1, op2) << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--)
    solve();
}
