#include <bits/stdc++.h>

using namespace std;

#define ll long long

string check(int k, vector<int> &a) {
  int n = a.size();
  string ans = string(n, '1');
  for (int i = 0; i < k; i++) {
    int x = (1 << 28) - 1;
    for (int j = i; j < n; j += k) {
      x &= a[j];
    }
    if (x == 0) {
      return "-1";
    }
    for (int j = i; j < n; j += k) {
      ans[j] = char(97 + 31 - __builtin_clz(x));
    }
  }
  return ans;
}

void solve() {
  int n, k;
  cin >> n >> k;

  vector<string> a(k);
  for (auto &c : a)
    cin >> c;
  vector<int> an(n);
  for (int i = 0; i < n; i++) {
    int x = 0;
    for (int j = 0; j < k; j++) {
      x |= (1 << (a[j][i] - 'a'));
    }
    an[i] = x;
  }

  vector<int> div;
  for (int i = 1; i * i <= n; i++) {
    if (n % i != 0)
      continue;
    div.push_back(i);
    div.push_back(n / i);
  }
  sort(div.begin(), div.end());
  for (auto d : div) {
    // cout << d << "\n";
    string s = check(d, an);
    if (s != "-1") {
      cout << s << "\n";
      return;
    }
  }
  cout << a[0] << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--)
    solve();
}
