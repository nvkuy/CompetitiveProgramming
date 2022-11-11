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

    int t;
    cin >> t;
    while (t--) {
        int n, q, l, r;
        cin >> n >> q;
        vector<int> a(n + 1), gtz(n + 1, 0);
        vector<long long> ps(n + 1, 0), px(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            ps[i] = a[i] + ps[i - 1];
            px[i] = a[i] ^ px[i - 1];
            gtz[i] = (a[i] > 0) + gtz[i - 1];
        }
        while (q--) {
            cin >> l >> r;
            long long fans = ps[r] - ps[l - 1] - (px[r] ^ px[l - 1]);
            vector<int> ls, rs;
            int tmp = lower_bound(gtz.begin(), gtz.end(), gtz[l]) - gtz.begin();
            ls.push_back(max(tmp, l));
            tmp = lower_bound(gtz.begin(), gtz.end(), gtz[r]) - gtz.begin();
            rs.push_back(max(tmp, l));
            while (ls.size() < 32) {
                int p = lower_bound(gtz.begin(), gtz.end(), gtz[ls.back()] + 1) - gtz.begin();
                if (p > r)
                    break;
                ls.push_back(p);
            }
            while (rs.size() < 31) {
                int p = lower_bound(gtz.begin(), gtz.end(), gtz[rs.back()] - 1) - gtz.begin();
                if (p < l)
                    break;
                rs.push_back(p);
            }
            set<int> pos;
            for (int ai : ls)
                pos.insert(ai);
            for (int ai : rs) 
                pos.insert(ai);
            vector<int> pp;
            for (int ai : pos)
                pp.push_back(ai);
            int lans = l, rans = r;
            for (int i = 0; i < pp.size(); i++) {
                for (int j = i; j < pp.size(); j++) {
                    long long tans = ps[pp[j]] - ps[pp[i] - 1] - (px[pp[j]] ^ px[pp[i] - 1]);
                    if ((tans == fans) && (rans - lans > pp[j] - pp[i]))
                        rans = pp[j], lans = pp[i];
                }
            }
            cout << lans << ' ' << rans << endl;
        }
    }

    return 0;
}
