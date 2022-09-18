#include <bits/stdc++.h>

using namespace std;

void facSieve(int n, vector<int> &minPrime) {
    minPrime.assign(n + 1, 0);
    for (int i = 2; i * i <= n; ++i) {
        if (minPrime[i] == 0) {
            for (int j = i * i; j <= n; j += i) {
                if (minPrime[j] == 0) {
                    minPrime[j] = i;
                }
            }
        }
    }
    for (int i = 2; i <= n; ++i) {
        if (minPrime[i] == 0) {
            minPrime[i] = i;
        }
    }
}
/*
vector<int> factorize(int n, vector<int> minPrime) {
    vector<int> res;
    while (n != 1) {
        res.push_back(minPrime[n]);
        n /= minPrime[n];
    }
    return res;
}
*/
struct Node {
    bool ic;
    map<int, int> mf;
    Node(bool isCubic, map<int, int> mFac) {
        ic = isCubic;
        mf = mFac;
    }
};

struct SegTree {

    map<int, int> tmp;
    map<int, int>::iterator it1, it2;
    Node SKIP_VALUE = Node(true, tmp);
    Node INIT_VALUE = Node(false, tmp);
    int ts;
    vector<Node> ST;
    vector<int> minPrime;

    SegTree(int tsize) {
        ts = 1;
        while (ts < tsize)
            ts *= 2;
        ST.assign(2 * ts + 2, INIT_VALUE);
        facSieve(1e6 + 1, minPrime);
    }

    Node mergeN(Node n1, Node n2) {
        bool ic = true;
        map<int, int> mn;
        for (it1 = n1.mf.begin(); it1 != n1.mf.end(); it1++) {
            int c = (*it1).second;
            it2 = n2.mf.find((*it1).first);
            if (it2 != n2.mf.end())
                c += (*it2).second;
            if (c % 3 != 0)
                ic = false;
            mn.insert(make_pair((*it1).first, c));
        }
        for (it1 = n2.mf.begin(); it1 != n2.mf.end(); it1++) {
            it2 = mn.find((*it1).first);
            if (it2 != mn.end())
                continue;
            if ((*it1).second % 3 != 0)
                ic = false;
            mn.insert(make_pair((*it1).first, (*it1).second));
        }
        return Node(ic, mn);
    }

    bool isCubic(map<int, int> mf) {
        for (it2 = mf.begin(); it2 != mf.end(); it2++)
            if ((*it2).second % 3 != 0)
                return false;
        return true;
    }

    void build(int id, int l, int r, int *a, int n) {
        if (l >= n) {
            ST[id] = SKIP_VALUE;
            return;
        }
        if (l == r) {
            bool ic = true;
            map<int, int> mf;
            int ai = a[l];
            mf.insert(make_pair(a[l] + 1, 0));
            it1 = mf.find(a[l] + 1);
            while (ai != 1) {
                if (minPrime[ai] == (*it1).first)
                    (it1->second)++;
                else {
                    mf.insert(make_pair(minPrime[ai], 1));
                    it1 = mf.find(minPrime[ai]);
                }
                ai /= minPrime[ai];
            }
            mf.erase(mf.find(a[l] + 1));
            /*
            vector<int> facs = factorize(a[l], minPrime);
            for (int i = 0; i < facs.size(); i++) {
                it1 = mf.find(facs[i]);
                if (it1 == mf.end())
                    mf.insert(make_pair(facs[i], 1));
                else
                    (it1->second)++;
            }
            */
            /*
            for (it1 = mf.begin(); it1 != mf.end(); it1++) {
                if ((*it1).second % 3 != 0) {
                    ic = false;
                    break;
                }
            }
            */
            ic &= isCubic(mf);
            ST[id] = Node(ic, mf);

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

int a[200002];

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, q, l, r;
    cin >> n >> q;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    SegTree st = SegTree(n);
    st.build(a, n);
    while (q--) {
        cin >> l >> r;
        Node ans = st.get(l - 1, r - 1);
        cout << (st.isCubic(ans.mf) ? "Yes" : "No") << '\n';
    }

    return 0;
}
