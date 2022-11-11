#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

inline void debugLocal() {
    if (!fopen("input.txt", "r"))
        return;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
}

struct SegTree {

    int SKIP_VALUE = 0;
    int ts;
    vector<int> ST;

    SegTree(int tsize) {
        ts = 1;
        while (ts < tsize)
            ts *= 2;
        ST.assign(2 * ts + 2, SKIP_VALUE);
    }

    int mergeN(int n1, int n2) {
        return n1 + n2;
    }

    void update(int id, int l, int r, int i, int v) {
        if (i < l || r < i) {
            return ;
        }
        if (l == r) {
            ST[id] += v;
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

    int get(int id, int l, int r, int pos) {
        if (l == r)
            return l;
        int mid = (l + r) / 2;
        if (ST[id * 2] >= pos)
            return get(id * 2, l, mid, pos);
        return get(id * 2 + 1, mid + 1, r, pos - ST[id * 2]);
    }

    int get(int pos) {
        return get(1, 0, ts, pos);
    }

};

struct qr {
    int type, num;
    qr(int tt, int nn): type(tt), num(nn) {}
};

map<int, int> hashFunc;
map<int, int> unHashFunc;

void buildHash(vector<int> all_num) {
    sort(all_num.begin(), all_num.end());
    int hash_num = 1;
    for (int ai : all_num) {
        if (hashFunc.find(ai) == hashFunc.end()) {
            unHashFunc[hash_num] = ai;
            hashFunc[ai] = hash_num++;
        }
    }
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    debugLocal();

    int q, num;
    string ss;
    cin >> q;
    vector<qr> qrs;
    vector<int> tmp;
    while (q--) {
        cin >> ss;
        if (ss == "MEDIAN")
            qrs.push_back({0, -1});
        else {
            cin >> num;
            tmp.push_back(num);
            if (ss == "IN")
                qrs.push_back({1, num});
            else
                qrs.push_back({2, num});
        }
    }
    buildHash(tmp);
    SegTree st = SegTree(hashFunc.size() + 2);
    int n = 0;
    for (qr qq : qrs) {
        if (qq.type == 0) {
            int n1 = st.get((n / 2) + 1);
            int n2 = n1;
            if (n % 2 == 0)
                n2 = st.get(n / 2);
            double ans = double(unHashFunc[n1] + unHashFunc[n2]) / 2.0;
            // cout << "At n = " << n << ": ";
            cout << ans << endl;
            // for (int i = 1; i <= n; i++)
            //     cout << unHashFunc[st.get(i)] << ' ';
            // cout << endl;
        } else {
            if (qq.type == 1) {
                st.update(hashFunc[qq.num], 1);
                n++;
            } else {
                st.update(hashFunc[qq.num], -1);
                n--;
            }
        }
    }

    return 0;
}
