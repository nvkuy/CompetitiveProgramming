#include <bits/stdc++.h>
using namespace std;

inline void debugLocal() {
    if (!fopen("snowboots.in", "r"))
        return;
    freopen("snowboots.in", "r", stdin);
    freopen("snowboots.out", "w", stdout);
}

struct Node {
    int maxZero;
    int maxSufZero;
    int maxPreZero;
    int length;
    Node() { 
        maxZero = maxSufZero = maxPreZero = length = 0;
    }
    Node(int i, int v) {
        maxZero = maxSufZero = maxPreZero = v;
        length = 1;
    }
};
 
struct SegTree {
 
    Node SKIP_VALUE = Node();
    int ts;
    vector<Node> ST;
 
    SegTree(int tsize) {
        ts = 1;
        while (ts < tsize)
            ts *= 2;
        ST.assign(2 * ts + 2, SKIP_VALUE);
    }
 
    Node mergeN(Node n1, Node n2) {
 
        Node res = Node();
        res.length = n1.length + n2.length;
 
        res.maxPreZero = n1.maxPreZero;
        if (n1.length == n1.maxPreZero)
            res.maxPreZero = n1.maxPreZero + n2.maxPreZero;
        
        res.maxSufZero = n2.maxSufZero;
        if (n2.length == n2.maxSufZero)
            res.maxSufZero = n1.maxSufZero + n2.maxSufZero;
 
        res.maxZero = max(max(max(n1.maxZero, n2.maxZero), max(res.maxPreZero, res.maxSufZero)), n1.maxSufZero + n2.maxPreZero);
 
        return res;
    }
 
    void build(int id, int l, int r, int n) {
        if (l >= n) {
            ST[id] = SKIP_VALUE;
            return;
        }
        if (l == r) {
            ST[id] = Node(l, 1);
            return;
        }
        int mid = (l + r) / 2;
        build(id * 2, l, mid, n);
        build(id * 2 + 1, mid + 1, r, n);
        ST[id] = mergeN(ST[id * 2], ST[id * 2 + 1]);
    }
 
    void build(int n) {
        build(1, 0, ts, n);
    }
 
    void update(int id, int l, int r, int i, int v) {
        if (i < l || r < i) {
            return ;
        }
        if (l == r) {
            ST[id] = Node(i, v);
            return ;
        }
 
        int mid = (l + r) / 2;
        update(id * 2, l, mid, i, v);
        update(id * 2 + 1, mid + 1, r, i, v);
        ST[id] = mergeN(ST[id * 2], ST[id * 2 + 1]);
    }
 
    void update(int i, char c) {
        update(1, 0, ts, i, c);
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
 
    int get(int l, int r) {
        Node tmp = get(1, 0, ts, l, r);
        return tmp.maxZero;
    }
 
};

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    debugLocal();

    int n, b;
    cin >> n >> b;
    vector<pair<int, int>> snow_pos(n);
    for (int i = 0; i < n; i++) {
        cin >> snow_pos[i].first;
        snow_pos[i].second = i;
    }
    vector<pair<int, pair<int, int>>> boots(b);
    for (int i = 0; i < b; i++) {
        cin >> boots[i].first;
        cin >> boots[i].second.first;
        boots[i].second.second = i;
    }
    sort(snow_pos.begin(), snow_pos.end());
    sort(boots.begin(), boots.end());
    SegTree st = SegTree(n);
    st.build(n);
    int j = 0;
    vector<int> ans(b);
    for (int i = 0; i < boots.size(); i++) {
        while (j < n && snow_pos[j].first <= boots[i].first) {
            st.update(snow_pos[j].second, 0);
            j++;
        }
        ans[boots[i].second.second] = st.get(0, n - 1) < boots[i].second.first;
    }
    for (int ai : ans) cout << ai << endl;

    return 0;
}
