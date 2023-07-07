#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>
#define endl '\n'

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

inline void debugLocal() {
    if (!fopen("input.txt", "r"))
        return;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
}

const int MaxN = 8 * 1e5 + 8, SKIP_VALUE = 2e9;
vector<int> a;
int n;

struct Node {
    int lazy, val;
    Node(int lz = 0, int va = SKIP_VALUE) {
        lazy = lz, val = va;
    }
};

Node ST[MaxN];

Node mergeNode(const Node &n1, const Node &n2) {
    return Node(0, min(n1.val, n2.val));
}

void pushDown(int id) {

    if (id * 2 + 2 >= MaxN) return;

    ST[id * 2 + 1].lazy += ST[id].lazy;
    ST[id * 2 + 1].val += ST[id].lazy;

    ST[id * 2 + 2].lazy += ST[id].lazy;
    ST[id * 2 + 2].val += ST[id].lazy;

    ST[id].lazy = 0;

}

void build(int id, int l, int r) {
    if (l >= n) {
        ST[id] = {0, SKIP_VALUE};
        return;
    }
    if (l == r) {
        ST[id] = {0, a[l]};
        return;
    }
    int m = (l + r) / 2;
    build(id * 2 + 1, l, m);
    build(id * 2 + 2, m + 1, r);
    ST[id] = mergeNode(ST[id * 2 + 1], ST[id * 2 + 2]);
}

void update(int id, int l, int r, int lx, int rx, int val) {
    if (l > rx || r < lx) return;
    if (lx <= l && r <= rx) {
        ST[id].val += val;
        ST[id].lazy += val;
        return;
    }
    pushDown(id);
    int m = (l + r) / 2;
    update(id * 2 + 1, l, m, lx, rx, val);
    update(id * 2 + 2, m + 1, r, lx, rx, val);
    ST[id] = mergeNode(ST[id * 2 + 1], ST[id * 2 + 2]); 
}

int getLR(int id, int l, int r, int lx, int rx) {
    if (l > rx || r < lx) return SKIP_VALUE;
    if (lx <= l && r <= rx) return ST[id].val;
    pushDown(id);
    int m = (l + r) / 2;
    return min(getLR(id * 2 + 1, l, m, lx, rx), getLR(id * 2 + 2, m + 1, r, lx, rx));
}

int findNext(int pos) {
    if (getLR(0, 0, n - 1, pos, n - 1) > 0)
        return 1e9;
    int l = pos, r = n - 1, m;
    while (l < r) {
        m = (l + r) / 2;
        if (getLR(0, 0, n - 1, pos, m) <= 0)
            r = m;
        else
            l = m + 1;
    }
    return r;
}

struct Range {
    int l, r;
    bool operator < (const Range &rg) const {
        return (r - l) < (rg.r - rg.l);
    }
};

multiset<Range> ranges;

vector<Range> getRange(int l, int r) {
    int curL = l;
    vector<Range> res;
    while (curL <= r) {
        int curR = min(findNext(curL), r + 1);
        if (curR - 1 >= curL) res.push_back({curL, curR - 1});
        curL = curR + 1;
    }
    return res;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    debugLocal();

    int t;
    cin >> t;
    while (t--) {
        a.clear();
        long long m;
        cin >> n;
        a.resize(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            a[i] = n - a[i];
        }
        cin >> m;
        build(0, 0, n - 1);
        long long ans = 0;
        vector<Range> tmp = getRange(0, n - 1);
        ranges.clear();
        ranges.insert(tmp.begin(), tmp.end());
        while (true) {
            if (ranges.size() == 0 || m == 0) break;
            auto it = ranges.end();
            it--;
            long long have = getLR(0, 0, n - 1, it->l, it->r);
            long long demand = m / (it->r - it->l + 1LL);
            long long real_use = min(have, demand);
            m -= (real_use * (it->r - it->l + 1LL));
            update(0, 0, n - 1, it->l, it->r, -real_use);
            have -= real_use;
            ans += (real_use * (it->r - it->l));
            if (have > 0 && m > 0) {
                ans += (m - 1);
                m = 0;
            }
            tmp = getRange(it->l, it->r);
            ranges.erase(it);
            ranges.insert(tmp.begin(), tmp.end());
        }
        cout << ans << endl;
    }

    return 0;
}
