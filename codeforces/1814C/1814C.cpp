#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve() {
  int n, s1, s2;
  cin >> n >> s1 >> s2;
  int accs1 = s1;
  int accs2 = s2;
  vector<int> r(n);
  for (auto &c : r)
    cin >> c;
  vector<int> a;
  vector<int> b;
  vector<int> idx(n);
  iota(idx.begin(), idx.end(), 0);
  sort(idx.begin(), idx.end(), [&](int x, int y) { return r[x] > r[y]; });
  // cout << accs1 << " " << accs2 << "\n";
  for (int i = 0; i < n; i++) {
    int id = idx[i];
    if (accs1 < accs2) {
      a.push_back(id + 1);
      accs1 += s1;
    } else {
      b.push_back(id + 1);
      accs2 += s2;
    }
  }
  cout << a.size() << " ";
  for (auto c : a) {
    cout << c << " ";
  }
  cout << "\n";
  cout << b.size() << " ";

  for (auto c : b) {
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
