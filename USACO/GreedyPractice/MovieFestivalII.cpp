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

    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].second >> a[i].first;
    }
    sort(a.begin(), a.end());
    multiset<int> end_watch;
    for (int i = 0; i < k; i++) end_watch.insert(0);
    int ans = 0;
    for (auto p : a) {
        auto it = end_watch.lower_bound(p.second);
        if (it == end_watch.begin() && *it > p.second) continue;
        if (it == end_watch.end() || *it > p.second) it--;
        ans++;
        end_watch.erase(it);
        end_watch.insert(p.first);
    }
    cout << ans << endl;

    return 0;
}
