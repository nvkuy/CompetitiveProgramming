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

    long long t, n;
    string s;
    cin >> t;
    while (t--) {
        cin >> n;
        cin >> s;
        long long all = (n * (n + 1LL)) / 2LL;
        long long bad = 0;
        for (int i = 0; i < n; i++) {
            vector<int> cnt(10, 0);
            int dn = 0, max_cnt = 0, j = i;
            for (j = i; j < min(i + 100LL, n); j++) {
                if (cnt[s[j] - '0'] == 0)
                    dn++;
                cnt[s[j] - '0']++;
                max_cnt = max(max_cnt, cnt[s[j] - '0']);
                if (max_cnt > dn)
                    bad++;
            }
            bad += (n - j);
        }
        cout << all - bad << endl;
    }

    return 0;
}