#include <bits/stdc++.h>

using namespace std;

#define optimize() cin.tie(0);cin.sync_with_stdio(0);ios_base::sync_with_stdio(0);cout.tie(0);

int main(void)
{
  optimize()

  int T;
  cin >> T;

  while(T--){
    string s;
    cin >> s;
    int n = s.length();
    
    if(s.substr(0, s.length() / 2) == s.substr(s.length() / 2, s.length())) cout << "YES" << endl;
    else cout << "NO" << endl;

  }

}