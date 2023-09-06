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

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> pos(n + 1), p(n + 1, -1), q(n + 1, -1);
        set<int> avai;
        for (int i = 1; i <= n; i++) {
            int pi;
            cin >> pi;
            pos[pi] = i;
            avai.insert(i);
        }
        bool iok = true;
        for (int i = 1; i <= n; i++) {
            if (!iok) break;
            for (auto it = avai.upper_bound(i); it != avai.end(); it++) {
                if (*it == pos[i]) continue;
                q[i] = *it;
                p[q[i]] = pos[i];
                avai.erase(it);
                break;
            }
            for (auto it = avai.begin(); it != avai.end() && *it < i; it++) {
                if (q[i] != -1) break;
                if (*it == pos[i]) continue;
                q[i] = *it;
                p[q[i]] = pos[i];
                avai.erase(it);
                break;
            }
            if (q[i] == -1) iok = false;
        }
        if (!iok) {
            cout << "Impossible" << endl;
            continue;
        }
        cout << "Possible" << endl;
        for (int i = 1; i <= n; i++) cout << p[i] << ' ';
        cout << endl;
        for (int i = 1; i <= n; i++) cout << q[i] << ' ';
        cout << endl;
    }

    return 0;
}
