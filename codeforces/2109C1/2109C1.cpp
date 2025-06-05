#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define optimize()              \
  cin.tie(0);                   \
  cin.sync_with_stdio(0);       \
  ios_base::sync_with_stdio(0); \
  cout.tie(0);

void solve()
{
  ll n;
  cin >> n;

  cout << "digit" << endl;
  char ans;
  cin >> ans;
  cout << "digit" << endl;
  cin >> ans;
  cout << "add -8" << endl;
  cin >> ans;
  cout << "add -4" << endl;
  cin >> ans;
  cout << "add -2" << endl;
  cin >> ans;
  cout << "add -1" << endl;
  cin >> ans;
  cout << "add " << n - 1 << endl;
  cin >> ans;
  cout << "!" << endl;
  cin >> ans;
}

int main(void)
{
  int T;
  cin >> T;
  // T = 1;
  while (T--)
    solve();
}