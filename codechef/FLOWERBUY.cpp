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
  if(n == 2){
    cout << 4 << "\n";
    return;
  }
  int ans = 0;
  while(n > 4){
    n-=3;
    ans +=5;
  }
  if(n == 4){
    ans += 8;
  } 
  if(n == 3) {
    ans += 5;
  }

  if(n == 2){
    ans += 4;
  }
  cout << ans << "\n";
}



int main() {
  optimize()
  int T;
  cin >> T;
  while(T--) solve();
}
