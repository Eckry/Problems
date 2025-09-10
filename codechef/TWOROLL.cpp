#include <bits/stdc++.h>

using namespace std;

#define ll long long

#define optimize()                \
    cin.tie(0);                   \
    cin.sync_with_stdio(0);       \
    ios_base::sync_with_stdio(0); \
    cout.tie(0);

void solve() {
  int x, y; cin >> x >> y;
  int lower = y * 2;
  int upper = (y + 5) * 2;
  if(lower <= 50 - x && 50 - x <= upper){
    cout << "YES" << "\n";
  } else {
    cout << "NO" << "\n";
  }
}

int main() {
  optimize()
  int T;
  cin >> T;
  while(T--) solve();
}
