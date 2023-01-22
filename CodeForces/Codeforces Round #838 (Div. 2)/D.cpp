#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

map<pair<int, int>, int> f;

int query(int a, int b) {
    if (a > b)
        swap(a, b);
    pair<int, int> p = {a, b};
    if (f.find(p) != f.end())
        return f[p];
    cout << "? " << a << ' ' << b << endl;
    cout.flush();
    int rp;
    cin >> rp;
    f[p] = rp;
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
        f.clear();
        vector<int> pos;
        pos.push_back(1);
        pos.push_back(2);
        for (int i = 3; i <= n; i++) {
            pos.push_back(i);
            int g1 = query(pos[0], pos[1]);
            int g2 = query(pos[1], pos[2]);
            int g3 = query(pos[0], pos[2]);
            if (min(g1, g3) < g2) {
                pos.erase(pos.begin());
                continue;
            }
            if (min(g1, g2) < g3) {
                pos.erase(pos.begin() + 1);
                continue;
            }
            pos.erase(pos.begin() + 2);
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
