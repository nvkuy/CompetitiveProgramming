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

    int n, ai;
    cin >> n;
    vector<long long> m5(5, 0);
    for (int i = 0; i < n; i++) {
        cin >> ai;
        m5[ai % 5]++;
    }
    long long ans = 0;
    for (int i = 0; i < 5; i++) {
        for (int j = i; j < 5; j++) {
            for (int k = j; k < 5; k++) {
                if ((i + j + k) % 5 > 0)
                    continue;
                if (i == j && j == k) {
                    ans += ((m5[i] * (m5[i] - 1LL) * (m5[i] - 2LL)) / 6LL);
                    continue;
                }
                if (i == j) {
                    ans += ((m5[k] * (m5[i] - 1LL) * m5[i]) / 2LL);
                    continue;
                }
                if (i == k) {
                    ans += ((m5[j] * (m5[i] - 1LL) * m5[i]) / 2LL);
                    continue;
                }
                if (k == j) {
                    ans += ((m5[i] * (m5[j] - 1LL) * m5[j]) / 2LL);
                    continue;
                }
                ans += (m5[i] * m5[j] * m5[k]);
            }
        }
    }
    cout << ans << endl;

    return 0;
}
