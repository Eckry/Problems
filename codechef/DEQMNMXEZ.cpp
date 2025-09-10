#include <bits/stdc++.h>

using namespace std;

#define ll long long

#define optimize()                \
    cin.tie(0);                   \
    cin.sync_with_stdio(0);       \
    ios_base::sync_with_stdio(0); \
    cout.tie(0);

void solve() {

  int n, q; cin >> n >> q;
  vector<int> a(n);
  for(auto &c : a) cin >> c;
  vector<int> b;
  b.push_back(a[0]);
  
  int j = 0;
  for(int i = 1; i <n;i++){
    if(i & 1){
      if(b[0] > b[j]){
        j++;
        b.insert(b.begin(), a[i]);
      }
      else {
        b.push_back(a[i]);
        j++;
      }
    } else {
      if(b[0] > b[j]){
        b.push_back(a[i]);
        j++;
      } else {
        b.insert(b.begin(), a[i]);
        j++;
      }
    }
  }
  // for(auto c : b) cout << c << " ";
  // cout << "\n";
  cout << min(b[0], b[j]) << "\n";
}

int main() {
  optimize()
  int T;
  cin >> T;
  while(T--) solve();
}
