#include <bits/stdc++.h>

using namespace std;

int main(void){
  string w;
  cin >> w;
  char s = toupper(w[0]);
  cout << s << w.substr(1);
}