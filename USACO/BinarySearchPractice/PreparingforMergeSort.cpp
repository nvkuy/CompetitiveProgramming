#include <bits/stdc++.h>
using namespace std;

const int MAX_LEN = 8e5 + 12;
int seg_tree[MAX_LEN];

int mergeNode(int n1, int n2) {
    return max(n1, n2);
}

void build(int id, int l, int r, vector<int> &a) {
    if (l >= a.size()) return;
    if (l == r) {
        seg_tree[id] = a[l];
        return;
    }
    int m = (l + r) / 2;
    build(id * 2 + 1, l, m, a);
    build(id * 2 + 2, m + 1, r, a);
    seg_tree[id] = mergeNode(seg_tree[id * 2 + 1], seg_tree[id * 2 + 2]);
}

void update(int id, int l, int r, int p) {
    if (p < l || p > r) return;
    if (l == r) {
        seg_tree[id] = 0;
        return;
    }
    int m = (l + r) / 2;
    update(id * 2 + 1, l, m, p);
    update(id * 2 + 2, m + 1, r, p);
    seg_tree[id] = mergeNode(seg_tree[id * 2 + 1], seg_tree[id * 2 + 2]);
}

int get(int id, int l, int r, int lx, int ai) {
    if (l == r)
        return l;
    int m = (l + r) / 2;
    if (seg_tree[id * 2 + 1] > ai && lx <= m)
        return get(id * 2 + 1, l, m, lx, ai);
    return get(id * 2 + 2, m + 1, r, lx, ai);
}

int main() {

    int n;
    cin >> n;
    vector<int> a(n), dd(n, 0);
    for (int i = 0; i < n; i++) cin >> a[i];

    memset(seg_tree, 0, sizeof(seg_tree));
    build(0, 0, n - 1, a);
    for (int i = 0; i < n; i++) {
        if (dd[i] != 0) continue;
        int preVal = 0, prePos = 0;
        while (seg_tree[0] > preVal) {
            int pos = get(0, 0, n - 1, prePos, preVal);
            cout << a[pos] << ' ';
            dd[pos] = 1;
            update(0, 0, n - 1, pos);
            preVal = a[pos], prePos = pos;
        }
        cout << endl;
    }

    return 0;
}