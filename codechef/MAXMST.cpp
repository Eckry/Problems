#include <bits/stdc++.h>

using namespace std;

#define ll long long

#define optimize()                                                             \
  cin.tie(0);                                                                  \
  cin.sync_with_stdio(0);                                                      \
  ios_base::sync_with_stdio(0);                                                \
  cout.tie(0);

void solve() {
  int n;
  cin >> n;
  int m = n * (n - 1);
  m /= 2;
  vector<int> w(m);
  for (auto &c : w)
    cin >> c;
  sort(w.begin(), w.end(), greater<>());
  int i = 0;
  int j = 1;
  int acc = 0;
  ll ans = 0;
  // while (i + acc < m) {
  //   cout << w[i + acc] << " ";
  //   i++;
  //   if (i == n - j) {
  //     j++;
  //     ans += w[i + acc - 1]; 
  //     cout << "dawdaw " <<  w[i + acc - 1] << "\n";
  //     acc = i;
  //     i = 0;
  //   }
  // }
 int temp = 0; 
  while(n - j > 0){
    for(int i = 0; i< n -j; i++){
      // cout << w[i + temp] << " ";
      acc = i;
    }
    // cout << "\n";
    // cout << "\n";
    // cout << w[acc + temp] << "\n";
    ans += w[acc + temp];
    temp += acc + 1;
    j++;
  }
  cout << ans << "\n";
}

int main() {
  optimize();
  int T;
  cin >> T;
  while (T--)
    solve();
}
