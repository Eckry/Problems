#include <bits/stdc++.h>

using namespace std;

#define ll long long

#define optimize()                \
    cin.tie(0);                   \
    cin.sync_with_stdio(0);       \
    ios_base::sync_with_stdio(0); \
    cout.tie(0);

void solve() {
  int n, m ; cin >> n >> m;
  string s; cin >> s;
  vector<int> a(m);
  for(auto &c : a) cin >> c;
  int j = 0;
  int pos = 1;
  for(int i = 0;i<n;i++) {
    if(s[i] == 'A') {
      pos++;
      // cout << i << " " << pos << "\n";
      a.push_back(pos);
      while(j < m && pos > a[j]) j++;
    } else {
      pos++;
      while(j < m && pos > a[j]) {
        j++;
      }
      while(j < m && pos == a[j]) {
        pos++;
        j++;
      }
      a.push_back(pos);
      // cout << pos << " " << j <<  "\n";
      // cout << i << " " << pos << "\n";
      pos++;
      // if(pos == 7) cout << j << "\n";
      while(j < m && pos > a[j]) {
        j++;
      }
      while(j < m && pos == a[j]) {
        pos++;
        j++;
      }
    // cout << "asd" << " " << pos << "\n";
    }
  }
  set<int> st(a.begin(), a.end());
  a = vector<int>(st.begin(), st.end());
  sort(a.begin(), a.end());
  cout << a.size() << "\n";
  for(auto c : a) cout << c << " ";
  cout << "\n";

}

int main() {
  optimize()
  int T;
  cin >> T;
  while(T--) solve();
}
