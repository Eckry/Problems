#include <bits/stdc++.h>
#include <iostream>

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
  int cnt = 0;
  int zeroidx = 0;
  int numleft = 0;
  for (int i = 0; i < n; i++) {
    numleft = (numleft) ^ (i + 1) ^ a[i];
    if (a[i] == i + 1)
      a[i] = -1;
    if (a[i] == 0) {
      cnt++;
      zeroidx = i;
    }
  }
  // cout << numleft << "\n";
  if (cnt == 1) {
    a[zeroidx] = numleft;
    if (a[zeroidx] == zeroidx + 1)
      a[zeroidx] = -1;
  }
  int ans = 200002;
  int mx = 0;
  int start = 0;
  int end = n - 1;
  while (start < n && a[start] == -1)
    start++;
  while (end >= 0 && a[end] == -1)
    end--;

  // for(auto c : a) cout << c << " ";
  // cout << "\n";
  if (end < start) {
    cout << 0 << "\n";
    return;
  }
  // cout << start << " " << end << "\n";
  for (int i = start; i <= end; i++) {
    if (a[i] == -1 && mx != 0) {
      ans = min(ans, mx);
      mx = 0;
    } else if(a[i] != -1){
      mx++;
    }
  }
  ans = min(ans, mx);

  cout << end -  start  + 1<< "\n";
}

int main() {
  optimize() int T;
  cin >> T;
  while (T--)
    solve();
}
