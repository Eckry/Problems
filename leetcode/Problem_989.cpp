#include <bits/stdc++.h>

using namespace std;

#define ll long long

#define optimize()                                                             \
  cin.tie(0);                                                                  \
  cin.sync_with_stdio(0);                                                      \
  ios_base::sync_with_stdio(0);                                                \
  cout.tie(0);

vector<int> addToArrayForm(vector<int> &num, int k) {
  int n = num.size();
  int carry = 0;
  for (int i = n - 1; i >= 0; i--) {
    int tosm = k % 10;
    if (num[i] + tosm + carry >= 10) {
      num[i] = (num[i] + tosm + carry) % 10;
      carry = 1;
    } else {
      num[i] += tosm + carry;
      carry = 0;
    }

    k /= 10;
  }

  while (k || carry) {
    int tosm = carry + k % 10;
    if (tosm >= 10) {
      num.insert(num.begin(), tosm % 10);
      carry = 1;
    } else {
      num.insert(num.begin(), tosm);
      carry = 0;
    }
    k /= 10;
  }
  return num;
}
int main() {
  optimize();
  int T;
  cin >> T;
  int n;
  cin >> n;
  vector<int> num(n);
  for (auto &c : num)
    cin >> c;
  int k;
  cin >> k;
  while (T--)
    addToArrayForm(num, k);
}
