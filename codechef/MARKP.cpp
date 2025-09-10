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
  int cnt = 0;
  int start = 0;
  int end = n - 1;
  while(start < n && s[start] == '1')start++;
  while(end >= 0 && s[end] == '1')end--;

  if(start == 2 || start == 1 || end == n - 3 || end == n - 2){
    cout << "NO" << "\n";
    return;
  } 
  for(int i = start; i <= end;i++){
    if(s[i] == '1'){
      cnt++;
    } 
    if(s[i] == '0' && cnt){
      if(cnt < 3){
        cout << "NO" << "\n";  
        return;
      }
      cnt = 0;
    }
  }
  cout << "YES" << "\n";
}

int main() {
  optimize();
  int T;
  cin >> T;
  while(T--) solve();
}
