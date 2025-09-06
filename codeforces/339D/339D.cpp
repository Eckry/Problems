#include <bits/stdc++.h>

using namespace std;

#define ll long long

#define optimize()                \
    cin.tie(0);                   \
    cin.sync_with_stdio(0);       \
    ios_base::sync_with_stdio(0); \
    cout.tie(0);

struct SegTree
{
    int N;
    vector<int> sg;
    SegTree(int n)
    {
        N = 1;
        while (N < n)
        {
            N <<= 1;
        }
        sg.resize(N << 1);
    }

    void build(int v, int tl, int tr, vector<int> &a, int even)
    {
        if (tl == tr)
        {
            sg[v] = a[tl];
        }
        else
        {
            int tm = (tr + tl) / 2;
            build(v << 1, tl, tm, a, 1 - even);
            build((v << 1) | 1, tm + 1, tr, a, 1 - even);
            if (even)
            {
                sg[v] = sg[v << 1] ^ sg[(v << 1) | 1];
            }
            else
            {
                sg[v] = sg[v << 1] | sg[(v << 1) | 1];
            }
        }
    }

    void update(int v, int tl, int tr, int pos, int val, int even)
    {
        if (tl == tr)
        {
            sg[v] = val;
        }
        else
        {
            int tm = (tr + tl) / 2;
            if (pos <= tm)
                update(v << 1, tl, tm, pos, val, 1 - even);
            else
                update((v << 1) | 1, tm + 1, tr, pos, val, 1 - even);
            if (even)
                sg[v] = sg[v << 1] ^ sg[(v << 1) | 1];
            else
                sg[v] = sg[v << 1] | sg[(v << 1) | 1];
        }
    }

    int query()
    {
        return sg[1];
    }
};

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(1 << n);
    for (auto &c : a)
        cin >> c;
    SegTree sg(1 << n);
    sg.build(1, 0, (1 << n) - 1, a, (n % 2 == 0));
    while (m--)
    {
        int p, b;
        cin >> p >> b;
        p--;
        sg.update(1, 0, (1 << n) - 1, p, b, (n % 2 == 0));
        cout << sg.query() << "\n";
    }
}

int main(void)
{
    optimize();
    int T;
    T = 1;
    while (T--)
        solve();
}