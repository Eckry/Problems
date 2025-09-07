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
    int temp = n;
    int ans = 0;
    while (temp > 0)
    {
        int x = temp % 10;
        temp /= 10;
        if (x == 0)
            continue;
        if (n % x == 0)
            ans++;
    }
    cout << ans << "\n";
}

int main(void)
{
    optimize();
    int T;
    T = 1;
    while (T--)
        solve();
}