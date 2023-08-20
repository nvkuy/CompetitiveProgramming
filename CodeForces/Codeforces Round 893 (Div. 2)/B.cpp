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

int cal(int l, int r, int d, bool icl = false) {
    int res = (r - l - 1) / d;
    if (icl && (r - l) % d == 0) res++;
    return res;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, m, d;
        cin >> n >> m >> d;
        vector<int> a(m + 2);
        for (int i = 1; i <= m; i++) cin >> a[i];
        a[0] = 1, a[m + 1] = n;
        vector<int> ps(m + 2, 1);
        ps[0] = ps[m + 1] = 0;
        for (int i = 1; i <= m; i++) ps[i] += ps[i - 1] + cal(a[i - 1], a[i], d);
        ps[m + 1] = ps[m] + cal(a[m], a[m + 1], d, true);
        if (a[m] == n) ps[m + 1]--;
        // cout << "@ps: ";
        // for (int i = 0; i <= m + 1; i++) cout << ps[i] << ' ';
        // cout << endl;
        int ans = 2e9, cnt = 0;
        for (int i = 1; i <= m; i++) {
            int tans = ps[i - 1] + ps[m + 1] - ps[i + 1] + 1;
            if (a[1] != 1 || i == 1) tans++;
            if (i == m)
                tans += cal(a[i - 1], a[i + 1], d, true) - 1;
            else
                tans += cal(a[i - 1], a[i + 1], d);
            ans = min(ans, tans);
        }
        for (int i = 1; i <= m; i++) {
            int tans = ps[i - 1] + ps[m + 1] - ps[i + 1] + 1;
            if (a[1] != 1 || i == 1) tans++;
            if (i == m)
                tans += cal(a[i - 1], a[i + 1], d, true) - 1;
            else
                tans += cal(a[i - 1], a[i + 1], d);
            if (tans == ans) cnt++;
            // cout << "@i: " << i << ' ' << tans << endl;
        }
        cout << ans << ' ' << cnt << endl;
    }

    return 0;
}
