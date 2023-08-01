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
        int n, m, a, b;
        cin >> n >> m >> a >> b;
        vector<int> fc(m);
        for (int i = 0; i < m; i++)
            cin >> fc[i];
        sort(fc.begin(), fc.end());
        int ll = 0, rr = m, free_time = b - 1;
        if (a > b) free_time = n - b;
        while (ll < rr) {
            int mm = (ll + rr + 1) / 2;
            int move = a - 1;
            if (a > b) move = n - a;
            int need_time = mm + move;
            int tmp = 0;
            for (int i = 0; i < mm; i++) tmp = max(tmp, fc[i] - i - move);
            need_time += tmp;
            if (need_time > free_time || abs(a - b) <= mm)
                rr = mm - 1;
            else
                ll = mm;
        }
        cout << ll << endl;
    }

    return 0;
}
