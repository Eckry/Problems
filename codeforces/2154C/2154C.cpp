#include <bits/stdc++.h>

using namespace std;

#define ll long long

vector<int> primes;
vector<vector<int>> erat(200002, vector<int>());

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &c : a)
    cin >> c;
  vector<int> b(n);
  for (auto &c : b)
    cin >> c;

  map<int, int> cnt;
  for (int i = 0; i < n; i++) {
    for (auto p : erat[a[i]]) {
      if (cnt[p] > 0) {
        cout << 0 << "\n";
        return;
      }
      cnt[p]++;
    }
  }

  for (int i = 0; i < n; i++) {
    for (auto p : erat[a[i]]) {
      cnt[p]--;
    }
    for (auto p : erat[a[i] + 1]) {
      if (cnt[p] > 0) {
        cout << 1 << "\n";
        return;
      }
    }

    for (auto p : erat[a[i]]) {
      cnt[p]++;
    }
  }
  cout << 2 << "\n";
}

int main() {
  for (int i = 2; i < 200002; i++) {
    if (erat[i].size() != 0)
      continue;
    for (int j = i; j < 200001; j += i) {
      erat[j].push_back(i);
    }
  }
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--)
    solve();
}
