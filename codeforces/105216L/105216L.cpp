#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &c : a)
    cin >> c;
  vector<int> b(n);
  for (auto &c : b)
    cin >> c;
  for (int i = 0; i < n; i++) {
    a[i]--;
    b[i]--;
  }
  vector<int> visited(n, 0);
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    if (visited[a[i]])
      continue;
    ans++;
    int temp = a[i];
    while (!visited[temp]) {
      visited[temp] = 1;
      temp = a[temp];
    }
  }
  visited = vector<int>(n, 0);
  for (int i = 0; i < n; i++) {
    if (visited[b[i]])
      continue;
    ans++;
    int temp = b[i];
    while (!visited[temp]) {
      visited[temp] = 1;
      temp = b[temp];
    }
  }
  cout << 2 * n - ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  int T;
  T = 1;
  while (T--)
    solve();
}
