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
  string s; cin >> s;

  vector<ll> sm(n + 1, 0);
  for(int i = 1 ; i<=n;i++){
    sm[i] = sm[i - 1] + (s[i - 1] - '0');
  }
  ll partialans = 0;
  // for(auto c : sm){
  //   cout << c << " ";
  // }
  // cout << "\n";
  for(int i = 2; i <=n;i++){
    partialans += sm[i] - sm[i - 2];
  }
  cout << sm[n] + partialans << "\n";

  // vector<vector<int>> grid(n, vector<int>(n, 0));
  // for(int i = 0; i<n;i++){
  //   for(int j = 0 ; j <n;j ++){
  //     if(i <= j){
  //       for(int k = i; k <= j; k++){
  //         grid[i][j] += (s[k] - '0'); 
  //       }
  //     } 
  //     else {
  //       grid[i][j] = grid[j][i];
  //     }
  //   }
  // }
  // for(int i = 0 ; i<n;i++){
  //   for(int j = 0 ;j<n;j++){
  //     cout << grid[i][j] << " ";
  //   }
  //   cout << "\n";
  // }
  // cout << "\n";
}

int main() {
  optimize()
  int T;
  cin >> T;
  while(T--) solve();
}
