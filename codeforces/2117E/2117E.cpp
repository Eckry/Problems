#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  vector<int> b(n);
  for (auto &c : a)
    cin >> c;
  for (auto &c : b)
    cin >> c;

  vector<int> odd(n + 1, -1);
  vector<int> even(n + 1, -1);

  for (int i = n - 1; i >= 0; i--) {
    if (i & 1) {
      int x = a[i];
      int y = b[i];
      if (odd[x] == -1) {
        // cout << "Adding " << x << " to odd\n";
        odd[x] = i;
      } else if (odd[x] - i > 1) {
        cout << i + 1 << "\n";
        return;
      }
      if (even[y] == -1) {
        // cout << "Adding " << y << " to even\n";
        even[y] = i;
      } else if (even[y] - i > 1) {
        cout << i + 1 << "\n";
        return;
      }
      if (odd[y] != -1) {
        cout << i + 1 << "\n";
        return;
      }

      if (even[x] != -1) {
        cout << i + 1 << "\n";
        return;
      }
    } else {
      int x = a[i];
      int y = b[i];
      if (even[x] == -1)
        even[x] = i;
      else if (even[x] - i > 1) {
        cout << i + 1 << "\n";
        return;
      }
      if (odd[y] == -1)
        odd[y] = i;
      else if (odd[y] - i > 1) {
        cout << i + 1 << "\n";
        return;
      }
      if (even[y] != -1) {
        cout << i + 1 << "\n";
        return;
      }

      if (odd[x] != -1) {
        cout << i + 1 << "\n";
        return;
      }
    }
  }
  cout << 0 << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--)
    solve();
}
