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
    string p;
    string s;
    cin >> p >> s;

    if (p.size() == 1)
    {
        if (s.size() == 1 && s[0] == p[0])
        {
            cout << "YES" << "\n";
            return;
        }
        else if (s[0] == p[0] && p[0] == s[1])
        {
            cout << "YES" << "\n";
            return;
        }
        else
        {
            cout << "NO" << " \n";
            return;
        }
    }
    char last = p[0];
    int cnt = 1;
    int j = 0;
    for (int i = 1; i < p.size(); i++)
    {
        if (p[i] != last)
        {
            int cnt2 = 0;
            while (j < s.size() && s[j] == last)
            {
                j++;
                cnt2++;
            }
            if (cnt2 >= cnt && cnt2 <= 2 * cnt)
            {
                cnt = 1;
                last = p[i];
                continue;
            }
            else
            {
                cout << "NO" << "\n";
                return;
            }
        }
        cnt++;
        last = p[i];
    }
    int cnt2 = 0;
    while (j < s.size() && s[j] == last)
    {
        j++;
        cnt2++;
    }
    if (cnt2 >= cnt && cnt2 <= 2 * cnt)
    {
    }
    else
    {
        cout << "NO" << "\n";
        return;
    }
    if (j != s.size())
    {
        cout << "NO" << "\n";
        return;
    }
    cout << "YES" << "\n";
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