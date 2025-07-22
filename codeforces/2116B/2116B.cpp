#include <iostream>
#include <vector>

using namespace std;
#define ll long long
#define optimize()                \
    cin.tie(0);                   \
    cin.sync_with_stdio(0);       \
    ios_base::sync_with_stdio(0); \
    cout.tie(0);

ll MOD = 998244353;
vector<ll> power(100001);

void solve()
{
    ll n;
    cin >> n;
    vector<ll> p(n);
    vector<ll> q(n);
    for (auto &c : p)
        cin >> c;
    for (auto &c : q)
        cin >> c;

    ll mxp = 0;
    ll mxq = 0;
    vector<ll> ans(n);
    ans[0] = (power[p[mxp]] + power[q[mxq]]) % MOD;

    for (int i = 1; i < n; i++)
    {
        if (p[mxp] < p[i])
            mxp = i;
        if (q[mxq] < q[i])
            mxq = i;

        if (p[mxp] != q[mxq])
        {
            if (p[mxp] > q[mxq])
                ans[i] = (power[p[mxp]] + power[q[i - mxp]]) % MOD;
            else
                ans[i] = (power[q[mxq]] + power[p[i - mxq]]) % MOD;
        }
        else
        {
            ans[i] = (power[p[mxp]] + power[max(p[i - mxq], q[i - mxp])]) % MOD;
        }
    }
    for (auto c : ans)
        cout << c << " ";
    cout << "\n";
}

int main(void)
{
    power[0] = 1;
    power[1] = 2;
    for (int i = 2; i <= 100000; i++)
    {
        power[i] = (power[i - 1] * 2) % MOD;
    }
    optimize();
    int T;
    cin >> T;
    // T = 1;
    while (T--)
        solve();
}