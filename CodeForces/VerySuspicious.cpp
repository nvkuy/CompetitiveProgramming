#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>
#define endl '\n'

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

inline long long cal(long long dash1, long long dash2, long long hoz) {
    long long res = dash1 * dash2 * 2;
    res += (dash1 + dash2) * hoz * 2;
    return res;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    map<long long, int> f;
    for (int i = 1; i <= 1e5; i++) {
        for (int j = i - 1; j <= i + 1; j++) {
            for (int k = i - 1; k <= i + 1; k++) {
                long long tmp = cal(i, j, k);
                if (f[tmp] == 0 || f[tmp] > i + j + k)
                    f[tmp] = i + j + k;
            }
        }
    }
    int pre_min = 1e9;
    for (auto it = f.rbegin(); it != f.rend(); it++) {
        pre_min = min(pre_min, it->second);
        it->second = pre_min;
    }

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        auto it = f.lower_bound(n);
        assert(it != f.end());
        cout << it->second << endl;
    }

    return 0;
}
