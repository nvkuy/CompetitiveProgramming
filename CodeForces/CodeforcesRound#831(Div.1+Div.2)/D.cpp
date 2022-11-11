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

    int t, n, m, k;
    cin >> t;
    while (t--) {
        cin >> n >> m >> k;
        vector<int> a(k);
        for (int i = 0; i < k; i++)
            cin >> a[i];
        int space = n * m - 2, cur = k, iok = 1;
        set<int> in;
        for (int i = 0; i < k; i++) {
            if (space < 2) {
                iok = 0;
                break;
            }
            if (a[i] == cur) {
                cur--;
                while (in.find(cur) != in.end()) {
                    in.erase(in.find(cur));
                    cur--, space++;
                }
                continue;
            }
            space--;
            in.insert(a[i]);
            if (space < 1)
                iok = 0;
        }
        cout << ((iok == 1) ? "YA" : "TIDAK") << endl;
    }

    return 0;
}
