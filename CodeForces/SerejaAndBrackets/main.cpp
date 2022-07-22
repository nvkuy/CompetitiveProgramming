#include <bits/stdc++.h>

using namespace std;

struct Node {
    int ans, open, close;
    Node (int opt, int ope, int clo) {
        ans = opt;
        open = ope;
        close = clo;
    }
};

const int maxN = 1e6;
Node skip_value = Node(0, 0, 0);
vector<Node> seg_tree(4 * maxN + 2, skip_value);
string s;

Node mergeNode(Node nl, Node nr) {
    int tmp = min(nl.open, nr.close);
    return Node(nl.ans + nr.ans + tmp, nl.open + nr.open - tmp, nl.close + nr.close - tmp);
}

void build(int id, int l, int r) {
    if (l == r) {
        bool isOpen = (s[l] == '(');
        seg_tree[id] = Node(0, isOpen, 1 - isOpen);
        return;
    }
    int m = (l + r) / 2;
    build(id * 2 + 1, l, m);
    build(id * 2 + 2, m + 1, r);
    seg_tree[id] = mergeNode(seg_tree[id * 2 + 1], seg_tree[id * 2 + 2]);
}

Node getLR(int id, int l, int r, int lq, int rq) {
    if (l > rq || r < lq)
        return skip_value;
    if (lq <= l && rq >= r)
        return seg_tree[id];
    int m = (l + r) / 2;
    return mergeNode(getLR(id * 2 + 1, l, m, lq, rq), getLR(id * 2 + 2, m + 1, r, lq, rq));
}

int main()
{

    int q, l, r;
    getline(cin, s);
    build(0, 0, s.length() - 1);
    cin >> q;
    while (q--) {
        cin >> l >> r;
        Node tmp = getLR(0, 0, s.length() - 1, l - 1, r - 1);
        cout << tmp.ans * 2 << endl;
    }

    return 0;
}
