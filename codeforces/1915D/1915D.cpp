#include <bits/stdc++.h>

using namespace std;

int main()
{

  int T;
  cin >> T;

  while (T--)
  {
    int n;
    cin >> n;
    string palabra;
    string respuesta = "";
    cin >> palabra;
    while (!palabra.empty())
    {
      int x;
      if (palabra.back() == 'e' || palabra.back() == 'a')
        x = 2;

      else
        x = 3;

      while (x--)
      {
        respuesta += palabra.back();
        palabra.pop_back();
      }
      respuesta += '.';
    }
    respuesta.pop_back();
    reverse(respuesta.begin(), respuesta.end());
    cout << respuesta << '\n';
  }
}