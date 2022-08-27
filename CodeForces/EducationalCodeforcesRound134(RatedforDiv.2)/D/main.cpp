#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

const int numBit = 30;

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<int> a(n), b(n);
        vector<bitset<numBit>> bsa, bsb;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            bitset<numBit> tmp(a[i]);
            bsa.push_back(tmp);
        }
        for (int i = 0; i < n; i++) {
            cin >> b[i];
            bitset<numBit> tmp(b[i]);
            bsb.push_back(tmp);
        }
        vector<pair<vector<int>, vector<int>>> c(1);
        vector<int> t1, t2;
        for (int i = 0; i < n; i++)
            t1.push_back(i);
        c[0] = {t1, t1};
        int ans = 0;
        for (int i = numBit - 1; i >= 0; i--) {
            vector<pair<vector<int>, vector<int>>> nc;
            bool iok = true;
            for (int j = 0; j < c.size(); j++) {
                t1 = c[j].first, t2 = c[j].second;
                int cnt1 = 0, cnt2 = 0;
                vector<int> g0a, g1a, g0b, g1b;
                for (int k = 0; k < t1.size(); k++) {
                    if (bsa[t1[k]][i] == 1) {
                        cnt1++;
                        g1a.push_back(t1[k]);
                    } else
                        g0a.push_back(t1[k]);
                    if (bsb[t2[k]][i] == 1) {
                        cnt2++;
                        g1b.push_back(t2[k]);
                    } else
                        g0b.push_back(t2[k]);
                }
                if (cnt1 + cnt2 != t1.size()) {
                    iok = false;
                    break;
                }
                if (g1a.size() > 0)
                    nc.push_back({g1a, g0b});
                if (g0a.size() > 0)
                    nc.push_back({g0a, g1b});
            }
            if (iok) {
                ans += (1 << i);
                c = nc;
            }
        }
        cout << ans << endl;
    }

    return 0;
}
