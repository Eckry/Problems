#include <bits/stdc++.h>

using namespace std;

string alph = "abcdefghijklmnopqrstuvwxyz";

#define optimize() cin.tie(0);cin.sync_with_stdio(0);ios_base::sync_with_stdio(0);cout.tie(0);

int main(void)
{
  optimize();

  int T;
  cin >> T;
  string s;
  int n, k;
  while (T--)
  {
    cin >> n >> k;
    s = "";
    for (int i = 0; i < n; i++)
      s.append(alph.substr(0, k));

    cout << s << endl;
  }
}