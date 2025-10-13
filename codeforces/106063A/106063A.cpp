#include <bits/stdc++.h>

using namespace std;

#define ll long long

#define optimize()                                                             \
  cin.tie(0);                                                                  \
  cin.sync_with_stdio(0);                                                      \
  ios_base::sync_with_stdio(0);                                                \
  cout.tie(0);

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &c : a)
    cin >> c;
  ll sm = 0;
  for (auto c : a)
    sm += c;

  int cnt = 0;
  while (sm % n != 0) {
    cnt++;
    n--;
  }
  cout << cnt << " ";
}

int main() {
  optimize();
  int T;
  T = 1;
  while (T--)
    solve();
}
