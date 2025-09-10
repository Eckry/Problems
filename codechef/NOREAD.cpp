#include <bits/stdc++.h>

using namespace std;

#define ll long long

#define optimize()                \
    cin.tie(0);                   \
    cin.sync_with_stdio(0);       \
    ios_base::sync_with_stdio(0); \
    cout.tie(0);

void solve() {
  int n; cin >> n;
  vector<int> a(n);
  for(auto &c : a) cin >> c;
  for(int i = 0 ;i<n-1;i++){
    if(a[i] > a[i + 1]){
      cout << i + 1 << " " << i + 2 << "\n"; 
      return;
    }
  }
  cout << -1 << "\n";
}

int main() {
  optimize()
  int T;
  cin >> T;
  while(T--) solve();
}
