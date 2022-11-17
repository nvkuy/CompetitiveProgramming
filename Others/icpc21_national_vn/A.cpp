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



int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    debugLocal();

    cin >> n;
    map<int, int> cnt;
    for (int i = 0; i < n; i++) {
        cin >> ai;
        cnt[ai]++;
    }
    vector<int> a(n, 0);
    int i = 0;
    map<int, int> remain;
    for (pair<int, int> p : cnt) {
        while (i < n && p.second > 0) {
            int tmp = min(n, p.second);
            a[i] = tmp;
            i++;
            p.second -= tmp;
        }
        if (p.second > 0)
            remain.insert({p.second, p.first});
    }

    return 0;
}
