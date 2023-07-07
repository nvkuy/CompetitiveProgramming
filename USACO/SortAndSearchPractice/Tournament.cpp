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

struct Group {

    int size;
    vector<int> low, high;

    Group(const vector<int> &power) {
        size = 1;
        low = power;
        high = power;
    }

    void merge(const Group &g) {
        size += g.size;
        for (int i = 0; i < low.size(); i++) {
            high[i] = max(high[i], g.high[i]);
            low[i] = min(low[i], g.low[i]);
        }
    }

    bool operator < (const Group &g) const {
        for (int i = 0; i < low.size(); i++)
            if (high[i] >= g.low[i]) return false;
        return true;
    }

};

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    debugLocal();

    int n, k;
    cin >> n >> k;
    set<Group> groups;
    while (n--) {
        vector<int> power(k);
        for (int i = 0; i < k; i++) cin >> power[i];
        Group group(power);
        auto lit = groups.lower_bound(group);
        auto rit = groups.upper_bound(group);
        while (lit != rit) {
            group.merge(*lit);
            lit = groups.erase(lit);
        }
        groups.insert(group);
        cout << groups.rbegin()->size << endl;
    }

    return 0;
}
