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

vector<int> par, cnt_other, cnt_want;

int getRoot(int u) {
    if (par[u] < 0) return u;
    return (par[u] = getRoot(par[u]));
}

int getSize(int u) {
    return -par[getRoot(u)];
}

void merge(int u, int v) {
    int p1 = getRoot(u), p2 = getRoot(v);
    if (p1 == p2) return;
    if (getSize(p1) < getSize(p2)) swap(p1, p2);
    par[p1] += par[p2];
    par[p2] = p1;
    cnt_other[p1] += cnt_other[p2];
    cnt_want[p1] += cnt_want[p2];
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    par.assign(n + 1, -1);
    cnt_other.assign(n + 1, 0);
    cnt_want.assign(n + 1, 0);

    int m;
    cin >> m;
    while (m--) {
        int u;
        cin >> u;
        cnt_want[u]++;
    }

    int have;
    cin >> have;
    for (int i = 0; i < have; i++) cin >> m;

    int l;
    cin >> l;
    while (l--) {
        int u;
        cin >> u;
        cnt_other[u]++;
    }

    int g;
    cin >> g;
    while (g--) {
        int u, v;
        cin >> u >> v;
        merge(u, v);
    }

    int use_mine = 0, use_other = 0, remain = 0;
    for (int i = 0; i <= n; i++) {
        if (par[i] >= 0) continue;
        int use = min(cnt_other[i], cnt_want[i]);
        remain += cnt_want[i] - use;
        use_other += use;
    }
    use_mine = min(have, remain);
    int use_me = min(use_mine, have), max_remain = have - use_me, trade = min(max_remain, use_other);
    use_mine += trade;
    use_other -= trade;

    cout << use_mine << ' ' << use_other << endl;

    return 0;
}
