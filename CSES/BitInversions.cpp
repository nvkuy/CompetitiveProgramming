#include <bits/stdc++.h>
using namespace std;

struct Node {
    int maxZero, maxOne;
    int maxSufZero, maxSufOne;
    int maxPreZero, maxPreOne;
    int length;
    Node() { 
        maxZero = maxOne = maxSufOne = maxSufZero = maxPreOne = maxPreZero = length = 0;
    }
    Node(char c) {
        maxZero = maxSufZero = maxPreZero = (c == '0');
        maxOne = maxSufOne = maxPreOne = (c != '0');
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

        res.maxPreOne = n1.maxPreOne;
        if (n1.length == n1.maxPreOne)
            res.maxPreOne = n1.maxPreOne + n2.maxPreOne;
        res.maxPreZero = n1.maxPreZero;
        if (n1.length == n1.maxPreZero)
            res.maxPreZero = n1.maxPreZero + n2.maxPreZero;
        
        res.maxSufOne = n2.maxSufOne;
        if (n2.length == n2.maxSufOne)
            res.maxSufOne = n1.maxSufOne + n2.maxSufOne;
        res.maxSufZero = n2.maxSufZero;
        if (n2.length == n2.maxSufZero)
            res.maxSufZero = n1.maxSufZero + n2.maxSufZero;

        res.maxOne = max(max(max(n1.maxOne, n2.maxOne), max(res.maxPreOne, res.maxSufOne)), n1.maxSufOne + n2.maxPreOne);
        res.maxZero = max(max(max(n1.maxZero, n2.maxZero), max(res.maxPreZero, res.maxSufZero)), n1.maxSufZero + n2.maxPreZero);

        return res;
    }

    void build(int id, int l, int r, string &s, int n) {
        if (l >= n) {
            ST[id] = SKIP_VALUE;
            return;
        }
        if (l == r) {
            ST[id] = Node(s[l]);
            return;
        }
        int mid = (l + r) / 2;
        build(id * 2, l, mid, s, n);
        build(id * 2 + 1, mid + 1, r, s, n);
        ST[id] = mergeN(ST[id * 2], ST[id * 2 + 1]);
    }

    void build(string &s, int n) {
        build(1, 0, ts, s, n);
    }

    void update(int id, int l, int r, int i, char c) {
        if (i < l || r < i) {
            return ;
        }
        if (l == r) {
            ST[id] = Node(c);
            return ;
        }

        int mid = (l + r) / 2;
        update(id * 2, l, mid, i, c);
        update(id * 2 + 1, mid + 1, r, i, c);
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
        return max(tmp.maxZero, tmp.maxOne);
    }

};

int main() {

    string s;
    cin >> s;
    SegTree st = SegTree(s.length());
    st.build(s, s.length());
    int q;
    cin >> q;
    while (q--) {
        int p;
        cin >> p;
        p--;
        s[p] = (1 - (s[p] - '0')) + '0';
        st.update(p, s[p]);
        cout << st.get(0, s.length() - 1) << ' ';
    }
    cout << endl;

    return 0;
}