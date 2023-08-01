#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>
#define endl '\n'

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<pair<int, int>> range(m);
        for (int i = 0; i < m; i++)
            cin >> range[i].first >> range[i].second;
        int q;
        cin >> q;
        vector<int> qr(q);
        for (int i = 0; i < q; i++) cin >> qr[i];
        int ll = 0, rr = q + 1, mm;
        while (ll < rr) {
            mm = (ll + rr) / 2;
            vector<int> ps(n + 1, 0);
            for (int i = 0; i < mm; i++)
                ps[qr[i]]++;
            for (int i = 1; i <= n; i++)
                ps[i] += ps[i - 1];
            bool iok = false;
            for (int i = 0; i < m; i++) 
                iok |= ((ps[range[i].second] - ps[range[i].first - 1]) * 2 > range[i].second - range[i].first + 1);
            if (iok)
                rr = mm;
            else
                ll = mm + 1;
        }
        cout << (rr <= q ? rr : -1) << endl;
    }

    return 0;
}
