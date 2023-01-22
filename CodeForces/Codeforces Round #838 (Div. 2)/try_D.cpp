#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int query(int a, int b) {
    cout << "? " << a << ' ' << b << endl;
    cout.flush();
    int rp;
    cin >> rp;
    return rp;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<int> pos;
        pos.push_back(1);
        pos.push_back(2);
        for (int i = 3; i <= n; i++) {
            pos.push_back(i);
            vector<int> tmp_pos;
            int g1 = query(pos[0], pos[1]);
            int g2 = query(pos[0], pos[2]);
            if (g1 == g2) {
                tmp_pos.push_back(pos[1]);
                tmp_pos.push_back(pos[2]);
            } else if (g1 < g2) {
                tmp_pos.push_back(pos[0]);
                tmp_pos.push_back(pos[2]);
            } else {
                tmp_pos.push_back(pos[0]);
                tmp_pos.push_back(pos[1]);
            }
            pos = tmp_pos;
        }
        cout << "! " << pos[0] << ' ' << pos[1] << endl;
        cout.flush();
        int rp;
        cin >> rp;
        if (rp != 1)
            return 0;
    }

    return 0;
}
