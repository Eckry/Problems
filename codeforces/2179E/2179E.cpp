#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve() {
  ll n, x, y;
  cin >> n >> x >> y;
  string s;
  cin >> s;

  vector<ll> p(n);
  for (auto &c : p)
    cin >> c;

  ll smp = 0;
  for (int i = 0; i < n; i++) {
    smp += p[i];
  }
  if (smp > x + y) {
    cout << "NO\n";
    return;
  }

  vector<ll> a(n, 0);
  vector<ll> b(n, 0);
  ll sma = 0;
  ll smb = 0;
  ll mnb = 0;
  ll mna = 0;
  int oneina = 0;
  int oneinb = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == '0') {
      a[i] = p[i];
      b[i] = 0;
      mna += (p[i] + 1) / 2;
      if (p[i] % 2 == 0) {
        mna++;
      }
      oneina = 1;
    } else {
      b[i] = p[i];
      a[i] = 0;
      mnb += (p[i] + 1) / 2;
      if (p[i] % 2 == 0) {
        mnb++;
      }
      oneinb = 1;
    }
    smb += b[i];
    sma += a[i];
  }
  // cout << mna << " " << mnb << "\n";
  if (mna > x || mnb > y) {
    cout << "NO\n";
    return;
  }

  if (oneina && oneinb) {
    if (sma <= x && smb <= y) {
      cout << "YES\n";
      return;
    }
    for (auto c : a) {
      cout << c << " ";
    }
    cout << "\n";
    for (auto c : b) {
      cout << c << " ";
    }
    cout << "\n";

    cout << sma << " " << smb << "\n";
    if (sma > x) {
      ll diff = sma - x;
      for (int i = 0; i < n; i++) {
        if (a[i] < b[i])
          continue;
        ll newval = (p[i] + 1) / 2;
        ll newvalb = p[i] / 2;
        if (p[i] % 2 == 0) {
          newval++;
          newvalb--;
        }
        cout << "Changing: " << a[i] << " to " << newval << "\n";
        if (diff >= a[i] - newval) {
          diff -= a[i] - newval;
          sma -= a[i] - newval;
          smb += newvalb;
          a[i] = newval;
          b[i] = newvalb;
        } else {
          sma -= diff;
          smb += diff;
          a[i] -= diff;
          b[i] += diff;
          diff = 0;
        }
        if (diff == 0)
          break;
      }
    } else if (smb > y) {
      ll diff = smb - y;
      for (int i = 0; i < n; i++) {
        if (a[i] > b[i])
          continue;
        ll newval = (p[i] + 1) / 2;
        ll newvalb = p[i] / 2;
        if (p[i] % 2 == 0) {
          newval++;
          newvalb--;
        }
        if (diff >= b[i] - newval) {
          diff -= b[i] - newval;
          smb -= b[i] - newval;
          sma += newvalb;
          b[i] = newval;
          a[i] = newvalb;
        } else {
          smb -= diff;
          sma += diff;
          b[i] -= diff;
          a[i] += diff;

          diff = 0;
        }
        if (diff == 0)
          break;
      }
    }
    for (auto c : a) {
      cout << c << " ";
    }
    cout << "\n";
    for (auto c : b) {
      cout << c << " ";
    }
    cout << "\n";
    cout << sma << " " << smb << "\n";
    if (sma <= x && smb <= y) {
      cout << "YES\n";
    } else
      cout << "NO\n";
    return;
  }

  if (oneina) {
    if (x - n >= y) {
      cout << "YES\n";
    } else
      cout << "NO\n";
    return;
  }
  if (oneinb) {
    if (y - n >= x) {
      cout << "YES\n";
    } else
      cout << "NO\n";
    return;
  }
  cout << "YES\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--)
    solve();
}
