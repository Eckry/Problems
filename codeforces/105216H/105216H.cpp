#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, r, c;
  cin >> n >> r >> c;

  if (n == 0)
    return 0;
  if (n == 1) {
    cout << 1 << '\n';
    return 0;
  }

  vector<int> nxt(n + 1), prv(n + 1);
  for (int i = 1; i <= n; ++i) {
    nxt[i] = (i == n ? 1 : i + 1);
    prv[i] = (i == 1 ? n : i - 1);
  }

  int alive = n;
  int pos1 = 1; // s1 starts behind candidate id 1
  int pos2 = n; // s2 starts behind candidate id n
  vector<int> hired;

  while (alive > 2) {
    // number of steps to move forward/backward (including own position -> move
    // r-1 steps)
    int steps1 = (r - 1) % alive;
    int steps2 = (c - 1) % alive;

    for (int i = 0; i < steps1; ++i)
      pos1 = nxt[pos1];
    for (int i = 0; i < steps2; ++i)
      pos2 = prv[pos2];

    if (pos1 == pos2) {
      // hire this one and remove it
      hired.push_back(pos1);

      // remove pos1
      int L = prv[pos1], R = nxt[pos1];
      nxt[L] = R;
      prv[R] = L;
      alive--;

      // new positions for supervisors: s1 -> R (next clockwise), s2 -> prev of
      // s1 (counter-clockwise neighbour)
      pos1 = R;
      pos2 = (alive > 0 ? prv[pos1] : pos1);
    } else {
      // remove both pos1 and pos2 (do not hire)
      int a = pos1, b = pos2;

      // compute new starting positions *before* removals
      int nextA = nxt[a];
      int prevB = prv[b];
      // if nextA equals b (adjacent case), skip over b to land at element after
      // b
      if (nextA == b)
        nextA = nxt[b];
      // if prevB equals a (adjacent case), skip over a to land at element
      // before a
      if (prevB == a)
        prevB = prv[a];

      // perform removals (order doesn't matter since we update arrays directly)
      // remove a
      nxt[prv[a]] = nxt[a];
      prv[nxt[a]] = prv[a];
      // remove b
      nxt[prv[b]] = nxt[b];
      prv[nxt[b]] = prv[b];

      alive -= 2;
      // set new positions (if circle is not empty)
      if (alive > 0) {
        pos1 = nextA;
        pos2 = prevB;
      }
    }
  }

  // remaining (<= 2) are hired
  if (alive > 0) {
    int cur = pos1;
    for (int i = 0; i < alive; ++i) {
      hired.push_back(cur);
      cur = nxt[cur];
    }
  }

  sort(hired.begin(), hired.end());
  for (size_t i = 0; i < hired.size(); ++i) {
    if (i)
      cout << ' ';
    cout << hired[i];
  }
  cout << '\n';
  return 0;
}
