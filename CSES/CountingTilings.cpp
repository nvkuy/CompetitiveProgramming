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

    int mod = 1e9 + 7;
    int n, m;
    cin >> n >> m;
    vector<vector<int>> trans(1 << n);
    for (int i = 0; i < (1 << n); i++) {
        for (int j = 0; j < (1 << n); j++) {
            bool iok = true;
            bitset<10> dd(j);
            for (int k = 0; k < n; k++) {
                if (!iok)
                    break;
                if (dd[k] == 1) {
                    if (((1 << k) & i) != 0)
                        iok = false;
                    continue;
                }
                if (((1 << k) & i) != 0) {
                    dd[k] = 1;
                    continue;
                }
                if (k + 1 == n || dd[k + 1] == 1)
                    iok = false;
                else
                    dd[k] = dd[k + 1] = 1;
            }
            if (iok) {
                trans[i].push_back(j);
                // bitset<10> t1(j), t2(i);
                // cout << t1 << "->" << t2 << endl;
            }
        }
    }
    // for (int i : trans[0]) {
    //     bitset<4> t1(0), t2(i);
    //     cout << t2 << "->" << t1 << endl;
    // }
    // return 0;
    vector<int> pf(1 << n, 0), f = pf;
    pf[0] = 1;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < (1 << n); j++) {
            // cout << j << '|' << trans[j].size() << endl;
            for (int k : trans[j]) {
                f[j] += pf[k];
                f[j] %= mod;
            }
            // cout << f[j] << ' ';
        }
        // cout << endl;
        pf = f;
        fill(f.begin(), f.end(), 0);
    }
    cout << pf[0] << endl;

    return 0;
}
