#include <bits/stdc++.h>

using namespace std;

#define ll long long

#define optimize()                \
    cin.tie(0);                   \
    cin.sync_with_stdio(0);       \
    ios_base::sync_with_stdio(0); \
    cout.tie(0);

void solve()
{
    int n;

    cin >> n;
    int k = n / 4;
    cout << k * k + k * ((n % 4) / 2) << "\n";
}

int main(void)
{
    optimize();
    int T;
    T = 1;
    while (T--)
        solve();
}