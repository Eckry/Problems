#include <bits/stdc++.h>

using namespace std;

#define ll long long

#define optimize()                \
    cin.tie(0);                   \
    cin.sync_with_stdio(0);       \
    ios_base::sync_with_stdio(0); \
    cout.tie(0);

void solve() {
  int n, k; cin >> n>> k;
  vector<int> a(n);
  for(auto &c : a) cin >> c;

  vector<int> seen(n + 1, 0);
  int mex = 0;
  for(int i = 0 ; i<n;i ++) {
    seen[a[i]]++;
    while(seen[mex]) mex++;
  }
  if(mex == k) {
    cout << 0 << "\n";

  } else if(mex < k) {
    int ans = 0;
    while(mex != k) {
      if(seen[mex]) {
        mex++;
      } else if(seen[k]) {
        seen[k]--;
        ans++;
        mex++;
      } else {
        ans++; 
        mex++;
      }
    }
    cout << ans + seen[k] << "\n";
  } else {
    cout << seen[k] << "\n";
  }

}

int main() {
  optimize()
  int T;
  cin >> T;
  while(T--) solve();
}
