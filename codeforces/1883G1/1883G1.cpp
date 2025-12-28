#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve() {
  ll n, m;
  cin >> n >> m;
  vector<ll> a(n);
  a[0] = 1;
  vector<ll> b(n);
  for (int i = 1; i < n; i++) {
    cin >> a[i];
  }
  for (auto &c : b)
    cin >> c;

  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  queue<ll> q;
  for (int i = 0; i < n; i++) {
    if (q.size() && q.front() < b[i]) {
      // cout << "Inserting " << q.front() << "\n";
      q.push(a[i]);
      // a[i] = q.front();
      q.pop();
    } else if (a[i] >= b[i]) {
      q.push(a[i]);
      // cout << "Error: " << a[i] << "\n";
      // a[i] = 0;
    }
  }
  // for (auto c : a) {
  //   cout << c << " ";
  // }
  // cout << "\n";
  // for (auto c : b) {
  //   cout << c << " ";
  // }
  // cout << "\n";
  cout << q.size() << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--)
    solve();
}
