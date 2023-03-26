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

    int x, n, ai;
    cin >> x >> n;
    multiset<int> sticks;
    for (int i = 0 ; i < n; i++) {
        cin >> ai;
        sticks.insert(ai);
    }
    long long ans = 0;
    while (sticks.size() > 1) {
        int s1 = *sticks.begin();
        sticks.erase(sticks.begin());
        int s2 = *sticks.begin();
        sticks.erase(sticks.begin());
        sticks.insert(s1 + s2);
        ans += (s1 + s2);
    }
    cout << ans << endl;

    return 0;
}
