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

map<int, int> fac(int x) {
    map<int, int> res;
    for (int i = 2; i * i <= x; i++) {
        int cnt = 0;
        while (x % i == 0) {
            cnt++;
            x /= i;
        }
        if (cnt > 0)
            res[i] = cnt;
    }
    if (x > 1) res[x]++;
    return res;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while (t--) {

        int n, q;
        cin >> n >> q;

        map<int, int> init = fac(n), cur_fac;
        int init_dn = 1, dn;
        for (auto p : init)
            init_dn *= (p.second + 1);
        dn = init_dn;
        cur_fac = init;

        while (q--) {

            int type;
            cin >> type;
            
            if (type == 2) {
                dn = init_dn;
                cur_fac = init;
                continue;
            }

            int x;
            cin >> x;

            map<int, int> more = fac(x);
            for (auto p : more) {
                dn /= (cur_fac[p.first] + 1);
                cur_fac[p.first] += p.second;
                dn *= (cur_fac[p.first] + 1);
            }

            bool iok = true;
            map<int, int> fac_dn = fac(dn);
            for (auto p : fac_dn) {
                if (p.second > cur_fac[p.first]) {
                    iok = false;
                    break;
                }
            }

            cout << (iok ? "YES" : "NO") << endl;

        }

    }

    return 0;
}
