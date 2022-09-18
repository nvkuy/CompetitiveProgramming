#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

struct Node {
    long long icnt;
    vector<long long> cnt;
    Node (int ai) {
        icnt = 0;
        cnt.assign(44, 0);
        cnt[ai]++;
    }
};

struct SegTree {

    Node SKIP_VALUE = Node(0);
    int ts;
    vector<Node> ST;

    SegTree(int tsize) {
        ts = 1;
        while (ts < tsize)
            ts *= 2;
        ST.assign(2 * ts + 2, SKIP_VALUE);
    }

    Node mergeN(Node n1, Node n2) {
        Node rs = Node(0);
        long long icnt = 0, tmp = 0;
        vector<long long> cnt(44, 0);
        for (int i = 40; i > 0; i--) {
            icnt += (tmp * n2.cnt[i]);
            tmp += n1.cnt[i];
            cnt[i] += (n1.cnt[i] + n2.cnt[i]);
        }
        icnt += (n1.icnt + n2.icnt);
        rs.icnt = icnt;
        rs.cnt = cnt;
        return rs;
    }

    void build(int id, int l, int r, int *a, int n) {
        if (l >= n) {
            ST[id] = SKIP_VALUE;
            return;
        }
        if (l == r) {
            ST[id] = Node(a[l]);
            return;
        }
        int mid = (l + r) / 2;
        build(id * 2, l, mid, a, n);
        build(id * 2 + 1, mid + 1, r, a, n);
        ST[id] = mergeN(ST[id * 2], ST[id * 2 + 1]);
    }

    void build(int *a, int n) {
        build(1, 0, ts, a, n);
    }

    void update(int id, int l, int r, int i, int v) {
        if (i < l || r < i) {
            return ;
        }
        if (l == r) {
            ST[id] = Node(v);
            return ;
        }

        int mid = (l + r) / 2;
        update(id * 2, l, mid, i, v);
        update(id * 2 + 1, mid + 1, r, i, v);
        ST[id] = mergeN(ST[id * 2], ST[id * 2 + 1]);
    }

    void update(int i, int v) {
        update(1, 0, ts, i, v);
    }

    Node get(int id, int l, int r, int u, int v) {
        if (v < l || r < u) {
            return SKIP_VALUE;
        }
        if (u <= l && r <= v) {
            return ST[id];
        }
        int mid = (l + r) / 2;
        return mergeN(get(id * 2, l, mid, u, v), get(id * 2 + 1, mid + 1, r, u, v));
    }

    Node get(int l, int r) {
        return get(1, 0, ts, l, r);
    }

};

int arr[500005];

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, q, t, a, b;
    cin >> n >> q;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    SegTree st = SegTree(n);
    st.build(arr, n);
    while (q--) {
        cin >> t >> a >> b;
        if (t == 1) {
            Node ans = st.get(a - 1, b - 1);
            cout << ans.icnt << endl;
        } else
            st.update(a - 1, b);
    }

    return 0;
}
