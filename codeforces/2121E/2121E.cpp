#include <iostream>
#include <vector>

using namespace std;
#define ll long long
#define optimize()                \
    cin.tie(0);                   \
    cin.sync_with_stdio(0);       \
    ios_base::sync_with_stdio(0); \
    cout.tie(0);

ll get(ll k)
{
    ll res = 1;
    while (k)
    {
        res *= 10;
        k--;
    }
    return res;
}

void solve()
{
    ll l, r;
    cin >> l >> r;

    ll cnt = 0;
    ll x = l;
    while (x)
    {
        cnt++;
        x /= 10;
    }

    ll acc = 0;
    ll temp = cnt;
    ll ans = 0;
    ll initialL = l;
    while (cnt)
    {
        for (int i = 1; i <= 2; i++)
        {
            if (l + i * get(acc) > r)
            {
                break;
            }
            if (((l + i * get(acc)) / get(acc)) % 10 != (r / get(acc)) % 10)
            {
                l += i * get(acc);
                break;
            }
        }
        acc++;
        cnt--;
    }

    ll tempL = initialL;
    ll tempR = r;
    ll tempX = l;
    while (tempX)
    {

        if (tempX % 10 == tempR % 10)
            ans++;
        if (tempX % 10 == tempL % 10)
            ans++;

        tempX /= 10;
        tempR /= 10;
        tempL /= 10;
    }
    cout << ans << "\n";
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