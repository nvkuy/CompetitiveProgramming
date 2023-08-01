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
        string s, l, r;
        cin >> s;
        int m, n = s.length();
        cin >> m;
        cin >> l >> r;
        vector<set<int>> pos(10);
        for (int i = 0; i < n; i++) pos[s[i] - '0'].insert(i);
        int j = 0;
        string pass;
        for (int i = 0; i < m; i++) {
            char worst = l[i];
            for (char c = l[i]; c <= r[i]; c++) {
                int p1 = n, p2 = n;
                if (pos[c - '0'].size() > 0)
                    p1 = *pos[c - '0'].begin();
                if (pos[worst - '0'].size() > 0)
                    p2 = *pos[worst - '0'].begin();
                if (p1 > p2)
                    worst = c;
            }
            if (pos[worst - '0'].size() == 0) break;
            int np = *pos[worst - '0'].begin();
            while (j <= np) {
                pos[s[j] - '0'].erase(pos[s[j] - '0'].begin());
                j++;
            }
            pass.push_back(worst);
        }
        // cout << "@pass: " << pass << endl;
        cout << (pass.length() < m ? "YES" : "NO") << endl;
    }

    return 0;
}
