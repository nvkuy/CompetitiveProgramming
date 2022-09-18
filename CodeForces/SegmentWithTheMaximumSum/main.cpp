#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

struct Node {
    long long val, suf, pre, slr;
    Node (long long tval, long long tsuf, long long tpre, long long tslr) {
        val = tval;
        pre = tpre;
        suf = tsuf;
        slr = tslr;
    }
};

struct SegTree {

    Node SKIP_VALUE = Node(0LL, 0LL, 0LL, 0LL);
    int ts;
    vector<Node> ST;

    SegTree(int tsize) {
        ts = 1;
        while (ts < tsize)
            ts *= 2;
        ST.assign(2 * ts + 2, SKIP_VALUE);
    }

    Node mergeN(Node n1, Node n2) {
        Node mNode = SKIP_VALUE;
        mNode.val = max(max(n1.val, n2.val), mNode.val);
        mNode.val = max(max(n1.slr + n2.pre, n2.slr + n1.suf), mNode.val);
        mNode.val = max(n1.suf + n2.pre, mNode.val);
        mNode.pre = max(n1.pre, n1.slr + n2.pre);
        mNode.suf = max(n2.suf, n2.slr + n1.suf);
        mNode.slr = n1.slr + n2.slr;
        return mNode;
    }

    Node assignNode(int value) {
        Node tmp = SKIP_VALUE;
        if (value > 0)
            tmp.val = tmp.pre = tmp.suf = value;
        else
            tmp.val = tmp.pre = tmp.suf = 0;
        tmp.slr = value;
        return tmp;
    }

    void build(int id, int l, int r, int *a, int n) {
        if (l >= n) {
            ST[id] = SKIP_VALUE;
            return;
        }
        if (l == r) {
            ST[id] = assignNode(a[l]);
            return;
        }
        int mid = (l + r) / 2;
        build(id * 2, l, mid, a, n);
        build(id * 2 + 1, mid + 1, r, a, n);
        ST[id] = mergeN(ST[id * 2], ST[id * 2 + 1]);
        //cout << "TEST: " << l << '|' << r << ' ' << ST[id].slr << endl;
    }

    void build(int *a, int n) {
        build(1, 0, ts, a, n);
        /*
        cout << "TEST BUILD FUNC: " << endl;
        for (int i = 0; i < ts; i++)
            cout << ST[i].val << '|' << ST[i].pre << '|' << ST[i].suf << '|' << ST[i].slr << ' ';
        cout << endl;
        */
    }

    void update(int id, int l, int r, int i, int v) {
        if (i < l || r < i) {
            return ;
        }
        if (l == r) {
            ST[id] = assignNode(v);
            //cout << "Update " << l << ": " << ST[id].val << endl;
            return;
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

    long long get(int l, int r) {
        Node ans = get(1, 0, ts, l, r);
        return ans.val;
        //return ans.slr;
    }

};

int arr[100001];

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m, i, v;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    SegTree st = SegTree(n);
    st.build(arr, n);

    while (m--) {
        cout << st.get(0, n - 1) << endl;
        cin >> i >> v;
        st.update(i, v);
    }
    cout << st.get(0, n - 1);

    return 0;
}
