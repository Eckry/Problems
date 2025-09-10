#include <bits/stdc++.h>

using namespace std;

#define ll long long

#define optimize()                \
    cin.tie(0);                   \
    cin.sync_with_stdio(0);       \
    ios_base::sync_with_stdio(0); \
    cout.tie(0);

void solve() {
  int a,b; cin >> a >> b;
  if(b == 1) {cout << 0 << "\n";return;}
  if(b >= a * 2){
    cout << a + a * 2 << "\n";
    return;
  }
  if(a * 2 >= b){
    cout << b - b % 2 + b / 2 << "\n";
    return;
  }
}

int main() {
  optimize();
  int T;
  cin >> T;
  while(T--) solve();
}
