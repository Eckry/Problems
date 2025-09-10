#include <bits/stdc++.h>

using namespace std;

#define ll long long

#define optimize()                \
    cin.tie(0);                   \
    cin.sync_with_stdio(0);       \
    ios_base::sync_with_stdio(0); \
    cout.tie(0);

void solve() {
  int n, m; cin >> n >> m;
  if(m == 0){
    for(int i = 0 ; i<n - 2; i++){
      cout << "<<";
    }
    cout << "<=<" << "\n";
    return;
  } 

  if(n == 0){
    for(int i = 0 ;i<m - 2; i ++){
      cout << "><";
    }
    cout << ">=>\n";
    return;
  }
  for(int i = 0 ; i<n - 1;i ++){
    cout << "<<"; 
  }
  cout << "<";
  for(int i = 0; i < m; i++){
    cout << "<>";
  }
  cout << "\n";

}

int main() {
  optimize()
  int T;
  cin >> T;
  while(T--) solve();
}
