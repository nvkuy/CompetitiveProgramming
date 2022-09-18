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
        vector<int> p;
        for (int i = 1; i <= (1 << n); i++)
            p.push_back(i);
        while (p.size() >= 4) {
            vector<int> np;
            for (int i = 0; i < p.size(); i += 4) {
                pair<int, int> p1 = {p[i], p[i + 1]};
                pair<int, int> p2 = {p[i + 2], p[i + 3]};
                int rp = query(p1.first, p2.first);
                if (rp == 0) {
                    if (query(p1.second, p2.second) == 1)
                        np.push_back(p1.second);
                    else
                        np.push_back(p2.second);
                    continue;
                }
                if (rp == 2)
                    swap(p1, p2);
                rp = query(p1.first, p2.second);
                if (rp == 1)
                    np.push_back(p1.first);
                else
                    np.push_back(p2.second);
            }
            p = np;
        }
        int ans = p[0];
        if (p.size() > 1) {
            if (query(p[0], p[1]) == 2)
                ans = p[1];
        }
        cout << "! " << ans << endl;
        cout.flush();
    }

    return 0;
}
