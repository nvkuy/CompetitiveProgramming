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

    // debugLocal();

    int n, k;
    cin >> n >> k;
    map<int, int> cnt;
    for (int i = 0; i < n; i++) {
        int ai;
        cin >> ai;
        cnt[ai]++;
    }
    long long sum = 0, ans = 0;
    for (auto p : cnt) {
        if (p.second >= k) {
            ans++;
            sum += p.first;
        }
    }
    cout << ans << ' ' << sum << endl;

    return 0;
}
