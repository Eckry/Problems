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
  vector<int> a(n);
  for (auto &c : a)
    cin >> c;

  vector<int> sm(n, 0);
  sm[0] = a[0];
  for (int i = 1; i < n; i++) {
    sm[i] = sm[i - 1] + a[i];
  }
  for (int i = 0; i < n - 1; i++) {
    for (int j = i + 1; j < n - 1; j++) {
      int s1 = sm[i];
      int s2 = sm[j] - sm[i];
      int s3 = sm[n - 1] - sm[j];
      if (s1 % 3 != s2 % 3 && s1 % 3 != s3 % 3 && s2 % 3 != s3 % 3) {
        cout << i + 1 << " " << j + 1 << "\n";
        return;
      }
      if (s1 % 3 == s2 % 3 && s1 % 3 == s3 % 3 && s2 % 3 == s3 % 3) {
        cout << i + 1 << " " << j + 1 << "\n";
        return;
      }
    }
  }
  cout << 0 << " " << 0 << "\n";
}

int main() {
  optimize();
  int T;
  cin >> T;
  while (T--)
    solve();
}
