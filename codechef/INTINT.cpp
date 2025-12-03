#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve() {
  ll n;
  cin >> n;
  vector<ll> a(n);
  vector<ll> b(n);
  for (auto &c : a)
    cin >> c;
  for (auto &c : b)
    cin >> c;

  vector<ll> prefa(n + 1, 0);
  vector<ll> prefb(n + 1, 0);
  for (int i = 1; i <= n; i++) {
    prefa[i] = prefa[i - 1] + a[i - 1];
    prefb[i] = prefb[i - 1] + b[i - 1];
  }
  vector<ll> prefmina(n + 1);
  vector<ll> prefminb(n + 1);
  vector<ll> sufmaxa(n + 1);
  vector<ll> sufmaxb(n + 1);
  prefmina[0] = 0;
  prefminb[0] = 0;
  for (int i = 1; i <= n; i++) {
    prefmina[i] = min(prefmina[i - 1], prefa[i]);
    prefminb[i] = min(prefminb[i - 1], prefb[i]);
  }
  sufmaxa[n] = prefa[n];
  sufmaxb[n] = prefb[n];
  for (int i = n - 1; i >= 0; i--) {
    sufmaxa[i] = max(sufmaxa[i + 1], prefa[i]);
    sufmaxb[i] = max(sufmaxb[i + 1], prefb[i]);
  }
  ll ans = LONG_LONG_MIN;
  for (int i = 1; i <= n; i++) {
    // cout << i << " " << prefmina[i - 1] << " " << sufmaxa[i] << " "
    //      << prefminb[i - 1] << " " << sufmaxb[i] << "\n";
    ans = max(ans, sufmaxa[i] - prefmina[i - 1] + sufmaxb[i] - prefminb[i - 1]);
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--)
    solve();
}
