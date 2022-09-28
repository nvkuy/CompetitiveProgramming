#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

inline void debugLocal() {
    if (!fopen("input.txt", "r"))
        return;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    debugLocal();

    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<int> b(n + 1), ans(n + 1);
        vector<vector<pair<int, int>>> c(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> b[i];
            int r, l = (i / (b[i] + 1)) + 1;
            if (b[i] == 0)
                r = n;
            else
                r = i / b[i];
            c[l].push_back({r, i});
        }
        set<pair<int, int>> avai;
        for (int i = 1; i <= n; i++) {
            for (auto p : c[i])
                avai.insert(p);
            while (true) {
                if (avai.size() > 0) {
                    pair<int, int> tmp = *avai.begin();
                    avai.erase(avai.begin());
                    if (tmp.first >= i) {
                        ans[tmp.second] = i;
                        break;
                    }
                }
            }
        }
        for (int i = 1; i <= n; i++)
            cout << ans[i] << ' ';
        cout << endl;
    }

    return 0;
}
