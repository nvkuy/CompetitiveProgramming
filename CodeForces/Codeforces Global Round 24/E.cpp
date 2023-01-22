#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

struct seg {
    int start, add_more, id;
};

bool cmp(const seg &seg1, const seg &seg2) {
    return seg1.start < seg2.start;
}

int n, k, ans;
vector<int> max_reach;
vector<seg> segs;

int cal(int pos) {
    if (ans != 0)
        return 0;
    int reach = segs[pos].start;
    if (pos == 1) {
        if (segs[1].id == 1)
            ans = 1;
        return reach;
    }
    // use seg pos - 1 to populate max reach of seg 1 -> pos - 2 or add more from ans pos - 1 or use start of pos
    reach = max(reach, min(max(max_reach[pos - 2], cal(pos - 1)), segs[pos].start) + segs[pos].add_more);
    // cout << segs[pos].id << ' ' << reach << endl;
    if (segs[pos].id == 1) {
        if (pos < n) // populate from max -> 1
            ans = 1;
        else
            ans |= (reach >= k);
    }
    return reach;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        max_reach.assign(n + 1, 0);
        ans = 0;
        segs.resize(n + 1);
        int x, y;
        for (int i = 1; i <= n; i++) {
            cin >> x >> y;
            segs[i] = {x, y, i};
        }
        if (segs[1].start >= k) {
            cout << "YES" << endl;
            continue;
        }
        if (n == 1 || segs[1].start + segs[1].add_more < k) {
            cout << "NO" << endl;
            continue;
        }
        sort(segs.begin() + 1, segs.end(), cmp);
        for (int i = 1; i <= n; i++)
            max_reach[i] = max(max_reach[i - 1], segs[i].start + segs[i].add_more);
        cal(n);
        cout << (ans ? "YES" : "NO") << endl;
    }

    return 0;
}
