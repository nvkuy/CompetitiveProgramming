#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

const int maxN = 1e3;

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m, q, bc = 0, t, a, b;
    cin >> n >> m >> q;
    vector<bitset<maxN>> bs(n, bitset<maxN>(0));
    vector<pair<vector<bitset<maxN>>, int>> days(q + 1);
    bitset<maxN> tmp(0);
    for (int i = 0; i < m; i++)
        tmp[i] = 1;
    days[0] = {bs, bc};
    for (int i = 1; i <= q; i++) {
        cin >> t;
        if (t == 1) {
            cin >> a >> b;
            bc -= bs[a - 1].count();
            bs[a - 1][b - 1] = 1;
            bc += bs[a - 1].count();
        }
        if (t == 2) {
            cin >> a >> b;
            bc -= bs[a - 1].count();
            bs[a - 1][b - 1] = 0;
            bc += bs[a - 1].count();
        }
        if (t == 3) {
            cin >> a;
            bc -= bs[a - 1].count();
            bs[a - 1].flip();
            bs[a - 1] &= tmp;
            bc += bs[a - 1].count();
        }
        if (t == 4) {
            cin >> a;
            bs = days[a].first;
            bc = days[a].second;
        }
        days[i] = {bs, bc};
        cout << bc << endl;
    }

    return 0;
}
