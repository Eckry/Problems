#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve() {
  ll n;
  cin >> n;
  vector<ll> a(n);
  for (auto &c : a)
    cin >> c;

  vector<ll> odd;
  vector<ll> even;
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] & 1)
      odd.push_back(a[i]);
    else
      even.push_back(a[i]);
  }

  int o = odd.size();
  int e = even.size();
  if (!o) {
    for (int i = 0; i < n; i++)
      cout << 0 << " ";
    cout << "\n";
    return;
  }

  sort(even.begin(), even.end(), greater<ll>());
  sort(odd.begin(), odd.end(), greater<ll>());
  vector<ll> prefodd(o + 1, 0);
  vector<ll> prefeven(e + 1, 0);
  for (int i = 0; i < e; i++) {
    prefeven[i + 1] = prefeven[i] + even[i];
  }
  for (int i = 0; i < o; i++) {
    prefodd[i + 1] = prefodd[i] + odd[i];
  }
  for (int i = 1; i <= n; i++) {
    ans = 0;
    if (i - 1 > e) {
      ll temp = i - 1;
      if ((temp - e) & 1) {
        if (temp - e + 1 > o - 1) {
          cout << 0 << " ";
          continue;
        }
        temp = e - 1;
      } else {
        if (temp - e > o - 1) {
          cout << 0 << " ";
          continue;
        }
        temp = e;
      }
      if (temp < 0) {
        cout << 0 << " ";
        continue;
      }
      ans += odd[0] + prefeven[temp];
      // cout << temp << "\n";

    } else {
      ans += odd[0] + prefeven[i - 1];
    }
    cout << ans << " ";
  }
  cout << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--)
    solve();
}
