#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>
#define endl '\n'
#define bit_cnt(x) __builtin_popcountll(x)

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int const inf = 1e9;

struct Node {
    int val, lazy;
    Node(int dat, int lzy) {
        val = dat;
        lazy = lzy;
    }
};

struct SegTree {

    Node SKIP_VALUE = Node(inf, 0);
    int ts;
    vector<Node> ST;

    SegTree(int tsize) {
        ts = 1;
        while (ts < tsize)
            ts *= 2;
        ST.assign(2 * ts + 2, SKIP_VALUE);
    }

    Node mergeN(Node n1, Node n2) {
        return Node(min(n1.val, n2.val), 0);
    }

    void pushDown(int id) {
        int lz = ST[id].lazy;
        ST[id * 2].val += lz;
        ST[id * 2].lazy += lz;
        ST[id * 2 + 1].val += lz;
        ST[id * 2 + 1].lazy += lz;
        ST[id].lazy = 0;
    }

    void update(int id, int l, int r, int u, int v, int val) {
        if (v < l || r < u) {
            return;
        }
        if (u <= l && r <= v) {
            ST[id].val += val;
            ST[id].lazy += val;
            return ;
        }
        pushDown(id);
        int mid = (l + r) / 2;
        update(id * 2, l, mid, u, v, val);
        update(id * 2 + 1, mid + 1, r, u, v, val);
        ST[id] = mergeN(ST[id * 2], ST[id * 2 + 1]);
    }

    void update(int l, int r, int val) {
        update(1, 0, ts, l, r, val);
    }

    // Node get(int id, int l, int r, int u, int v) {
    //     if (v < l || r < u) {
    //         return SKIP_VALUE;
    //     }
    //     if (u <= l && r <= v) {
    //         return ST[id];
    //     }
    //     pushDown(id);
    //     int mid = (l + r) / 2;
    //     return mergeN(get(id * 2, l, mid, u, v), get(id * 2 + 1, mid + 1, r, u, v));
    // }

    // int get(int l, int r) {
    //     Node rs = get(1, 0, ts, l, r);
    //     return rs.val;
    // }

    int getNegPos(int id, int l, int r) {
        if (l == r) {
            if (ST[id].val >= 0)
                return inf;
            return l;
        }
        pushDown(id);
        int m = (l + r) / 2;
        if (ST[id * 2].val < 0)
            return getNegPos(id * 2, l, m);
        return getNegPos(id * 2 + 1, m + 1, r);
    }

    int getNegPos() {
        return getNegPos(1, 0, ts);
    }
    
};

// bool oddPos(int pos, const string &s) {
//     if ((pos - 1 >= 0) && (pos + 1 < s.length()) && (s[pos - 1] == s[pos] == s[pos + 1] == '(')) return true;
//     return false;
// }

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, q, oddPosCnt = 0;
    cin >> n >> q;
    string s;
    cin >> s;

    SegTree st = SegTree(n);
    int cur = 0, neg_cnt = 0;
    set<int> inf_pos, inf_neg;
    for (int i = 0; i < n; i++) {
        // oddPosCnt += oddPos(i, s);
        if (s[i] == ')') {
            cur--;
            neg_cnt++;
        } else cur++;
        st.update(i, i, -inf);
        st.update(i, i, cur);
        if (i > 0 && s[i] == s[i - 1]) {
            if (s[i] == ')') inf_neg.insert(i);
            else inf_pos.insert(i);
        }
    }

    while (q--) {
        
        int pos;
        cin >> pos;
        pos--;

        // oddPosCnt -= oddPos(i, s);

        if (pos > 0) {
            if (s[pos] == s[pos - 1]) {
                if (s[pos] == ')')
                    inf_neg.erase(inf_neg.find(pos));
                else
                    inf_pos.erase(inf_pos.find(pos));
            } else {
                if (s[pos] == ')')
                    inf_pos.insert(pos);
                else
                    inf_neg.insert(pos);
            }
        }
        if (pos + 1 < n) {
            if (s[pos] == s[pos + 1]) {
                if (s[pos] == ')')
                    inf_neg.erase(inf_neg.find(pos + 1));
                else
                    inf_pos.erase(inf_pos.find(pos + 1));
            } else {
                if (s[pos] == ')')
                    inf_pos.insert(pos + 1);
                else
                    inf_neg.insert(pos + 1);
            }
        }

        int val = -2;
        if (s[pos] == ')') {
            val = 2;
            neg_cnt--;
            s[pos] = '(';
        } else {
            s[pos] = ')';
            neg_cnt++;
        }

        // oddPosCnt += oddPos(i, s);

        st.update(pos, n - 1, val);
        cur += val;

        int neg_pos = st.getNegPos();
        bool iok = false;
        if (s[0] == '(' && s[n - 1] == ')') {
            if (neg_pos < n) {
                if (inf_pos.size() > 0 && *inf_pos.begin() < neg_pos) {
                    if (cur == 0) {
                        if (inf_neg.size() > 0 && *inf_neg.rbegin() > *inf_pos.rbegin()) iok = true;
                    } else {
                        if (neg_cnt % 2 == (n - neg_cnt) % 2)
                            if (inf_neg.size() > 0 && *inf_neg.rbegin() > *inf_pos.rbegin()) iok = true;
                    }
                }
            } else {
                if (cur == 0) {
                    if (inf_pos.size() > 0) {
                        if (inf_neg.size() > 0 && *inf_neg.rbegin() > *inf_pos.rbegin()) iok = true;
                    } else
                        iok = true;
                } else {
                    if (neg_cnt % 2 == (n - neg_cnt) % 2) {
                        if (inf_pos.size() > 0) {
                            if (inf_neg.size() > 0 && *inf_neg.rbegin() > *inf_pos.rbegin()) iok = true;
                        } else
                            iok = true;
                    }
                }
            }
        }
        
        cout << (iok ? "YES" : "NO") << endl;
    }

    return 0;
}
