#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

inline void debugMode() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
}

vector<int> c;

bool check(int time, int n, int m) {
    vector<int> tl(n, time);
    for (int i = 0; i < n; i++) {
        int tmp = min(time, c[i]);
        tl[i] -= tmp;
        m -= tmp;
    }
    for (int i = 0; i < n; i++) {
        int tmp = min(m, tl[i] / 2);
        m -= tmp;
    }
    return (m <= 0);
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    debugMode();

    int t, n, m, ai;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        c.assign(n, 0);
        for (int i = 0; i < m; i++) {
            cin >> ai;
            c[ai - 1]++;
        }
        int l = 0, r = 1e9, mm;
        while (l < r) {
            mm = (l + r) / 2LL;
            if (check(mm, n, m))
                r = mm;
            else
                l = mm + 1;
        }
        cout << r << endl;
    }

    return 0;
}
