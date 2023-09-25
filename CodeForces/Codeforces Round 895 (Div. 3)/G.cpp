#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>
#define endl '\n'
#define bit_cnt(x) __builtin_popcountll(x)

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

// idea: create segment of two type: non-1 product and other = > skip atmost 60 non-1 product => skip atmost 120 segment
const long long inf = 1e18;

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<long long> a(n + 1), ps(n + 1, 0), pp(n + 1, 1);
        for (int i = 1; i <= n; i++) cin >> a[i];
        bool isProductBig = false;
        for (int i = 1; i <= n; i++) {
            if (inf / pp[i - 1] < a[i]) {
                isProductBig = true;
                break;
            }
            ps[i] = ps[i - 1] + a[i];
            pp[i] = pp[i - 1] * a[i];
        }
        if (isProductBig) {
            int l = 1, r = n;
            while (l < n && a[l] == 1) l++;
            while (r > l && a[r] == 1) r--;
            cout << l << ' ' << r << endl;
            continue;
        }
        vector<int> l, r, p;
        long long prod = 1, pre = 1;
        for (int i = 1; i <= n; i++) {
            if (a[i] == 1) {
                if (prod != 1) {
                    l.push_back(pre);
                    r.push_back(i - 1);
                    p.push_back(prod);
                    pre = i;
                    prod = 1;
                }
            } else {
                if (prod == 1 && i != 1) {
                    l.push_back(pre);
                    r.push_back(i - 1);
                    p.push_back(prod);
                    pre = i;
                    prod = 1;
                }
            }
            prod *= a[i];
        }
        l.push_back(pre);
        r.push_back(n);
        p.push_back(prod);
        // cout << "@: " << endl;
        long long ans = ps[n], ans_l = 1, ans_r = 1;
        for (int i = 0; i < p.size(); i++) {
            // cout << l[i] << ' ' << r[i] << ' ' << p[i] << endl;
            for (int j = 0; j <= min(121, i); j++) {
                long long tans = 0;
                int ll = l[j], rr = r[i];
                tans += ps[ll - 1];
                tans += ps[n] - ps[rr];
                tans += pp[rr] / pp[ll - 1];
                if (tans > ans) {
                    ans_l = ll, ans_r = rr;
                    ans = tans;
                }
                // cout << ll << ' ' << rr << ' ' << tans << endl;
            }
        }
        cout << ans_l << ' ' << ans_r << endl;
    }

    return 0;
}
