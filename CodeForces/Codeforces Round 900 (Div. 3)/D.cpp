#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>
#define endl '\n'
#define bit_cnt(x) __builtin_popcountll(x)
#define low_bit(x) __builtin_ctzll(x)

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

pair<int, int> opposite(int l, int r, int x) {
    return {min(x, l + r - x), max(x, l + r - x)};
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while (t--) {

        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;

        vector<int> l(k), r(k), ps(n + 1, 0);
        for (int i = 0; i < k; i++) {
            cin >> l[i];
            l[i]--;
        }
        for (int i = 0; i < k; i++) {
            cin >> r[i];
            r[i]--;
        }

        int q;
        cin >> q;
        while (q--) {
            int x;
            cin >> x;
            x--;
            int idx = lower_bound(r.begin(), r.end(), x) - r.begin();
            assert(idx < k);
            auto p = opposite(l[idx], r[idx], x);
            ps[p.first]++;
            ps[p.second + 1]--;
        }

        for (int i = 1; i < n; i++) ps[i] += ps[i - 1];

        int j = 0;
        for (int i = 0; i < n; i++) {
            if (i > r[j]) j++;
            assert(j < k);
            auto p = opposite(l[j], r[j], i);
            if (i == p.second || ps[i] % 2 == 0) continue;
            assert(p.second < n);
            swap(s[p.first], s[p.second]);
        }

        cout << s << endl;

    }

    return 0;
}
