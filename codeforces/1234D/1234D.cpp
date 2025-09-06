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
    vector<int> sg;
    int N;
    SegTree(int n)
    {
        N = 1;
        while (N < n)
        {
            N <<= 1;
        }
        sg.resize(N << 1);
    }

    void build(int v, int tl, int tr, string &a)
    {
        if (tl == tr)
        {
            sg[v] = 1 << (a[tl] - 'a');
        }
        else
        {
            int tm = (tl + tr) / 2;
            build(v << 1, tl, tm, a);
            build((v << 1) | 1, tm + 1, tr, a);
            sg[v] = sg[v << 1] | sg[(v << 1) | 1];
        }
    }

    void update(int v, int tl, int tr, int pos, int c)
    {
        if (tl == tr)
        {
            sg[v] = 1 << (c - 'a');
        }
        else
        {
            int tm = (tl + tr) / 2;
            if (pos <= tm)
            {
                update(v << 1, tl, tm, pos, c);
            }
            else
            {
                update((v << 1) | 1, tm + 1, tr, pos, c);
            }
            sg[v] = sg[v << 1] | sg[(v << 1) | 1];
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
        else
        {
            int tm = (tl + tr) / 2;
            return query(v << 1, tl, tm, l, min(r, tm)) | query((v << 1) | 1, tm + 1, tr, max(l, tm + 1), r);
        }
    }
};

void solve()
{
    string s;
    cin >> s;
    int q;
    cin >> q;
    int n = s.size();
    SegTree sg(n);
    sg.build(1, 0, n - 1, s);
    while (q--)
    {
        int p;
        cin >> p;
        if (p == 1)
        {
            int pos;
            char c;
            cin >> pos >> c;
            pos--;
            sg.update(1, 0, n - 1, pos, c);
        }
        else
        {
            int l, r;
            cin >> l >> r;
            l--;
            r--;
            int x = sg.query(1, 0, n - 1, l, r);
            cout << __popcount(x) << "\n";
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