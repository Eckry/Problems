#include <bits/stdc++.h>

using namespace std;

#define optimize()              \
  cin.tie(0);                   \
  cin.sync_with_stdio(0);       \
  ios_base::sync_with_stdio(0); \
  cout.tie(0);

void solve()
{
  int n;
  cin >> n;
  string s;
  long long int count = 0;
  for (int i = 0; i < n; i++)
  {
    cin >> s;
    if (s == "Tetrahedron")
      count += 4;
    if (s == "Cube")
      count += 6;
    if (s == "Octahedron")
      count += 8;
    if (s == "Dodecahedron")
      count += 12;
    if (s == "Icosahedron")
      count += 20;
  }

  cout << count;
}

int main(void)
{
  optimize();
  int T;
  // cin >> T;
  T = 1;
  while (T--)
    solve();
}