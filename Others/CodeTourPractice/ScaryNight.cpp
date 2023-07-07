#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

struct Node
{
    long long val1, val2;
    int lazy;
    Node(long long dat1, long long dat2, int lzy)
    {
        val1 = dat1;
        val2 = dat2;
        lazy = lzy;
    }
};

struct SegTree
{

    Node SKIP_VALUE = Node(0, 0, 0);
    int ts;
    vector<Node> ST;

    SegTree(int tsize)
    {
        ts = 1;
        while (ts < tsize)
            ts *= 2;
        ST.assign(2 * ts + 2, SKIP_VALUE);
    }

    Node mergeN(Node n1, Node n2)
    {
        return Node(n1.val1 + n2.val1, n1.val2 + n2.val2, 0);
    }

    void pushDown(int id)
    {
        int lz = ST[id].lazy;
        rotK(ST[id * 2].val1, ST[id * 2].val2, lz);
        ST[id * 2].lazy += lz;
        rotK(ST[id * 2 + 1].val1, ST[id * 2 + 1].val2, lz);
        ST[id * 2 + 1].lazy += lz;
        ST[id].lazy = 0;
    }

    void rot90(long long &x, long long &y)
    {
        long long t1 = -y, t2 = x;
        x = t1, y = t2;
    }

    void rotK(long long &x, long long &y, int k)
    {
        for (int i = 0; i < (k % 4); i++)
            rot90(x, y);
    }

    void build(int id, int l, int r, vector<pair<int, int>> &a, int n)
    {
        if (l >= n)
        {
            ST[id] = SKIP_VALUE;
            return;
        }
        if (l == r)
        {
            ST[id] = Node(a[l].first, a[l].second, 0);
            return;
        }
        int mid = (l + r) / 2;
        build(id * 2, l, mid, a, n);
        build(id * 2 + 1, mid + 1, r, a, n);
        ST[id] = mergeN(ST[id * 2], ST[id * 2 + 1]);
    }

    void build(vector<pair<int, int>> &a, int n)
    {
        build(1, 0, ts, a, n);
    }

    void update(int id, int l, int r, int u, int v, int val)
    {
        if (v < l || r < u)
        {
            return;
        }
        if (u <= l && r <= v)
        {
            rotK(ST[id].val1, ST[id].val2, val);
            ST[id].lazy += val;
            return;
        }
        pushDown(id);
        int mid = (l + r) / 2;
        update(id * 2, l, mid, u, v, val);
        update(id * 2 + 1, mid + 1, r, u, v, val);
        ST[id] = mergeN(ST[id * 2], ST[id * 2 + 1]);
    }

    void update(int l, int r, int val)
    {
        update(1, 0, ts, l, r, val);
    }

    void updateNode(int id, int l, int r, int i, pair<int, int> cor) {
        if (i < l || i > r)
            return;
        if (l == r) {
            ST[id] = Node(cor.first, cor.second, 0);
            return;
        }
        pushDown(id);
        int mid = (l + r) / 2;
        updateNode(id * 2, l, mid, i, cor);
        updateNode(id * 2 + 1, mid + 1, r, i, cor);
        ST[id] = mergeN(ST[id * 2], ST[id * 2 + 1]);
    }

    void updateNode(int i, pair<int, int> cor) {
        updateNode(1, 0, ts, i, cor);
    }

    Node get(int id, int l, int r, int u, int v)
    {
        if (v < l || r < u)
        {
            return SKIP_VALUE;
        }
        if (u <= l && r <= v)
        {
            return ST[id];
        }
        pushDown(id);
        int mid = (l + r) / 2;
        return mergeN(get(id * 2, l, mid, u, v), get(id * 2 + 1, mid + 1, r, u, v));
    }

    pair<long long, long long> get(int l, int r)
    {
        Node rs = get(1, 0, ts, l, r);
        return {rs.val1, rs.val2};
    }
};

// Note: LazySegTree index 0

pair<int, int> toCor(char c)
{
    if (c == 'N')
        return {1, 0};
    else if (c == 'E')
        return {0, 1};
    else if (c == 'S')
        return {-1, 0};
    else
        return {0, -1};
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string s;
    int n, q, u, v, ans = 0, t, k;
    char c;
    cin >> n >> q;
    cin >> s;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < s.length(); i++)
        a[i] = toCor(s[i]);
    SegTree st = SegTree(n);
    st.build(a, n);
    for (int i = 0; i < q; i++)
    {
        cin >> t;
        if (t == 1)
        {
            cin >> u >> c;
            u--;
            st.updateNode(u, toCor(c));
        } else {
            cin >> u >> v >> k;
            u--, v--;
            st.update(u, v, k);
        }
        pair<long long, long long> tmp = st.get(0, n - 1);
        if (tmp.first == 0 && tmp.second == 0) 
            ans++;
    }
    cout << ans << endl;

    return 0;
}
