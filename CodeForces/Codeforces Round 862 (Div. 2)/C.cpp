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

bool ok(long long a, long long b, long long c, long long k) {
    long long tb = b - k;
    long long denta = tb * tb - 4LL * a * c;
    return denta < 0;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    debugLocal();

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<long long> line(n);
        for (int i = 0; i < n; i++) cin >> line[i];
        sort(line.begin(), line.end());
        while (m--) {
            long long a, b, c;
            cin >> a >> b >> c;
            auto it = lower_bound(line.begin(), line.end(), b);
            if (it == line.end()) it--;
            if (ok(a, b, c, *it)) {
                cout << "YES" << endl;
                cout << *it << endl;
            } else {
                if (it != line.begin()) it--;
                if (ok(a, b, c, *it)) {
                    cout << "YES" << endl;
                    cout << *it << endl;
                } else
                    cout << "NO" << endl;
            }
        }
    }

    return 0;
}
