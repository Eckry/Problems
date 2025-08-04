#include <bits/stdc++.h>

using namespace std;

#define optimize()              \
  cin.tie(0);                   \
  cin.sync_with_stdio(0);       \
  ios_base::sync_with_stdio(0); \
  cout.tie(0);

void solve()
{
  int n; cin >> n;
  vector<int> a(n);
  for(auto &c : a) cin >> c;

  if(n % 2 == 0){
    cout << 2 << "\n";
    cout << 1 << " " << n << "\n";
    cout << 1 << " " << n << "\n";
  } else {
    cout << 4 << "\n";
    cout << 1 << " " << n << "\n"; 
    cout << 1 << " " << n - 1 << "\n";
    cout << n - 1 << " " << n << "\n";
    cout << n - 1 << " " << n << "\n";
  }
}

int main(void)
{
  optimize();
  int T;
  cin >> T;
  // T = 1;
  while (T--)
    solve();
}
