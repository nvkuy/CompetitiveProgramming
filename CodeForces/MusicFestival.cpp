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
        return max(n1, n2);
    }

    void build(int id, int l, int r, vector<int> &a, int n) {
        if (l >= n) {
            ST[id] = SKIP_VALUE;
            return;
        }
        if (l == r) {
            ST[id] = a[l];
            return;
        }
        int mid = (l + r) / 2;
        build(id * 2, l, mid, a, n);
        build(id * 2 + 1, mid + 1, r, a, n);
        ST[id] = mergeN(ST[id * 2], ST[id * 2 + 1]);
    }

    void build(vector<int> &a, int n) {
        build(1, 0, ts, a, n);
    }

    void update(int id, int l, int r, int i, int v) {
        if (i < l || r < i) {
            return ;
        }
        if (l == r) {
            ST[id] = v;
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

    int get(int id, int l, int r, int u, int v) {
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
        return get(1, 0, ts, l, r);
    }

};

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> all_num;
        vector<pair<int, vector<int>>> album(n); 
        for (int i = 0; i < n; i++) {
            int k, max_val = 0;
            cin >> k;
            while (k--) {
                int ai;
                cin >> ai;
                max_val = max(max_val, ai);
                album[i].second.push_back(ai);
                all_num.push_back(ai);
            }
            album[i].first = max_val;
        }
        sort(all_num.begin(), all_num.end());
        map<int, int> compress_func;
        int cur = 0;
        for (int num : all_num) {
            if (compress_func[num] == 0) {
                cur++;
                compress_func[num] = cur;
            }
        }
        for (int j = 0; j < album.size(); j++) {
            for (int i = 0; i < album[j].second.size(); i++)
                album[j].second[i] = compress_func[album[j].second[i]];
            album[j].first = compress_func[album[j].first];
        }
        sort(album.begin(), album.end());
        vector<vector<int>> f(n);
        for (int i = 0; i < album.size(); i++) {
            auto &ab = album[i].second;
            f[i].resize(ab.size());
            stack<int> next_greater;
            for (int j = ab.size() - 1; j >= 0; j--) {
                while (next_greater.size() > 0 && ab[next_greater.top()] <= ab[j]) next_greater.pop();
                int pre_f = 0;
                if (next_greater.size() > 0) pre_f = f[i][next_greater.top()];
                f[i][j] = pre_f + 1;
                next_greater.push(j);
            }
        }
        SegTree st(cur + 2);
        for (int i = 0; i < n; i++) {
            int max_val = album[i].first, val = st.get(max_val, max_val), cur_max = 0;
            auto &ab = album[i].second;
            for (int j = 0; j < ab.size(); j++) {
                if (ab[j] <= cur_max) continue;
                cur_max = max(cur_max, ab[j]);
                val = max(val, st.get(0, ab[j] - 1) + f[i][j]);
            }
            st.update(max_val, val);
        }
        cout << st.get(0, cur + 1) << endl;
    }

    return 0;
}
