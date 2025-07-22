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
    string s;
    cin >> s;

    int i = s.size() - 1;
    int ans = 0;
    while (i >= 0 && s[i] == '0')
    {
        i--;
        ans++;
    }

    i--;
    while (i >= 0)
    {
        if (s[i] != '0')
            ans++;
        i--;
    }

    cout << ans << " \n";
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