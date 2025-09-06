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

    void build(int v, int tl, int tr, vector<int> &a)
    {
        if (tl == tr)
        {
            sg[v] = a[tl];
        }
        else
        {
            int tm = tl + (tr - tl) / 2;
            build(v * 2, tl, tm, a);
            build(v * 2 + 1, tm + 1, tr, a);
            sg[v] = (sg[v * 2] ^ sg[v * 2 + 1]);
        }
    }

    void update(int v, int tl, int tr, int pos, int newval)
    {
        if (tl == tr)
        {
            sg[v] += newval;
        }
        else
        {
            int tm = tl + (tr - tl) / 2;
            if (pos <= tm)
            {
                update(v * 2, tl, tm, pos, newval);
            }
            else
            {
                update(v * 2 + 1, tm + 1, tr, pos, newval);
            }
            sg[v] = (sg[v * 2] ^ sg[v * 2 + 1]);
        }
    }
    int query(int v, int tl, int tr, int l, int r)
    {
        if (l > r)
        {
            return 0;
        }

        if (tl == l && tr == r)
        {
            return sg[v];
        }

        int tm = tl + (tr - tl) / 2;
        return (query(v * 2, tl, tm, l, min(r, tm)) ^ query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
    }
};

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (auto &c : a)
        cin >> c;
    SegTree sg(n);
    sg.build(1, 0, n - 1, a);
    while (q--)
    {
        char x;
        cin >> x;
        if (x == 'P')
        {
            int l, r;
            cin >> l >> r;
            l--;
            r--;

            int ans = sg.query(1, 0, n - 1, l, r);
            if (ans != 0)
            {
                cout << "FRANK" << "\n";
            }
            else
            {
                cout << "JUAN" << "\n";
            }
        }
        else
        {
            int k, x;
            cin >> k >> x;
            k--;
            sg.update(1, 0, n - 1, k, x);
        }
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