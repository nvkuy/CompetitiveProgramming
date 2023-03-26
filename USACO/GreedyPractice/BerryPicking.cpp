#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

inline void debugLocal() {
    if (!fopen("berries.in", "r"))
        return;
    freopen("berries.in", "r", stdin);
    freopen("berries.out", "w", stdout);
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    debugLocal();

    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    int ans = 0;
    for (int max_size_for_bessie = 0; max_size_for_bessie <= 1000; max_size_for_bessie++) {
        multiset<int> rm;
        for (int i = 0; i < n; i++) rm.insert(a[i]);
        for (int i = 0; i < k / 2; i++) {
            auto it = rm.end(); it--;
            int ai = *it;
            rm.erase(it);
            ai -= min(ai, max_size_for_bessie);
            rm.insert(ai);
        }
        int tans = 0;
        for (int i = 0; i < k / 2; i++) {
            auto it = rm.end(); it--;
            int ai = *it;
            rm.erase(it);
            int tmp = min(ai, max_size_for_bessie);
            tans += tmp;
            ai -= tmp;
            rm.insert(ai);
        }
        ans = max(ans, tans);
    }
    cout << ans << endl;

    return 0;
}
