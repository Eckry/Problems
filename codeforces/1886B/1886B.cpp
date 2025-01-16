#include <bits/stdc++.h>

using namespace std;

#define optimize()              \
  cin.tie(0);                   \
  cin.sync_with_stdio(0);       \
  ios_base::sync_with_stdio(0); \
  cout.tie(0);

void solve()
{
  int px, py, ax, ay, bx, by;

  cin >> px >> py >> ax >> ay >> bx >> by;

  long double r = sqrt(pow(bx - ax, 2) + pow(by - ay, 2));
  long double ans = r / 2;
  long double distanceP1 = sqrt(pow(ax, 2) + pow(ay, 2));
  long double distanceP2 = sqrt(pow(bx, 2) + pow(by, 2));
  long double distanceP1House = sqrt(pow(ax - px, 2) + pow(ay - py, 2));
  long double distanceP2House = sqrt(pow(bx - px, 2) + pow(by - py, 2));
  long double minAns = min(distanceP1House, distanceP2House);
  long double minHouse = min(distanceP2House, distanceP1House);

  long double firstCaseA = max(distanceP1, distanceP1House);
  long double firstCaseB = max(distanceP2, distanceP2House);

  long double secondCaseAB = max(distanceP1House, max(distanceP2, ans));
  long double secondCaseBA = max(distanceP2House, max(distanceP1, ans));

  cout << setprecision(10) << min(min(firstCaseA, firstCaseB), min(secondCaseAB, secondCaseBA)) << "\n";
}

int main(void)
{
  optimize();
  int T;
  cin >> T;
  // T = 1;
  while (T--)
    solve();
}